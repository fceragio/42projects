/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:17:22 by fceragio          #+#    #+#             */
/*   Updated: 2024/04/27 02:14:57 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int main()
// {
// 	char c1 = '1';
// 	char c2 = '@';
// 	char c3 = 'h';

// 	printf("For the character %c isascii returns %d\n", c1, isascii(c1));
// 	printf("For the character %c isascii returns %d\n", c2, isascii(c2));
// 	printf("For the character %c isascii returns %d\n\n", c3, isascii(c3));

// 	printf("For the character %c ft_isascii returns %d\n", c1, ft_isascii(c1));
// 	printf("For the character %c ft_isascii returns %d\n", c2, ft_isascii(c2));
// 	printf("Forthecharacter %c ft_isascii returns %d\n\n", c3, ft_isascii(c3));
// 	return 0;
// }
