/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:05:22 by federico          #+#    #+#             */
/*   Updated: 2025/06/10 22:59:22 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_unset(t_tree *node, t_program *shell)
{
	int	i;

	i = 1;
	while (node->cmd_args[i])
	{
		if (contains_equal(node->cmd_args[i]) == NO)
		{
			try_to_remove(node->cmd_args[i],
				&shell->envs, &shell->local_envs, shell);
		}
		i++;
	}
	shell->exit_status = SUCCESS;
}

void	try_to_remove(char *target, char ***envs,
			char ***local_envs, t_program *shell)
{
	int	i;

	i = find_env(target, *envs);
	if (i != -1)
	{
		remove_env(target, envs, shell);
	}
	i = find_env(target, *local_envs);
	if (i != -1)
	{
		remove_env(target, local_envs, shell);
	}
}
