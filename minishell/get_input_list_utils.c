/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 18:58:28 by federico          #+#    #+#             */
/*   Updated: 2025/06/10 19:03:56 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	list_append(t_list **list, t_list *new_node, char *token)
{
	t_list	*last_node;

	if ((*list) == NULL)
	{
		(*list) = new_node;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		last_node = list_last(*list);
		last_node->next = new_node;
		new_node->prev = last_node;
		new_node->next = NULL;
	}
	new_node->content = token;
	new_node->token_id = NO;
}

t_list	*list_last(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
	{
		list = list->next;
	}
	return (list);
}

void	list_add_nl_after_redirect(t_list **list, t_program *shell)
{
	char	*token;
	t_list	*new_node;

	token = malloc(sizeof(char) * (1 + 1));
	if (token == NULL)
	{
		manage_critical_error(MALLOC_ERR,
			"list_add_nl_after_redirect(token)", shell);
	}
	token[0] = '\n';
	token[1] = '\0';
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		manage_critical_error(MALLOC_ERR,
			"list_add_nl_after_redirect(new_node)", shell);
	}
	new_node->token_len = 1;
	list_append(list, new_node, token);
}
