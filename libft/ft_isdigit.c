/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fceragio <fceragio@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:07:16 by fceragio          #+#    #+#             */
/*   Updated: 2024/04/20 14:28:49 by fceragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

//#include <stdio.h>
//#include <ctype.h>
//
//int main()
//{
//	char c1 = '5';
//	char c2 = '0';
//	char c3 = 'H';
//
//	printf("For the character %c isdigit returns %d\n", c1, isdigit(c1));
//	printf("For the character %c isdigit returns %d\n", c2, isdigit(c2));
//	printf("For the character %c isdigit returns %d\n\n", c3, isdigit(c3));
//
//	printf("For the character %c ft_isdigit returns %d\n", c1, ft_isdigit(c1));
//	printf("For the character %c ft_isdigit returns %d\n", c2, ft_isdigit(c2));
//	printf("For the character %c ft_isdigit returns %d\n", c3, ft_isdigit(c3));
//}
