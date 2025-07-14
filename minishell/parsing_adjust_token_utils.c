/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_adjust_token_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:25:16 by federico          #+#    #+#             */
/*   Updated: 2025/06/11 14:03:44 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	list_insert_left(t_list *new_node, t_list **token_list)
{
	new_node->prev = (*token_list);
	new_node->next = (*token_list)->next;
	if ((*token_list)->next)
	{
		(*token_list)->next->prev = new_node;
	}
	(*token_list)->next = new_node;
}

void	list_insert_right(t_list *new_node, t_list **token_list)
{
	new_node->next = (*token_list);
	new_node->prev = (*token_list)->prev;
	if ((*token_list)->prev)
	{
		(*token_list)->prev->next = new_node;
	}
	(*token_list)->prev = new_node;
}
