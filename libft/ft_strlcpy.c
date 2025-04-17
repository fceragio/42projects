/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:07:02 by fceragio          #+#    #+#             */
/*   Updated: 2024/05/03 00:20:46 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size_dst)
{
	size_t	i;

	i = 0;
	if (size_dst <= 0)
		return (ft_strlen(src));
	while (i < (size_dst - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size_dst)
		dst[i] = 0;
	while (src[i])
		i++;
	return (i);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	size_t copy;
// 	char dest1[100] = "........................................";
// 	char dest2[100] = "........................................";
// 	char *src = "Abcdefgh,,,,,,,,";

// 	// printf("strlcpy:\n%s +++ %s\n", dest1, src);
// 	// copy = strlcpy(dest1, src, strlen(dest1));
// 	// printf("%s\ncopy size: %zu\n\n", dest1, copy);

// 	printf("ft_strlcpy:\n%s +++ %s\n", dest2, src);
// 	copy = ft_strlcpy(dest2, src, strlen(dest2));
// 	printf("%s\ncopy size: %zu\n", dest2, copy);
// 	return 0;
// }