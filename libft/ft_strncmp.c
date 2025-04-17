/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 02:42:51 by federico          #+#    #+#             */
/*   Updated: 2024/05/03 00:26:21 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (n > (i + 1) && s1[i] && s1[i] == s2[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char	*str1 = "ABCDEFTTT";
// 	char	*str2 = "ABCDEfTTT";
// 	size_t	n = 5;
// 	size_t	n2 = 6;
// 	size_t	n3 = 10;

// 	printf("The difference betwin the %zuth characters of the strings\n", n);
// 	printf("%s\nand\n%s\n", str1, str2);
// 	printf("is %d according to strncmp\n%d according to the ft_strncmp\n\n",
// strncmp(str1, str2, n), ft_strncmp(str1, str2, n));

// 	printf("The difference betwin the %zuth characters of the strings\n", n2);
// 	printf("%s\nand\n%s\n", str1, str2);
// 	printf("is %d according to strncmp\n%d according to the ft_strncmp\n\n",
// strncmp(str1, str2, n2), ft_strncmp(str1, str2, n2));

// 	printf("The difference betwin the %zuth characters of the strings\n", n3);
// 	printf("%s\nand\n%s\n", str1, str2);
// 	printf("is %d according to strncmp\n%d according to the ft_strncmp\n\n",
// strncmp(str1, str2, n3), ft_strncmp(str1, str2, n3));

// 	return (0);
// }
