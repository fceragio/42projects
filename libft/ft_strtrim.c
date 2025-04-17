/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 02:48:47 by federico          #+#    #+#             */
/*   Updated: 2024/05/03 00:37:45 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = NULL;
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && i < j && ft_strchr(set, s1[i]))
		i++;
	while (s1[j - 1] && i < j && ft_strchr(set, s1[j - 1]))
		j--;
	result = (char *)malloc(sizeof(char) * (j - i + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, &s1[i], j - i + 1);
	return (result);
}

// #include <stdio.h>

// int main()
// {
// 	char	*str = "abcThis is the string to trim.abc";
// 	char	*trim = "ca";
// 	char	*trimd;

// 	trimd = ft_strtrim(str, trim);
// 	printf("%s		---		%s\n%s\n", str, trim, trimd);
// 	free(trimd);
// 	return 0;
// }