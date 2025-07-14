/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:37:31 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 15:49:25 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_pipe_exit(pid_t *pid1, pid_t *pid2, t_program *shell);

void	exec_pipe(t_tree *node, t_program *shell)
{
	int		pipe_fds[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipe_fds) == -1)
		manage_critical_error(SYS_ERR, "exec_pipe pipe()", shell);
	exec_pipe_left(node, pipe_fds, &pid1, shell);
	exec_pipe_right(node, pipe_fds, &pid2, shell);
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	exec_pipe_exit(&pid1, &pid2, shell);
}

void	exec_pipe_left(t_tree *node,
			int *pipe_fds, pid_t *pid1, t_program *shell)
{
	*pid1 = fork();
	if (*pid1 == -1)
		manage_critical_error(SYS_ERR, "exec_pipe_left fork()", shell);
	if (*pid1 == 0)
	{
		close(pipe_fds[0]);
		dup2(pipe_fds[1], STDOUT_FILENO);
		close(pipe_fds[1]);
		exec_node(node->left_node, shell);
		exit(shell->exit_status);
	}
}

void	exec_pipe_right(t_tree *node,
			int *pipe_fds, pid_t *pid2, t_program *shell)
{
	*pid2 = fork();
	if (*pid2 == -1)
		manage_critical_error(SYS_ERR, "exec_pipe fork()", shell);
	if (*pid2 == 0)
	{
		close(pipe_fds[1]);
		dup2(pipe_fds[0], STDIN_FILENO);
		close(pipe_fds[0]);
		exec_node(node->right_node, shell);
		exit(shell->exit_status);
	}
}

static void	exec_pipe_exit(pid_t *pid1, pid_t *pid2, t_program *shell)
{
	int	wstatus;

	waitpid(*pid1, &wstatus, 0);
	if (WIFEXITED(wstatus))
	{
		shell->exit_status = WEXITSTATUS(wstatus);
	}
	waitpid(*pid2, &wstatus, 0);
	if (WIFEXITED(wstatus))
	{
		shell->exit_status = WEXITSTATUS(wstatus);
	}
}
