/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 04:41:02 by federico          #+#    #+#             */
/*   Updated: 2024/05/02 23:43:14 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*spare1;
	char	*spare2;

	spare1 = (char *)s1;
	spare2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (spare1[i] != spare2[i])
			return ((unsigned char)spare1[i] - (unsigned char)spare2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char *str1 = "AAAAAAAA";
// 	char *str2 = "AAAAAAAB";
// 	size_t nb = 20;

// 	printf("Comparing the first %zu bytes of:\n%s\n%s\n", nb, str1, str2);

// 	printf("Using memcmp, we get: %d\n", memcmp(str1, str2, nb));
// 	printf("Using ft_memcmp, we get: %d\n\n", ft_memcmp(str1, str2, nb));
// 	return 0;
// }