/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_execution_output.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:21:42 by federico          #+#    #+#             */
/*   Updated: 2025/06/14 00:08:31 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	resolve_redirect_output(t_rdr_queue *temp, t_program *shell)
{
	if (strings_are_equal(">", temp->name))
	{
		if (resolve_write_output(temp, shell) == NO)
		{
			return (NO);
		}
	}
	else if (strings_are_equal(">>", temp->name))
	{
		if (resolve_append_output(temp, shell) == NO)
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

int	resolve_write_output(t_rdr_queue *temp, t_program *shell)
{
	int	fd;

	fd = open(temp->rdr_arg, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
	{
		print_error(temp->rdr_arg);
		manage_error(FILE_ERR, ": couldn't open file", shell);
		return (NO);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(fd);
		manage_critical_error(SYS_ERR, "resolve_write_output dup2()", shell);
	}
	close(fd);
	return (YES);
}

int	resolve_append_output(t_rdr_queue *temp, t_program *shell)
{
	int	fd;

	fd = open(temp->rdr_arg, O_WRONLY | O_CREAT | O_APPEND, 0664);
	if (fd == -1)
	{
		print_error(temp->rdr_arg);
		manage_error(FILE_ERR, ": couldn't open file", shell);
		return (NO);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(fd);
		manage_critical_error(SYS_ERR, "resolve_append_output dup2()", shell);
	}
	close(fd);
	return (YES);
}
