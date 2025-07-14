/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution_builtin.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:41:06 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 14:45:50 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	command_is_builtin(t_tree *node);
static int	builtin_setups_ok(t_tree *node, int *spare_stdout,
				int *spare_stdin, t_program *shell);

void	exec_command(t_tree *node, t_program *shell)
{
	if (command_is_builtin(node) == YES)
	{
		exec_builtin(node, shell);
	}
	else
	{
		exec_executable(node, shell);
	}
}

void	exec_builtin(t_tree *node, t_program *shell)
{
	int	spare_stdout;
	int	spare_stdin;

	if (builtin_setups_ok(node, &spare_stdout, &spare_stdin, shell) == NO)
		return ;
	if (strings_are_equal("exit", node->name))
		exec_exit(node, shell);
	else if (strings_are_equal("echo", node->name))
		exec_echo(node, shell);
	else if (strings_are_equal("export", node->name))
		exec_export(node, shell);
	else if (strings_are_equal("unset", node->name))
		exec_unset(node, shell);
	else if (strings_are_equal("env", node->name))
		exec_env(node, shell);
	else if (strings_are_equal("cd", node->name))
		exec_cd(node, shell);
	else if (strings_are_equal("pwd", node->name))
		exec_pwd(node, shell);
	restore_streams(spare_stdout, spare_stdin, shell);
}

static int	command_is_builtin(t_tree *node)
{
	if (strings_are_equal("exit", node->name)
		|| strings_are_equal("echo", node->name)
		|| strings_are_equal("export", node->name)
		|| strings_are_equal("unset", node->name)
		|| strings_are_equal("env", node->name)
		|| strings_are_equal("cd", node->name)
		|| strings_are_equal("pwd", node->name))
	{
		return (YES);
	}
	return (NO);
}

static int	builtin_setups_ok(t_tree *node, int *spare_stdout,
				int *spare_stdin, t_program *shell)
{
	if (spare_streams_init(spare_stdout, spare_stdin, shell) == NO)
	{
		return (NO);
	}
	if (resolve_redirections(node, shell) == NO)
	{
		restore_streams(*spare_stdout, *spare_stdin, shell);
		return (NO);
	}
	return (YES);
}
