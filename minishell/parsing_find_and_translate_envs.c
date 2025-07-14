/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_find_and_translate_envs.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:40:30 by federico          #+#    #+#             */
/*   Updated: 2025/06/14 00:09:04 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	find_and_translate_envs_whileloop(t_list *temp,
				int *i, t_program *shell);
static int	env_expansion_ok(char *str, int i);

void	find_and_translate_envs(t_list **token_list, t_program *shell)
{
	t_list	*temp;
	int		i;

	temp = *token_list;
	while (temp)
	{
		i = 0;
		find_and_translate_envs_whileloop(temp, &i, shell);
		temp = temp->next;
	}
}

static void	find_and_translate_envs_whileloop(t_list *temp,
				int *i, t_program *shell)
{
	while (temp->content[*i])
	{
		if (temp->token_id == REDIRECTION_ARG)
		{
			if (strings_are_equal("<<", temp->prev->content) == YES)
				break ;
		}
		if (temp->content[*i] == '\"')
		{
			translate_envs_inside_dblquotes(temp, i, shell);
		}
		else if (temp->content[*i] == '\'')
		{
			skip_envs_inside_snglquotes(temp->content, i, shell);
		}
		else if (temp->content[*i] == '$'
			&& env_expansion_ok(temp->content, (*i) + 1) == YES)
		{
			translate_env(temp, *i, shell);
			*i = 0;
		}
		else
			(*i)++;
	}
}

void	translate_env(t_list *temp, int i, t_program *shell)
{
	char	env[BUFFER_LIMIT];
	int		j;
	char	*str;

	j = 0;
	str = temp->content;
	i++;
	if (str[i] == '?')
	{
		env[j++] = '?';
		env[j] = '\0';
		token_substitute_with_last_exit_code(env, &temp, i + 1, shell);
		return ;
	}
	while (env_expansion_ok(str, i) == YES)
	{
		env[j] = str[i];
		j++;
		i++;
	}
	env[j] = '\0';
	if (j > 0)
		token_substitute_env(env, &temp, i, shell);
}

static int	env_expansion_ok(char *str, int i)
{
	if (str == NULL || str[i] == '\0')
	{
		return (NO);
	}
	if ((str[i] >= 'a' && str[i] <= 'z')
		|| (str[i] >= 'A' && str[i] <= 'Z')
		|| (str[i] >= '0' && str[i] <= '9')
		|| str[i] == '_' || str[i] == '?')
		return (YES);
	return (NO);
}
