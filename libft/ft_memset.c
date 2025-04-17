/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 02:29:07 by federico          #+#    #+#             */
/*   Updated: 2024/05/02 23:46:38 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		p[n - 1] = c;
		n--;
	}
	return (s);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char	mem[] = "Abcde";
// 	char	mem2[] = "Abcde";

// 	int		memint[] = {1, 2, 3, 4, 5};
// 	int		memint2[] = {1, 2, 3, 4, 5};

// 	int		set = 9;
// 	size_t	area = 2;

// 	printf("memset: %s --> ", mem);
// 	memset(mem, set, area);
// 	printf("%s\n\n", mem);

// 	printf("ft_memset: %s --> ", mem2);
// 	ft_memset(mem2, set, area);
// 	printf("%s\n\n\n", mem2);

// 	printf("Array before memset:\n");
// 	for (int i = 0; i < 5; i++)
// 		printf("%d\n", memint[i]);
// 	memset(memint, set, area);
// 	printf("Array after memset:\n");
// 	for (int i = 0; i < 5; i++)
// 		printf("%d\n", memint[i]);
// 	printf("\n");

// 	printf("Array before ft_memset:\n");
// 	for (int i = 0; i < 5; i++)
// 		printf("%d\n", memint2[i]);
// 	ft_memset(memint2, set, area);
// 	printf("Array after ft_memset:\n");
// 	for (int i = 0; i < 5; i++)
// 		printf("%d\n", memint2[i]);
// 	printf("\n");

// 	return(0);
// }