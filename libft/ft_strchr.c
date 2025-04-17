/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fceragio <fceragio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:25:16 by fceragio          #+#    #+#             */
/*   Updated: 2024/05/08 19:11:08 by fceragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	new_c;

	new_c = (unsigned char) c;
	while (*str != new_c && *str)
	{
		str++;
	}
	if (*str == new_c)
		return ((char *)str);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char	*s = "aaaaaaaa aaaaaaa aa";
// 	char	c = ' ';

// 	printf("strch:\n");
// 	printf("The adress of the string %s is %p\n", s, s);
// 	printf("Adress first occurrence of %c is %p\n\n", c , strchr(s, c));

// 	printf("ft_strch:\n");
// 	printf("The adress of the string %s is %p\n", s, s);
// 	printf("Adress first occurrence of %c is %p\n\n", c , ft_strchr(s, c));

// 	return (0);
// }