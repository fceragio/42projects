/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fceragio <fceragio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 04:40:53 by federico          #+#    #+#             */
/*   Updated: 2024/05/08 19:05:46 by fceragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*spare;
	size_t			i;

	spare = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)spare[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char *str = "abcdefghilmnopqrstuvz";
// 	char c = 't';
// 	size_t range = 20;

// 	printf("The adress of the string %s is:\n%p\n\n", str, str);
// 	printf("If we scan it with memchr for %zu bytes,\n", range);
// 	printf("the adress of the first \"%c\" results being:\n%p\n",c,
// memchr(str, c, range));
// 	printf("If we scan it with ft_memchr for %zu bytes,\n", range);
// 	printf("the adress of the first \"%c\" results being:\n%p\n", c,
// ft_memchr(str, c, range));

// 	return 0;
// }