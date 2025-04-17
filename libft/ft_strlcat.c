/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:03:36 by fceragio          #+#    #+#             */
/*   Updated: 2024/05/03 00:18:13 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size_dst)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] && i < size_dst)
		i++;
	j = 0;
	while (src[j] && (i + j + 1) < size_dst)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size_dst)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

// #include <stdio.h>
// #include <string.h>

// int main ()
// {
// 	size_t size = 100;

// 	char src1[size];
// 	char dst1[size];

// 	char src2[size];
// 	char dst2[size];

// 	for (int i = 0; i < 10; i++)
// 	{
// 		src1[i] = 'A';
// 		src2[i] = 'A';
// 		dst1[i] = 'B';
// 		dst2[i] = 'B';
// 	}

// 	// printf("strlcat\n");
// 	// printf("Concatenating\n%s\nand\n%s\n", dst1, src1);
// 	// size_t newSize = strlcat(dst1, src1, size);
// 	// printf("results in the string\n%s\nof size %zu\n\n", dst1, newSize);

// 	printf("ft_strlcat\n");
// 	printf("Concatenating\n%s\nand\n%s\n", dst2, src2);
// 	size_t newSize2 = ft_strlcat(dst2, src2, size);
// 	printf("results in the string\n%s\nof size %zu\n\n", dst2, newSize2);
// 	return 0;
// }