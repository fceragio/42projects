/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_identify_commands.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:44:53 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 13:59:11 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	first_if(t_list **temp, int *new_block);

void	identify_commands(t_list **token_list)
{
	t_list	*temp;
	int		new_block;

	temp = *token_list;
	new_block = YES;
	while (temp)
	{
		first_if(&temp, &new_block);
		if (temp)
		{
			if (temp->token_id == PIPE
				|| temp->token_id == REDIRECT_INPUT
				|| temp->token_id == REDIRECT_OUTPUT)
			{
				new_block = YES;
			}
			temp = temp->next;
		}
	}
}

static void	first_if(t_list **temp, int *new_block)
{
	if ((*temp)->token_id == NO && *new_block == YES)
	{
		(*temp)->token_id = COMMAND;
		*new_block = NO;
		while (*temp && *new_block == NO)
		{
			if ((*temp)->token_id == NO)
			{
				(*temp)->token_id = ARGUMENT;
			}
			else if ((*temp)->token_id == PIPE)
			{
				*new_block = YES;
				break ;
			}
			*temp = (*temp)->next;
		}
	}
}
