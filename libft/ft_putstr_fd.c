/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 02:32:52 by federico          #+#    #+#             */
/*   Updated: 2024/04/27 02:32:53 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

// #include <stdio.h>
// #include <fcntl.h>

// int main()
// {
// 	char *c = "String to put in the file.\nDid it work?";
// 	int fd = open("test.txt", O_RDWR);

// 	if (fd == -1)
// 		printf("can not open file\n");
// 	else
// 	{
// 		ft_putstr_fd(c, fd);
// 		close(fd);
// 	}
// 	return 0;
// }