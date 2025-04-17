/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:27:39 by federico          #+#    #+#             */
/*   Updated: 2024/06/06 18:35:02 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
void	create_list_till_newl(t_list **list, int fd);
void	add_node(t_list **list, char *buffer);
int		new_line(t_list *list);
t_list	*find_last(t_list *list);
char	*concatenate_lines(t_list	*list);
void	cleanup(t_list **list);
void	freeall_save_leftover(t_list **list, t_list *new_list, char	*leftover);
size_t	chars_to_newl(t_list *list);
void	cat_nodes(t_list *list, char *next_line);

#endif