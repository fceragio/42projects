/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_cleaning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:21:10 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 15:10:01 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tree_free_command(t_tree *node)
{
	int	i;

	free_rdr(node->redirection_queue);
	i = 0;
	while (node->cmd_args[i])
	{
		free(node->cmd_args[i]);
		i++;
	}
	queue_free(&node->assignations);
	free(node->cmd_args);
	free(node->exec_path);
	clean_envs(node->vars);
	clean_envs(node->local_vars);
	free(node->name);
	free(node);
}

void	free_rdr(t_rdr_queue *head)
{
	t_rdr_queue	*temp;

	if (head == NULL)
	{
		return ;
	}
	while (head)
	{
		temp = head->next;
		free(head->name);
		head->name = NULL;
		free(head->rdr_arg);
		head->rdr_arg = NULL;
		free(head);
		head = temp;
	}
}

void	tree_free_pipe(t_tree *node)
{
	tree_free_node(&node->left_node);
	tree_free_node(&node->right_node);
	free(node->name);
	free(node);
}
