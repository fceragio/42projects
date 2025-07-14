/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:13:20 by federico          #+#    #+#             */
/*   Updated: 2025/06/14 00:27:14 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	substitute_env(char *new_env, char ***envs)
{
	int	i;

	i = find_env(new_env, *envs);
	if (i == -1)
	{
		return ;
	}
	(*envs)[i] = realloc_string((*envs)[i], new_env);
}

void	really_add_env(char *new_env, char ***envs, t_program *shell)
{
	char	**new_envs;
	int		qnt;
	int		i;

	qnt = count_envp(*envs);
	new_envs = malloc(sizeof(char *) * (qnt + 2));
	if (new_envs == NULL)
	{
		manage_critical_error(MALLOC_ERR, "really_add_env", shell);
	}
	i = 0;
	while (i < qnt)
	{
		new_envs[i] = str_copy((*envs)[i]);
		i++;
	}
	new_envs[i++] = str_copy(new_env);
	new_envs[i] = NULL;
	clean_envs(*envs);
	(*envs) = new_envs;
}

void	add_env(char *new_env, char ***envs, t_program *shell)
{
	if (new_env == NULL)
	{
		return ;
	}
	if (find_env(new_env, *envs) != -1)
	{
		substitute_env(new_env, envs);
	}
	else
	{
		really_add_env(new_env, envs, shell);
	}
}

void	remove_env(char *target, char ***envs, t_program *shell)
{
	char	**new_envs;
	int		qnt;
	int		i;
	int		j;
	int		rmv_index;

	qnt = count_envp(*envs);
	new_envs = malloc(sizeof(char *) * (qnt));
	if (new_envs == NULL)
		manage_critical_error(MALLOC_ERR, "remove_env", shell);
	i = 0;
	j = 0;
	rmv_index = find_env(target, *envs);
	while (i < qnt)
	{
		if (i == rmv_index)
		{
			i++;
			continue ;
		}
		new_envs[j++] = str_copy((*envs)[i++]);
	}
	new_envs[j] = NULL;
	clean_envs(*envs);
	(*envs) = new_envs;
}
