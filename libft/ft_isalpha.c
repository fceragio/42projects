/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fceragio <fceragio@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:44:04 by fceragio          #+#    #+#             */
/*   Updated: 2024/04/20 14:28:19 by fceragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

//#include <stdio.h>
//#include <ctype.h>
//
//int main()
//{
//	char c1 = 'A';
//	char c2 = '5';
//	char c3 = ' ';
//
//	printf("For the char %c, isalpha returns %d\n", c1, isalpha(c1));
//	printf("For the char %c, isalpha returns %d\n", c2, isalpha(c2));
//	printf("For the char %c, isalpha returns %d\n\n", c3, isalpha(c3));
//
//	printf("For the char %c, FT returns %d\n", c1, ft_isalpha(c1));
//	printf("For the char %c, FT returns %d\n", c2, ft_isalpha(c2));
//	printf("For the char %c, FT returns %d\n", c3, ft_isalpha(c3));
//	return 0;
//}
