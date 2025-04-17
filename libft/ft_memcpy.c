/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 02:27:03 by federico          #+#    #+#             */
/*   Updated: 2024/05/03 02:46:07 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char buff1[100] = "ABCDEFGHILMNO";
// 	char buff2[100] = "ABCDEFGHILMNO";
// 	char *src = "-------";

// 	printf("before memcpy: %s\n", buff1);
// 	memcpy(buff1, src, 5);
// 	printf("after memcpy: %s\n\n", buff1);

// 	printf("before ft_memcpy: %s\n", buff2);
// 	ft_memcpy(buff2, src, 5);
// 	printf("after ft_memcpy: %s\n\n", buff2);

// 	return 0;
// }