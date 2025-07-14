/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_command_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:13:20 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 15:28:38 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**set_command_args(t_list *token_list, t_program *shell)
{
	int		count;
	char	**result;
	int		i;

	count = count_args(token_list);
	result = malloc(sizeof(char *) * (count + 1 + 1));
	if (result == NULL)
	{
		manage_critical_error(MALLOC_ERR, "set_command_args", shell);
	}
	result[0] = str_copy(token_list->content);
	i = 1;
	while (i < count + 1)
	{
		if (token_list->token_id == ARGUMENT)
		{
			result[i] = str_copy(token_list->content);
			i++;
		}
		token_list = token_list->next;
	}
	result[i] = NULL;
	return (result);
}

int	count_args(t_list *token_list)
{
	int	result;

	result = 0;
	while (token_list && token_list->token_id != PIPE)
	{
		if (token_list->token_id == ARGUMENT)
		{
			result++;
		}
		token_list = token_list->next;
	}
	return (result);
}
