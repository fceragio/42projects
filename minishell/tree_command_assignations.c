/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_command_assignations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:15:16 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 15:08:26 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_queue	*set_command_assignations(t_list *token_list, t_program *shell)
{
	t_queue	*result;

	result = NULL;
	if (token_list == NULL)
	{
		return (NULL);
	}
	if (token_list->prev == NULL)
	{
		return (NULL);
	}
	if (token_list->prev->token_id == ASSIGNATION)
	{
		result = create_assignation_queue(token_list->prev, shell);
	}
	return (result);
}

t_queue	*create_assignation_queue(t_list *token_list, t_program *shell)
{
	t_queue	*result;
	t_list	*start;

	result = NULL;
	start = find_first_assignation(token_list);
	while (start && start->token_id == ASSIGNATION)
	{
		queue_append_assignation(&result, start->content, shell);
		start = start->next;
	}
	return (result);
}

t_list	*find_first_assignation(t_list *token_list)
{
	while (token_list->prev)
	{
		if (token_list->prev->token_id != ASSIGNATION)
		{
			break ;
		}
		token_list = token_list->prev;
	}
	return (token_list);
}

void	queue_append_assignation(t_queue **queue,
			char *assignation, t_program *shell)
{
	t_queue	*result;
	t_queue	*last;

	result = malloc(sizeof(t_queue));
	if (result == NULL)
	{
		manage_critical_error(MALLOC_ERR, "queue_append_assignation", shell);
	}
	result->pipe_mode = NULL;
	result->content = str_copy(assignation);
	result->next = NULL;
	if (*queue == NULL)
	{
		*queue = result;
	}
	else
	{
		last = queue_last(*queue);
		last->next = result;
	}
}
