/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 02:28:24 by federico          #+#    #+#             */
/*   Updated: 2024/05/03 02:50:35 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	bytes;

	if (!dest && !src)
		return (NULL);
	bytes = 0;
	if (dest > src)
	{
		bytes = n;
		while (bytes > 0)
		{
			bytes--;
			((char *)dest)[bytes] = ((char *)src)[bytes];
		}
	}
	else
	{
		while (bytes < n)
		{
			((char *)dest)[bytes] = ((char *)src)[bytes];
			bytes++;
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char buff1[100] = "ABCDEFGHILMNO";
// 	char buff2[100] = "ABCDEFGHILMNO";
// 	char *src1;
// 	char *src2;

// 	src1 = buff1;
// 	src2 = buff2;

// 	printf("before memmove: %s\n", buff1);
// 	memmove(buff1 + 3, src1, 5);
// 	printf("after memmove: %s\n\n", buff1);

// 	printf("before ft_memmove: %s\n", buff2);
// 	ft_memmove(buff2 + 3, src2, 5);
// 	printf("after ft_memmove: %s\n\n", buff2);
// 	return 0;
// }