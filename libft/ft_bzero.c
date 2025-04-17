/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 04:40:16 by federico          #+#    #+#             */
/*   Updated: 2024/05/02 23:16:21 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*mem;

	mem = (char *)s;
	while (n > 0)
	{
		mem[n - 1] = 0;
		n--;
	}
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	size_t size = 5;
// 	size_t bytesToZero = 3 * sizeof(int);
// 	int ar[] = {1, 2, 3, 4, 5};
// 	int ar2[] = {1, 2, 3, 4, 5};

// 	printf("array: ");
// 	for (int i = 0; i < size; i++)
// 		printf("%d", ar[i]);

// 	bzero(ar, bytesToZero);
// 	printf("\nAfter bzero: ");
// 	for (int i = 0; i < size; i++)
// 		printf("%d", ar[i]);
// 	printf("\n\n");

// 	printf("array: ");
// 	for (int i = 0; i < size; i++)
// 		printf("%d", ar2[i]);

// 	ft_bzero(ar2, bytesToZero);
// 	printf("\nAfter ft_bzero: ");
// 	for (int i = 0; i < size; i++)
// 		printf("%d", ar2[i]);
// 	printf("\n\n");

// 	return 0;
// }