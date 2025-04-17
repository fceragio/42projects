/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 02:31:12 by federico          #+#    #+#             */
/*   Updated: 2024/04/27 02:31:56 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main()
// {
// 	char	*c = "After this string there should be an extra new line.\n";
// 	int		fd = open("test.txt", O_RDWR);

// 	if (fd == -1)
// 		printf("can not open the file\n");
// 	else
// 	{
// 		ft_putendl_fd(c, fd);
// 		ft_putendl_fd("Did it work?", fd);
// 		close(fd);
// 	}
// 	return 0;
// }