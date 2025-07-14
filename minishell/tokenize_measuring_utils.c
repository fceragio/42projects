/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_measuring_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:37:44 by federico          #+#    #+#             */
/*   Updated: 2025/06/06 19:45:35 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	measure_dblquotes(char *str, int i, int *len)
{
	(*len)++;
	while (str[(i + *len)] != '\"')
	{
		(*len)++;
	}
	(*len)++;
	return ;
}

void	measure_snglquotes(char *str, int i, int *len)
{
	(*len)++;
	while (str[(i + *len)] != '\'')
	{
		(*len)++;
	}
	(*len)++;
	return ;
}

void	measure_major(char *str, int i, int *len)
{
	(*len)++;
	if (str[(i + *len)] && str[(i + *len)] == '>')
	{
		(*len)++;
	}
	return ;
}

void	measure_minor(char *str, int i, int *len)
{
	(*len)++;
	if (str[(i + *len)] && str[(i + *len)] == '<')
	{
		(*len)++;
	}
	return ;
}
