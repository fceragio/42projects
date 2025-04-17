/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 02:32:31 by federico          #+#    #+#             */
/*   Updated: 2024/05/01 15:28:20 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n % 10 + '0', fd);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main()
// {
// 	int	x = -2147483648;
// 	int fd = open("test.txt", O_RDWR);

// 	if (fd == -1)
// 		printf("can not open the file\n");
// 	else
// 		{
// 			ft_putnbr_fd(x, fd);
// 			close(fd);
// 		}
// 	return 0;
// }