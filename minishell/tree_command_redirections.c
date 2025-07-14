/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_command_redirections.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:19:41 by federico          #+#    #+#             */
/*   Updated: 2025/06/14 00:27:41 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_rdr_queue	*set_redirection_queue(t_list *token_list, t_program *shell)
{
	t_rdr_queue	*result;
	t_list		*temp;

	temp = token_list;
	result = NULL;
	while (temp && temp->token_id != PIPE)
	{
		if (temp->token_id == REDIRECT_OUTPUT
			|| temp->token_id == REDIRECT_INPUT || temp->token_id == HEREDOC)
		{
			append_rdr_queue(&result, temp, shell);
		}
		temp = temp->next;
	}
	return (result);
}

void	append_rdr_queue(t_rdr_queue **head,
			t_list *token_list, t_program *shell)
{
	t_rdr_queue	*result;
	t_rdr_queue	*last;

	result = malloc(sizeof(t_rdr_queue));
	if (result == NULL)
	{
		manage_critical_error(MALLOC_ERR, "append_rdr_queue", shell);
	}
	result->type = token_list->token_id;
	result->name = str_copy(token_list->content);
	result->rdr_arg = str_copy(token_list->next->content);
	result->next = NULL;
	last = last_rdr(*head);
	if (last == NULL)
	{
		*head = result;
		return ;
	}
	last->next = result;
}

t_rdr_queue	*last_rdr(t_rdr_queue *head)
{
	if (head == NULL)
	{
		return (NULL);
	}
	while (head->next)
	{
		head = head->next;
	}
	return (head);
}
