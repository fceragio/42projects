/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 04:40:24 by federico          #+#    #+#             */
/*   Updated: 2024/05/10 03:09:15 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t qnt, size_t type)
{
	void	*cal;
	size_t	tot;

	if (!type || !qnt)
	{
		qnt = 1;
		type = 1;
	}
	if (type != 0 && qnt > (SIZE_MAX / type))
		return (NULL);
	tot = qnt * type;
	cal = (void *)malloc(tot);
	if (cal == NULL)
		return (NULL);
	ft_bzero(cal, tot);
	return (cal);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	int size = 20;

//  	void * d1 = ft_calloc(size, sizeof(int));
//  	void * d2 = calloc(size, sizeof(int));
//  	printf("memcmp -> %d\n", memcmp(d1, d2, size * sizeof(int)));
// 	return 0;
// }