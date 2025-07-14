/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_remove_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:42:52 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 15:25:20 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_quotes_loop(t_list *temp,
				int *i, int *new_len, char *clean_buffer);

void	translate_envs_inside_dblquotes(t_list *temp, int *i, t_program *shell)
{
	char	*str;

	str = temp->content;
	(*i)++;
	while (str[*i] != '\"')
	{
		if (str[*i] == '$' && str[*i + 1] != '\0'
			&& str[*i + 1] != ' ' && str[*i + 1] != '\t'
			&& str[*i + 1] != '\n' && str[*i + 1] != '\"')
		{
			translate_env(temp, *i, shell);
			str = temp->content;
		}
		else
			(*i)++;
	}
	(*i)++;
}

void	skip_envs_inside_snglquotes(char *str, int *i, t_program *shell)
{
	(void)shell;
	(*i)++;
	while (str[*i] != '\'')
	{
		(*i)++;
	}
	(*i)++;
}

void	remove_quotes(t_list **token_list, t_program *shell)
{
	t_list	*temp;
	char	clean_buffer[BUFFER_LIMIT];
	int		i;
	int		new_len;

	temp = *token_list;
	while (temp)
	{
		i = 0;
		new_len = 0;
		remove_quotes_loop(temp, &i, &new_len, clean_buffer);
		if (new_len < temp->token_len)
		{
			realloc_token_content(temp, clean_buffer, new_len, shell);
		}
		reset_buffer(clean_buffer, new_len);
		temp = temp->next;
	}
}

static void	remove_quotes_loop(t_list *temp,
				int *i, int *new_len, char *clean_buffer)
{
	while (*i < temp->token_len)
	{
		if (temp->content[*i] == '\"')
			skip_dblquotes(i, new_len, temp->content, clean_buffer);
		else if (temp->content[*i] == '\'')
			skip_snglquotes(i, new_len, temp->content, clean_buffer);
		else
		{
			clean_buffer[*new_len] = temp->content[*i];
			(*i)++;
			(*new_len)++;
		}
	}
}
