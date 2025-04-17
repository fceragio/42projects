/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fceragio <fceragio@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:16:20 by fceragio          #+#    #+#             */
/*   Updated: 2024/04/20 16:41:13 by fceragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

//#include <stdio.h>
//#include <ctype.h>
//
//int main()
//{
//	char c1 = 'a';
//	char c2 = 'Z';
//	int c3 = 300;
//
//	printf("for the character %c tolower returns %c\n", c1, tolower(c1));
//	printf("for the character %c tolower returns %c\n", c2, tolower(c2));
//	printf("for the character %d tolower returns %d\n\n", c3, tolower(c3));
//
//	printf("for the character %c ft_tolower returns %c\n", c1, ft_tolower(c1));
//	printf("for the character %c ft_tolower returns %c\n", c2, ft_tolower(c2));
//	printf("for the character %d ft_tolower returns %d\n", c3, ft_tolower(c3));
//	return 0;
//}
