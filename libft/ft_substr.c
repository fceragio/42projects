/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 02:49:18 by federico          #+#    #+#             */
/*   Updated: 2024/05/10 03:36:40 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	result = (char *)malloc(len * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < start && s[i])
		i++;
	j = 0;
	while (j < len && s[i])
	{
		result[j] = s[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}

// #include <stdio.h>

// int main()
// {
// 	char			*str = "This-is-the-default-string.";
// 	unsigned int	first = 5;
// 	size_t			max = 3;
// 	char 			*sub;

// 	sub = ft_substr(str, first, max);
// 	printf("%s\nThe substring starting on the byte %u\n", str, first);
// 	printf("of maximum length %zu bytes is\n%s\n", max, sub);
// 	free(sub);

// 	return 0;
// }