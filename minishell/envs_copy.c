/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:08:13 by federico          #+#    #+#             */
/*   Updated: 2025/06/14 00:27:16 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_envp(char **envp, t_program *shell)
{
	char	**result;
	int		i;

	if (envp == NULL)
		return (NULL);
	i = count_envp(envp);
	if (i == 0)
		return (NULL);
	result = malloc(sizeof(char *) * (i + 1));
	if (result == NULL)
	{
		manage_critical_error(MALLOC_ERR, "copy_envp", shell);
	}
	alloc_and_copy_sngl_envs(result, envp, shell);
	return (result);
}

void	alloc_and_copy_sngl_envs(char **result, char **envp, t_program *shell)
{
	int		i;
	int		len;

	i = 0;
	while (envp[i])
	{
		len = string_len(envp[i]);
		result[i] = malloc(sizeof(char) * (len + 1));
		if (result[i] == NULL)
		{
			clean_envs(result);
			manage_critical_error(MALLOC_ERR,
				"alloc_and_copy_sngl_envs", shell);
		}
		copy_sngl_env(result[i], envp[i]);
		i++;
	}
	result[i] = NULL;
}

void	copy_sngl_env(char *result, char *envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		result[i] = envp[i];
		i++;
	}
	result[i] = '\0';
}

int	count_envp(char **envp)
{
	int	i;

	i = 0;
	if (envp == NULL)
	{
		return (0);
	}
	while (envp[i])
	{
		i++;
	}
	return (i);
}
