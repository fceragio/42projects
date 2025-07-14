/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:36:10 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 14:32:26 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_clean(t_program *shell)
{
	clean_envs(shell->envs);
	clean_envs(shell->local_envs);
	queue_free(&shell->input_queue);
	list_reset(&shell->token_list);
	tree_free_node(&shell->execution_tree);
	rl_clear_history();
}

void	clean_envs(char **result)
{
	int	j;

	j = 0;
	if (result == NULL)
		return ;
	while (result[j])
	{
		free(result[j++]);
	}
	free(result);
}

void	queue_free(t_queue **queue)
{
	t_queue	*temp;

	if (queue == NULL || *queue == NULL)
	{
		return ;
	}
	if ((*queue)->pipe_mode)
	{
		free((*queue)->pipe_mode);
		(*queue)->pipe_mode = NULL;
	}
	while (*queue)
	{
		temp = (*queue)->next;
		free((*queue)->content);
		(*queue)->content = NULL;
		free(*queue);
		*queue = temp;
	}
	return ;
}

void	list_reset(t_list **list)
{
	t_list	*temp;

	if (list == NULL)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		free((*list)->content);
		(*list)->content = NULL;
		free((*list));
		(*list) = temp;
	}
}

void	tree_free_node(t_tree **node)
{
	if (*node == NULL)
	{
		return ;
	}
	if ((*node)->type == COMMAND)
	{
		tree_free_command(*node);
		*node = NULL;
	}
	else
	{
		tree_free_pipe(*node);
		*node = NULL;
	}
}
