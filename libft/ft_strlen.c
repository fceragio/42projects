/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:41:06 by fceragio          #+#    #+#             */
/*   Updated: 2024/05/03 00:21:27 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char *s1 = "asdasfgrgthfbt";
// 	char *s2 = "1";
// 	char *s3 = "";

// 	printf("length of %s according to strlen is %zu\n", s1, strlen(s1));
// 	printf("length of %s according to strlen is %zu\n", s2, strlen(s2));
// 	printf("length of %s according to strlen is %zu\n\n", s3, strlen(s3));

// 	printf("length of %s according to ft_strlen is %zu\n", s1, ft_strlen(s1));
// 	printf("length of %s according to ft_strlen is %zu\n", s2, ft_strlen(s2));
// 	printf("length of %s according to ft_strlen is %zu\n\n", s3, ft_strlen(s3));

// 	return 0;
// }
