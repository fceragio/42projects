/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_adjust_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:48:30 by federico          #+#    #+#             */
/*   Updated: 2025/06/14 00:27:28 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	adjust_token(t_list **token_list, t_program *shell)
{
	t_list	*temp;

	temp = *token_list;
	while (temp)
	{
		if (no_command_in_block(temp))
		{
			temp = list_insertion_point(temp);
			list_insert_fake_command(&temp, shell);
		}
		temp = list_surpass_next_pipe(temp);
	}
}

void	list_insert_fake_command(t_list **token_list, t_program *shell)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		manage_critical_error(MALLOC_ERR, "list_insert_fake_command", shell);
	}
	new_node->token_id = COMMAND;
	new_node->token_len = 0;
	new_node->content = NULL;
	if ((*token_list)->token_id == ASSIGNATION)
	{
		list_insert_left(new_node, token_list);
	}
	else
	{
		list_insert_right(new_node, token_list);
	}
}

t_list	*list_surpass_next_pipe(t_list *temp)
{
	if (temp == NULL)
	{
		return (NULL);
	}
	while (temp)
	{
		if (temp->token_id == PIPE)
		{
			return (temp->next);
		}
		temp = temp->next;
	}
	return (NULL);
}

int	no_command_in_block(t_list *temp)
{
	if (temp == NULL)
	{
		return (YES);
	}
	while (temp && temp->token_id != PIPE)
	{
		if (temp->token_id == COMMAND)
		{
			return (NO);
		}
		temp = temp->next;
	}
	return (YES);
}

t_list	*list_insertion_point(t_list *temp)
{
	if (temp == NULL)
	{
		return (NULL);
	}
	if (temp->token_id == ASSIGNATION)
	{
		while (temp->next)
		{
			if (temp->next->token_id != ASSIGNATION)
			{
				return (temp);
			}
			temp = temp->next;
		}
	}
	return (temp);
}
