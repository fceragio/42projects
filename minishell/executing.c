/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:14:44 by federico          #+#    #+#             */
/*   Updated: 2025/06/14 00:09:23 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_tree(t_tree *root, t_program *shell)
{
	if (tree_only_assignations(root))
	{
		change_shell_envs(root, shell);
	}
	else
	{
		exec_node(root, shell);
	}
	tree_free_node(&shell->execution_tree);
}

void	change_shell_envs(t_tree *tree, t_program *shell)
{
	t_queue	*temp;

	temp = tree->assignations;
	while (temp)
	{
		if (find_env(temp->content, shell->envs) == -1)
		{
			add_env(temp->content, &shell->local_envs, shell);
		}
		else
		{
			add_env(temp->content, &shell->envs, shell);
		}
		temp = temp->next;
	}
}

int	tree_only_assignations(t_tree *tree)
{
	if (tree == NULL)
	{
		return (NO);
	}
	if (tree->type == PIPE)
	{
		return (NO);
	}
	if (tree->type == COMMAND)
	{
		if (tree->name)
		{
			return (NO);
		}
	}
	return (YES);
}

void	exec_node(t_tree *node, t_program *shell)
{
	if (node == NULL)
	{
		return ;
	}
	else if (node->type == PIPE)
	{
		exec_pipe(node, shell);
	}
	else if (node->type == COMMAND)
	{
		exec_command(node, shell);
	}
}
