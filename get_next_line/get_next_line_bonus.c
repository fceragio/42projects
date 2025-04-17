/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:50:52 by federico          #+#    #+#             */
/*   Updated: 2024/06/14 16:12:32 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*list[1024];
	char			*next_line;
	int				check;

	next_line = NULL;
	check = read(fd, next_line, 0);
	if (fd > 1023 || fd < 0 || BUFFER_SIZE <= 0 || check < 0)
		return (NULL);
	create_list_till_newl(list, fd);
	if (list[fd] == NULL)
		return (NULL);
	next_line = concatenate_lines(list[fd]);
	cleanup(&list[fd]);
	return (next_line);
}

void	create_list_till_newl(t_list **list, int fd)
{
	char	*buffer;
	size_t	chars;

	while (!new_line(list[fd]))
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
		add_node(list, buffer, fd);
	}
}

void	add_node(t_list **list, char *buffer, int fd)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last(list[fd]);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		list[fd] = new_node;
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
// 	char	*next_line1, *next_line2, *next_line3;
// 	int		fd1, fd2, fd3;

// 	fd1 = open("test.txt", O_RDONLY);
// 	fd2 = open("test1.txt", O_RDONLY);
// 	fd3 = open("test2.txt", O_RDONLY);

// 	while (1)
// 	{
// 		next_line1 = get_next_line(fd1);
// 		printf("next_line1 adress->\t%p\n", next_line1);
// 		next_line2 = get_next_line(fd2);
// 		printf("next_line2 adress->\t%p\n", next_line2);
// 		next_line3 = get_next_line(fd3);
// 		printf("next_line2 adress->\t%p\n", next_line3);
// 		printf("\n");

// 		if (next_line1)
// 		{
// 			printf("fd1 = %d\n%s\n\n", fd1, next_line1);
// 			free(next_line1);
// 		}
// 		if (next_line2)
// 		{
// 			printf("fd2 = %d\n%s\n\n", fd2, next_line2);
// 			free(next_line2);
// 		}
// 		if (next_line3)
// 		{
// 			printf("fd3 = %d\n%s\n\n", fd3, next_line3);
// 			free(next_line3);
// 		}
// 		if (!next_line1 && !next_line2 && !next_line3)
// 			break;
// 	}

// 	close(fd1);
// 	close(fd2);
// 	close(fd3);

// 	return 0;
// }