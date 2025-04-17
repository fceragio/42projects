/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 02:30:50 by federico          #+#    #+#             */
/*   Updated: 2024/04/27 02:30:51 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main()
// {
// 	char c = 'b';
// 	int fd = open("test.txt", O_RDWR);

// 	if (fd == -1)
// 		printf("can not open file\n");
// 	else
// 	{
// 		ft_putchar_fd(c, fd);
// 		close(fd);
// 	}
// 	return 0;
// }