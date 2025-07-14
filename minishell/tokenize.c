/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:39:16 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 19:25:28 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*tokenize(char *input, t_program *shell)
{
	t_list			*token_list;
	t_token_info	info;

	token_list = NULL;
	info.i = 0;
	while (input[info.i])
	{
		trim_forespace(input, &info.i, token_list);
		if (list_check_redirect(token_list) == NO)
			info.len = measure_token(input, info.i);
		else
			info.len = measure_redirect(input, info.i);
		if (info.len == 0)
			break ;
		list_add(&token_list, input, &info, shell);
	}
	if (list_check_redirect(token_list) == YES)
		list_add_nl_after_redirect(&token_list, shell);
	free(input);
	return (token_list);
}

void	trim_forespace(char	*str, int *i, t_list *list)
{
	if (list_check_redirect(list) == YES)
	{
		while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
		{
			(*i)++;
		}
	}
	else
	{
		while (str[*i] && (str[*i] == ' '
				|| str[*i] == '\t' || str[*i] == '\n'))
		{
			(*i)++;
		}
	}
}
