/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:52:04 by federico          #+#    #+#             */
/*   Updated: 2024/06/13 19:00:20 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*concatenate_lines(t_list	*list)
{
	size_t	total_len;
	char	*next_line;

	if (list == NULL)
		return (NULL);
	total_len = chars_to_newl(list);
	if (total_len <= 0)
		return (NULL);
	next_line = malloc(sizeof(char) * (total_len + 1));
	if (next_line == NULL)
		return (NULL);
	cat_nodes(list, next_line);
	return (next_line);
}

void	cat_nodes(t_list *list, char *next_line)
{
	size_t	i;
	size_t	j;

	if (list == NULL)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				next_line[j++] = '\n';
				next_line[j] = '\0';
				return ;
			}
			next_line[j++] = list->content[i++];
		}
		list = list->next;
	}
	next_line[j] = '\0';
}

size_t	chars_to_newl(t_list *list)
{
	size_t	total_len;
	size_t	i;

	if (list == NULL)
		return (0);
	total_len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
				return (++total_len);
			i++;
			total_len++;
		}
		list = list->next;
	}
	return (total_len);
}

void	cleanup(t_list **list)
{
	t_list	*last_node;
	t_list	*new_node;
	char	*leftover;
	int		i;
	int		j;

	leftover = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	new_node = malloc(sizeof(t_list));
	if (leftover == NULL || new_node == NULL)
		return ;
	last_node = find_last(*list);
	i = 0;
	j = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] && last_node->content[++i])
		leftover[j++] = last_node->content[i];
	leftover[j] = '\0';
	new_node->content = leftover;
	new_node->next = NULL;
	freeall_save_leftover(list, new_node, leftover);
}

void	freeall_save_leftover(t_list **list, t_list *new_list, char	*leftover)
{
	t_list	*spare;

	if (*list == NULL)
		return ;
	while (*list)
	{
		spare = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = spare;
	}
	*list = NULL;
	if (new_list->content[0])
		*list = new_list;
	else
	{
		free(leftover);
		free(new_list);
	}
}
