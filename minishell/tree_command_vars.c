/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_command_vars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:13:59 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 14:30:24 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**set_command_local_vars(t_program *shell,
			t_queue *command_assignations)
{
	t_queue	*temp;
	char	**result;

	result = copy_envp(shell->local_envs, shell);
	temp = command_assignations;
	while (temp)
	{
		if (find_env(temp->content, shell->envs) != -1)
		{
			add_env(temp->content, &result, shell);
		}
		temp = temp->next;
	}
	return (result);
}

char	**set_command_vars(t_program *shell,
			t_queue *command_assignations)
{
	t_queue	*temp;
	char	**result;

	result = copy_envp(shell->envs, shell);
	temp = command_assignations;
	while (temp)
	{
		add_env(temp->content, &result, shell);
		temp = temp->next;
	}
	return (result);
}
