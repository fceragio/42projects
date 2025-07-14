/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export_raw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:10:23 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 15:41:13 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_raw(char **envs, t_program *shell)
{
	t_queue	*sorted_envs;

	if (envs == NULL)
	{
		return ;
	}
	sorted_envs = sort_envs(envs, shell);
	print_all_export_format(sorted_envs);
	queue_free(&sorted_envs);
}

t_queue	*sort_envs(char **envs, t_program *shell)
{
	t_queue	*result;
	int		i;

	result = NULL;
	if (envs == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (envs[i])
	{
		append_in_order(envs[i], &result, shell);
		i++;
	}
	return (result);
}

void	print_all_export_format(t_queue	*sorted_envs)
{
	t_queue	*temp;

	if (sorted_envs == NULL)
	{
		return ;
	}
	temp = sorted_envs;
	while (temp)
	{
		printf("declare -x ");
		print_env_identifier(temp->content);
		printf("\"");
		print_env_value(temp->content);
		printf("\"");
		printf("\n");
		temp = temp->next;
	}
}

void	print_env_identifier(char *env)
{
	int	i;

	if (env == NULL)
	{
		return ;
	}
	i = 0;
	while (env[i])
	{
		printf("%c", env[i]);
		if (env[i] == '=')
		{
			break ;
		}
		i++;
	}
}

void	print_env_value(char *env)
{
	int	i;

	if (env == NULL)
	{
		return ;
	}
	i = 0;
	while (env[i] && env[i] != '=')
	{
		i++;
	}
	if (env[i] == '=')
	{
		i++;
	}
	while (env[i])
	{
		printf("%c", env[i]);
		i++;
	}
}
