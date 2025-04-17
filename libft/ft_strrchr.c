/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fceragio <fceragio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 02:48:01 by federico          #+#    #+#             */
/*   Updated: 2024/05/08 19:26:50 by fceragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	size_t			len;
	unsigned char	new_c;

	new_c = (unsigned char)c;
	len = ft_strlen(src);
	while (len > 0)
	{
		if (src[len] == new_c)
			return ((char *)src + len);
		len--;
	}
	if (src[len] == new_c)
		return ((char *)src + len);
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
// 	char	*str = "qwertyuiopasdfghjklzxcvbnnm";
// 	int		c = 'A';

// 	printf("The last occurence of the character\n%c\n", c);
// 	printf("in the string \n%s\n(string adress)\n%p\n", str, str);
// 	printf("can be found at the adress\n%p\n", ft_strrchr(str, c));
// 	printf("%s\n\n", ft_strrchr(str, c));

// 	return 0;
// }