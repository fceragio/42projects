/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:13:59 by fceragio          #+#    #+#             */
/*   Updated: 2024/05/02 23:13:58 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int		neg;
	size_t	num;

	neg = 0;
	num = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-')
	{
		s++;
		neg = 1;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		num = (num * 10) + (*s - '0');
		s++;
	}
	if ((neg == 0 && num > 2147483647) || (neg != 0 && num > 2147483648))
		return (0);
	if (neg)
		return (-num);
	return (num);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
// 	char *str1 = " \n\t-111111111111111111111111111111";
// 	char *str2 = "asdasdasdasdasd";
// 	char *str3 = "-2147483648";

// 	printf("the first digits of %s are %d", str1, atoi(str1));
// 	printf("\nfor our atoi: %d\n", ft_atoi(str1));
// 	printf("again the first string was %s\n\n", str1);

// 	printf("the first digits of %s are %d", str2, atoi(str2));
// 	printf("\nfor our atoi: %d\n\n", ft_atoi(str2));

// 	printf("the first digits of %s are %d", str3, atoi(str3));
// 	printf("\nfor our atoi: %d\n\n", ft_atoi(str3));
// 	return 0;
// }
