/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:12:31 by fceragio          #+#    #+#             */
/*   Updated: 2024/04/27 02:13:06 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int main()
// {
// 	char c1 = 'D';
// 	char c2 = '6';
// 	char c3 = '?';

// 	printf("For the character %c isalnum returns %d\n", c1, isalnum(c1));
// 	printf("For the character %c isalnum returns %d\n", c2, isalnum(c2));
// 	printf("For the character %c isalnum returns %d\n\n", c3, isalnum(c3));

// 	printf("For the character %c ft_isalnum returns %d\n", c1, ft_isalnum(c1));
// 	printf("For the character %c ft_isalnum returns %d\n", c2, ft_isalnum(c2));
// 	printf("Forthecharacter %c ft_isalnum returns %d\n\n", c3, ft_isalnum(c3));
// 	return 0;
// }
