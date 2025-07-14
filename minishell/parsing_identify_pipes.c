/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_identify_pipes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:33:29 by federico          #+#    #+#             */
/*   Updated: 2025/06/09 01:02:49 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	identify_pipes(t_list **token_list)
{
	t_list	*temp;

	temp = *token_list;
	while (temp)
	{
		if (strings_are_equal("|", temp->content) == YES)
		{
			if (temp->prev == NULL)
			{
				return (NO);
			}
			else if (temp->prev->token_id == PIPE)
			{
				return (NO);
			}
			else
				temp->token_id = PIPE;
		}
		temp = temp->next;
	}
	return (YES);
}
