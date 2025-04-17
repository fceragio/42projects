/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:45:56 by fceragio          #+#    #+#             */
/*   Updated: 2024/05/02 23:58:31 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = 0;
	while (s[len])
		len++;
	dup = malloc(len * sizeof(char) + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char *string = "AsdAsdAsd";
// 	char *dup;

// 	dup = strdup(string);
// 	printf("strdup:\n%s\n", string);
// 	printf("%s\n\n", dup);
// 	free(dup);

// 	dup = ft_strdup(string);
// 	printf("ft_strdup:\n%s\n", string);
// 	printf("%s\n\n", dup);
// 	free(dup);

// 	return (0);
// }
