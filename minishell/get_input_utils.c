/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:01:38 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 16:02:31 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_next_target(t_queue **queue, int *i, char target, int *flag)
{
	(*i)++;
	while (*queue)
	{
		while ((*queue)->content[*i])
		{
			if ((*queue)->content[*i] == target)
			{
				*flag = YES;
				(*i)++;
				return ;
			}
			else
			{
				(*i)++;
			}
		}
		*queue = (*queue)->next;
		*i = 0;
	}
	return ;
}

void	wait_valid_char(t_queue **queue, int *i, int *flag)
{
	(*i)++;
	*(*queue)->pipe_mode = YES;
	while (*queue)
	{
		while ((*queue)->content[*i])
		{
			if ((*queue)->content[*i] != ' '
				&& (*queue)->content[*i] != '\t'
				&& (*queue)->content[*i] != '\n')
			{
				*(*queue)->pipe_mode = NO;
				*flag = YES;
				return ;
			}
			else
			{
				(*i)++;
			}
		}
		*queue = (*queue)->next;
		*i = 0;
	}
	return ;
}
