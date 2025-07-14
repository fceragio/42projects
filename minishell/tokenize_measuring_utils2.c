/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_measuring_utils2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:53:05 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 18:13:42 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	redirect_while(char *str, int *i, int *len);
static void	token_while(char *str, int *i, int *len);

int	measure_redirect(char *str, int i)
{
	int	len;

	len = 0;
	if ((str[i + len]) && (str[i + len] == '>'))
	{
		measure_major(str, i, &len);
		return (len);
	}
	else if ((str[i + len]) && (str[i + len] == '<'))
	{
		measure_minor(str, i, &len);
		return (len);
	}
	else if ((str[i + len]) && (str[i + len] == '|'))
		return (1);
	redirect_while(str, &i, &len);
	return (len);
}

static void	redirect_while(char *str, int *i, int *len)
{
	while (str[*i + *len])
	{
		if (str[*i + *len] == ' ' || str[*i + *len] == '\t')
			break ;
		else if (str[*i + *len] == '\"')
		{
			measure_dblquotes(str, *i, len);
		}
		else if (str[*i + *len] == '\'')
		{
			measure_snglquotes(str, *i, len);
		}
		else if (str[*i + *len] == '>'
			|| str[*i + *len] == '<' || str[*i + *len] == '|')
			break ;
		else
			(*len)++;
	}
}

int	measure_token(char *str, int i)
{
	int	len;

	len = 0;
	if ((str[i + len]) && (str[i + len] == '>'))
	{
		measure_major(str, i, &len);
		return (len);
	}
	else if ((str[i + len]) && (str[i + len] == '<'))
	{
		measure_minor(str, i, &len);
		return (len);
	}
	else if ((str[i + len]) && (str[i + len] == '|'))
		return (1);
	token_while(str, &i, &len);
	return (len);
}

static void	token_while(char *str, int *i, int *len)
{
	while (str[*i + *len])
	{
		if (str[*i + *len] == ' '
			|| str[*i + *len] == '\t'
			|| str[*i + *len] == '\n')
			break ;
		else if (str[*i + *len] == '\"')
		{
			measure_dblquotes(str, *i, len);
		}
		else if (str[*i + *len] == '\'')
		{
			measure_snglquotes(str, *i, len);
		}
		else if (str[*i + *len] == '>'
			|| str[*i + *len] == '<' || str[*i + *len] == '|')
			break ;
		else
			(*len)++;
	}
}
