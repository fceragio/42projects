/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 02:45:40 by federico          #+#    #+#             */
/*   Updated: 2024/05/01 17:21:13 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && (i + j) < len)
			{
				j++;
				if (little[j] == '\0')
					return ((char *)big + i);
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
// 	char *big = "AaaaaaaaaBBBBaaaaaaaa";
// 	char *small = "Ba";
// 	size_t range = 15;

// 	printf("The memoryAdress of the string %s is\n%p\n\n", big, big);
// 	printf("The memoryAdress of the string %s in the string %s", small, big);
// 	printf(",searched%zubytes\n%p\n", range, ft_strnstr(big, small, range));
// 	printf("%s\n\n", ft_strnstr(big, small, range));

// 	return 0;
// }