/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:00:48 by federico          #+#    #+#             */
/*   Updated: 2025/06/14 00:27:44 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tree	*create_tree_node(t_list *token_list, t_program *shell)
{
	t_list	*temp;
	t_tree	*result;

	temp = token_list;
	while (temp != NULL)
	{
		if (temp->token_id == PIPE)
		{
			result = tree_create_pipe_node(temp, shell);
			return (result);
		}
		temp = temp->prev;
	}
	temp = token_list;
	while (temp != NULL)
	{
		if (temp->token_id == COMMAND)
		{
			result = tree_create_command_node(temp, shell);
			return (result);
		}
		temp = temp->prev;
	}
	return (NULL);
}

t_tree	*tree_create_pipe_node(t_list *token_list, t_program *shell)
{
	t_tree	*pipe_node;

	pipe_node = malloc(sizeof(t_tree));
	if (pipe_node == NULL)
	{
		manage_critical_error(MALLOC_ERR, "tree_create_pipe_node", shell);
	}
	pipe_node->type = PIPE;
	pipe_node->name = str_copy(token_list->content);
	pipe_node->vars = NULL;
	pipe_node->local_vars = NULL;
	pipe_node->exec_path = NULL;
	pipe_node->cmd_args = NULL;
	pipe_node->left_node = create_tree_node(token_list->prev, shell);
	pipe_node->right_node = tree_create_command_node(
			list_find_next_command(token_list->next), shell);
	pipe_node->assignations = NULL;
	pipe_node->redirection_queue = NULL;
	return (pipe_node);
}

t_list	*list_find_next_command(t_list *token_list)
{
	while (token_list)
	{
		if (token_list->token_id == COMMAND)
		{
			return (token_list);
		}
		token_list = token_list->next;
	}
	return (token_list);
}

t_tree	*tree_create_command_node(t_list *token_list, t_program *shell)
{
	t_tree	*command_node;

	command_node = malloc(sizeof(t_tree));
	if (command_node == NULL)
	{
		manage_critical_error(MALLOC_ERR, "tree_create_command_node", shell);
	}
	command_node->type = COMMAND;
	command_node->name = str_copy(token_list->content);
	command_node->assignations = set_command_assignations(token_list, shell);
	command_node->vars = set_command_vars(shell, command_node->assignations);
	command_node->local_vars = set_command_local_vars(
			shell, command_node->assignations);
	command_node->exec_path = set_command_exec_path(
			command_node->name, command_node->vars, shell);
	command_node->cmd_args = set_command_args(token_list, shell);
	command_node->redirection_queue = set_redirection_queue(token_list, shell);
	command_node->left_node = NULL;
	command_node->right_node = NULL;
	return (command_node);
}
