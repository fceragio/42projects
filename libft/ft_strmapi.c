/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 02:42:19 by federico          #+#    #+#             */
/*   Updated: 2024/05/03 00:25:14 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			size;
	char			*result;

	size = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * size + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// #include <stdio.h>

// static char	func(unsigned int plus, char c);

// int main()
// {
// 	char	*str = "This is the string.";
// 	char	*new;
// 	char	c = 'T';
// 	unsigned int n = 0;

// 	new = ft_strmapi(str, (func));
// 	printf("%c -->  func  --> %c\n", c, func(n, c));
// 	printf("%s\n|\nft_strmapi\n|\n%s\n\n", str, new);
// 	free(new);

// 	return 0;
// }

// static char	func(unsigned int plus, char c)
// {
// 	char	new;

// 	new = (plus + c) % '~';
// 	return (new);
// }