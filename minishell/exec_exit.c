/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:51:04 by federico          #+#    #+#             */
/*   Updated: 2025/06/14 00:10:16 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_exit(t_tree *node, t_program *shell)
{
	printf("exit\n");
	if (node->cmd_args[1] == NULL)
	{
		shell_clean(shell);
		exit(SUCCESS);
	}
	if (node->cmd_args[2] != NULL)
	{
		manage_error(SYNTAX_ERR, "exit: too many arguments", shell);
		return ;
	}
	exit_with_status(node->cmd_args[1], shell);
}

void	exit_with_status(char *status, t_program *shell)
{
	unsigned char	n;

	if (non_numeric(status) == YES)
	{
		manage_critical_error(CMD_ERR,
			"exit: required numerical argument", shell);
	}
	n = convert_status(status);
	set_shell_exit_status(n, shell);
	exit(n);
}

unsigned char	convert_status(char *status)
{
	int				i;
	unsigned char	result;

	result = 0;
	if (status == NULL)
	{
		return (0);
	}
	i = 0;
	while (status[i])
	{
		result = (result * 10) + (status[i] - '0');
		i++;
	}
	return (result);
}

int	non_numeric(char *str)
{
	int	i;

	if (str == NULL)
	{
		return (YES);
	}
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (YES);
		}
		i++;
	}
	return (NO);
}

void	set_shell_exit_status(int status, t_program *shell)
{
	shell->exit_status = status;
}
