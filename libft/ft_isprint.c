/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:26:40 by fceragio          #+#    #+#             */
/*   Updated: 2024/05/01 03:08:02 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int main()
// {
// 	char c1 = 'A';
// 	char c2 = '\t';
// 	char c3 = '\0';

// 	printf("For the character %c isprint returns %d\n", c1, isprint(c1));
// 	printf("For the character %c isprint returns %d\n", c2, isprint(c2));
// 	printf("For the character %c isprint returns %d\n\n", c3, isprint(c3));

// 	printf("For the character %c ft_isprint returns %d\n", c1, ft_isprint(c1));
// 	printf("For the character %c ft_isprint returns %d\n", c2, ft_isprint(c2));
// 	printf("Forthecharacter %c ft_isprint returns %d\n\n", c3, ft_isprint(c3));
// 	return 0;
// }
