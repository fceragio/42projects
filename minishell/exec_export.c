/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:06:33 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 22:36:26 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_by_name(char *arg, t_queue *assignations, t_program *shell)
{
	int		i;
	char	*to_add;

	if (valid_identifier(arg) == NO)
	{
		write(2, arg, string_len(arg));
		manage_error(CMD_ERR,
			": is not a valid identifier for export", shell);
		return ;
	}
	i = find_env(arg, shell->local_envs);
	if (i != -1)
	{
		add_env(shell->local_envs[i], &shell->envs, shell);
		remove_env(arg, &shell->local_envs, shell);
	}
	to_add = find_env_in_queue(arg, assignations);
	if (to_add != NULL)
	{
		add_env(to_add, &shell->envs, shell);
		free(to_add);
	}
	shell->exit_status = SUCCESS;
}

void	export_expression(char *arg, t_program *shell)
{
	if (valid_identifier(arg) == NO)
	{
		write(2, arg, string_len(arg));
		manage_error(CMD_ERR,
			": is not a valid identifier for export", shell);
		return ;
	}
	if ((find_env(arg, shell->local_envs)) != -1)
	{
		add_env(arg, &shell->envs, shell);
		remove_env(arg, &shell->local_envs, shell);
	}
	else
	{
		add_env(arg, &shell->envs, shell);
	}
	shell->exit_status = SUCCESS;
}

void	exec_export(t_tree *node, t_program *shell)
{
	int	i;

	i = 1;
	if (node->cmd_args[i] == NULL)
	{
		export_raw(shell->envs, shell);
		shell->exit_status = SUCCESS;
	}
	else
	{
		while (node->cmd_args[i])
		{
			if (contains_equal(node->cmd_args[i]))
			{
				export_expression(node->cmd_args[i], shell);
			}
			else
			{
				export_by_name(node->cmd_args[i], node->assignations, shell);
			}
			i++;
		}
	}
}

int	contains_equal(char	*arg)
{
	int	i;

	if (arg == NULL)
	{
		return (NO);
	}
	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
		{
			return (YES);
		}
		i++;
	}
	return (NO);
}
