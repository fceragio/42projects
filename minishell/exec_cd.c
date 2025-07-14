/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:01:52 by federico          #+#    #+#             */
/*   Updated: 2025/06/14 00:27:23 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cd(t_tree *node, t_program *shell)
{
	if (node->cmd_args[1] == NULL
		|| (strings_are_equal("~", node->cmd_args[1])
			&& node->cmd_args[2] == NULL))
	{
		cd_home(node, shell);
		return ;
	}
	if (node->cmd_args[2] != NULL)
	{
		manage_error(SYNTAX_ERR, "cd: too many arguments", shell);
		return ;
	}
	if (chdir(node->cmd_args[1]) != 0)
	{
		manage_error(DIR_ERR, "cd : couldn't change directory", shell);
		return ;
	}
}

void	cd_home(t_tree *node, t_program *shell)
{
	char	*home;

	home = custom_get_env("HOME", node->vars);
	if (home == NULL)
	{
		manage_error(CMD_ERR, "couldn't find HOME", shell);
		return ;
	}
	if (chdir(home) != 0)
	{
		manage_error(DIR_ERR, "couldn't move to HOME", shell);
		free(home);
		return ;
	}
	free(home);
	shell->exit_status = SUCCESS;
}
