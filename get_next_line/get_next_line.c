/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:28:08 by federico          #+#    #+#             */
/*   Updated: 2024/06/14 15:49:09 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;
	int				check;

	next_line = NULL;
	check = read(fd, next_line, 0);
	if (fd < 0 || BUFFER_SIZE <= 0 || check < 0)
		return (NULL);
	create_list_till_newl(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = concatenate_lines(list);
	cleanup(&list);
	return (next_line);
}

void	create_list_till_newl(t_list **list, int fd)
{
	char	*buffer;
	size_t	chars;

	while (!new_line(*list))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		chars = read(fd, buffer, BUFFER_SIZE);
		if (chars == 0)
		{
			free(buffer);
			return ;
		}
		buffer[chars] = '\0';
		add_node(list, buffer);
	}
}

void	add_node(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = buffer;
	new_node->next = NULL;
}

int	new_line(t_list *list)
{
	size_t	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i] && i < BUFFER_SIZE)
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

t_list	*find_last(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

// #include <stdio.h>
// int main()
// {
// 	char	*next_line;
// 	int		fd;

// 	fd = open("test.txt", O_RDONLY);
// 	while ((next_line = get_next_line(fd)))
// 	{
// 		printf("next_line-> %p\n", next_line);
// 		printf("%s\n", next_line);
// 		free(next_line);
// 	}
// 	printf("next_line-> %p\n", next_line);
// 	close(fd);
// 	return 0;
// }