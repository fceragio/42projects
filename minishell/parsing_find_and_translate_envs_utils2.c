/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_find_and_translate_envs_utils2.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 00:46:23 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 15:57:55 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env_value(char *name, t_program *shell)
{
	int		i;
	int		j;

	i = find_env(name, shell->envs);
	j = find_env(name, shell->local_envs);
	if (i != -1)
	{
		return (string_minus_beginning(shell->envs[i],
				string_len(name) + 1));
	}
	else if (j != -1)
	{
		return (string_minus_beginning(shell->local_envs[j],
				string_len(name) + 1));
	}
	return (NULL);
}

void	reset_buffer(char	*clean_buffer, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		clean_buffer[j] = '\0';
		j++;
	}
}

void	skip_dblquotes(int *i, int *new_len,
			char *old_content, char *clean_buffer)
{
	(*i)++;
	while (old_content[*i] != '\"')
	{
		clean_buffer[*new_len] = old_content[*i];
		(*new_len)++;
		(*i)++;
	}
	(*i)++;
}

void	skip_snglquotes(int *i, int *new_len,
			char *old_content, char *clean_buffer)
{
	(*i)++;
	while (old_content[*i] != '\'')
	{
		clean_buffer[*new_len] = old_content[*i];
		(*new_len)++;
		(*i)++;
	}
	(*i)++;
}
