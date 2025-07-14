/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution_executable.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:48:52 by federico          #+#    #+#             */
/*   Updated: 2025/06/14 00:22:10 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	executable_setups_ok(t_tree *node, int *spare_stdout,
				int *spare_stdin, t_program *shell);
static void	executable_exit(t_program *shell);

void	exec_executable(t_tree *node, t_program *shell)
{
	int		spare_stdout;
	int		spare_stdin;
	pid_t	pid;

	if (executable_setups_ok(node, &spare_stdout, &spare_stdin, shell) == NO)
	{
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		restore_streams(spare_stdout, spare_stdin, shell);
		manage_critical_error(SYS_ERR, "exec_executable fork()", shell);
	}
	if (pid == 0)
	{
		execve(node->exec_path, node->cmd_args, shell->envs);
		restore_streams(spare_stdout, spare_stdin, shell);
		manage_critical_error(SYS_ERR,
			"execve child process killed manually", shell);
	}
	executable_exit(shell);
	restore_streams(spare_stdout, spare_stdin, shell);
}

static int	executable_setups_ok(t_tree *node,
		int *spare_stdout, int *spare_stdin, t_program *shell)
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
	if (node->exec_path == NULL)
	{
		write(2, node->name, string_len(node->name));
		manage_error(CMD_ERR, ": command not found", shell);
		restore_streams(*spare_stdout, *spare_stdin, shell);
		return (NO);
	}
	if (access(node->exec_path, X_OK) == -1)
	{
		write(2, node->name, string_len(node->name));
		manage_error(FILE_ERR, ": permission denied", shell);
		restore_streams(*spare_stdout, *spare_stdin, shell);
		return (NO);
	}
	return (YES);
}

static void	executable_exit(t_program *shell)
{
	int	wstatus;

	wait(&wstatus);
	if (WIFEXITED(wstatus))
	{
		shell->exit_status = WEXITSTATUS(wstatus);
	}
}
