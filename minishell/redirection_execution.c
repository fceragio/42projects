/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_execution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:48:23 by federico          #+#    #+#             */
/*   Updated: 2025/06/14 00:27:36 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	spare_streams_init(int *spare_stdout, int *spare_stdin, t_program *shell)
{
	*spare_stdout = dup(STDOUT_FILENO);
	if (*spare_stdout == -1)
	{
		manage_critical_error(SYS_ERR, "spare_streams_init dup", shell);
	}
	*spare_stdin = dup(STDIN_FILENO);
	if (*spare_stdin == -1)
	{
		manage_critical_error(SYS_ERR, "spare_streams_init dup", shell);
	}
	return (YES);
}

int	restore_streams(int spare_stdout, int spare_stdin, t_program *shell)
{
	if (dup2(spare_stdout, STDOUT_FILENO) == -1)
	{
		close(spare_stdin);
		close(spare_stdout);
		manage_critical_error(SYS_ERR, "restore_streams dup2", shell);
	}
	close(spare_stdout);
	if (dup2(spare_stdin, STDIN_FILENO) == -1)
	{
		close(spare_stdin);
		manage_critical_error(SYS_ERR, "restore_streams dup2", shell);
	}
	close(spare_stdin);
	return (YES);
}

int	resolve_redirections(t_tree *node, t_program *shell)
{
	t_rdr_queue	*temp;

	temp = node->redirection_queue;
	while (temp)
	{
		if (temp->type == REDIRECT_OUTPUT)
		{
			if (resolve_redirect_output(temp, shell) == NO)
			{
				return (NO);
			}
		}
		else if (temp->type == REDIRECT_INPUT)
		{
			if (resolve_redirect_input(temp, shell) == NO)
			{
				return (NO);
			}
		}
		temp = temp->next;
	}
	return (YES);
}
