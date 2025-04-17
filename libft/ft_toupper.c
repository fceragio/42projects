/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fceragio <fceragio@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:09:33 by fceragio          #+#    #+#             */
/*   Updated: 2024/04/20 16:47:52 by fceragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

//#include <stdio.h>
//#include <ctype.h>
//
//int main()
//{
//	char c1 = 'b';
//	char c2 = 'Z';
//	int  c3 = 300;
//
//	printf("For the character %c toupper returns %c\n", c1, toupper(c1));
//	printf("For the character %c toupper returns %c\n", c2, toupper(c2));
//	printf("For the character %d toupper returns %d\n\n", c3, toupper(c3));
//
//	printf("For the character %c ft_toupper returns %c\n", c1, ft_toupper(c1));
//	printf("For the character %c ft_toupper returns %c\n", c2, ft_toupper(c2));
//	printf("For the character %d ft_toupper returns %d\n", c3, ft_toupper(c3));
//	return 0;
//}
