/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_execution_input.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:20:35 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 13:43:29 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	resolve_redirect_input(t_rdr_queue *temp, t_program *shell)
{
	if (strings_are_equal("<", temp->name))
	{
		if (resolve_read_input(temp, shell) == NO)
		{
			return (NO);
		}
	}
	else if (strings_are_equal("<<", temp->name))
	{
		if (resolve_heredoc(temp, shell) == NO)
		{
			return (NO);
		}
	}
	else
	{
		return (NO);
	}
	return (YES);
}

int	resolve_read_input(t_rdr_queue *temp, t_program *shell)
{
	int	fd;

	fd = open(temp->rdr_arg, O_RDONLY);
	if (fd == -1)
	{
		print_error(temp->rdr_arg);
		manage_error(FILE_ERR, ": couldn't open file", shell);
		return (NO);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(fd);
		manage_critical_error(SYS_ERR, "resolve_read_input dup2()", shell);
	}
	close(fd);
	return (YES);
}

int	resolve_heredoc(t_rdr_queue *temp, t_program *shell)
{
	int	pipe_fds[2];

	if (pipe(pipe_fds) == -1)
	{
		manage_critical_error(SYS_ERR, "resolve_heredoc pipe()", shell);
	}
	write(pipe_fds[1], temp->rdr_arg, string_len(temp->rdr_arg));
	close(pipe_fds[1]);
	if (dup2(pipe_fds[0], STDIN_FILENO) == -1)
	{
		manage_critical_error(SYS_ERR, "resolve_heredoc dup2()", shell);
	}
	close(pipe_fds[0]);
	return (YES);
}
