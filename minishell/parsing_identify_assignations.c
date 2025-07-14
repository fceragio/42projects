/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_identify_assignations.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:39:32 by federico          #+#    #+#             */
/*   Updated: 2025/06/10 19:12:06 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	temp_while_loop(t_list *temp, int *new_block, int *i);
static void	temp_content_while_loop(t_list *temp, int *new_block, int *i);

void	identify_assignations(t_list **token_list)
{
	t_list	*temp;
	int		new_block;
	int		i;

	temp = *token_list;
	new_block = YES;
	temp_while_loop(temp, &new_block, &i);
}

static void	temp_while_loop(t_list *temp, int *new_block, int *i)
{
	while (temp)
	{
		*i = 0;
		if (temp->token_id == PIPE)
			*new_block = YES;
		else if (*new_block == YES && temp->token_id == NO)
		{
			if (temp->content[0] != '_'
				&& (temp->content[0] < 'A' || temp->content[0] > 'Z')
				&& (temp->content[0] < 'a' || temp->content[0] > 'z'))
			{
				*new_block = NO;
			}
			else
			{
				(*i)++;
				temp_content_while_loop(temp, new_block, i);
			}
		}
		else
			*new_block = NO;
		temp = temp->next;
	}
}

static void	temp_content_while_loop(t_list *temp, int *new_block, int *i)
{
	while (temp->content[*i] && temp->content[*i] != '=')
	{
		if (temp->content[*i] != '_'
			&& (temp->content[*i] < 'a' || temp->content[*i] > 'z')
			&& (temp->content[*i] < 'A' || temp->content[*i] > 'Z')
			&& (temp->content[*i] < '0' || temp->content[*i] > '9'))
		{
			*new_block = NO;
			return ;
		}
		(*i)++;
	}
	if (temp->content[*i] == '=')
	{
		temp->token_id = ASSIGNATION;
	}
	else
	{
		*new_block = NO;
	}
}
