/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 02:37:01 by federico          #+#    #+#             */
/*   Updated: 2024/05/03 00:05:59 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

// #include <stdio.h>

// void	func(unsigned int n, char *s);

// int main()
// {
// 	char	*str = "123456789";

// 	printf("%s\n\n", str);
// 	ft_striteri(str, func);
// }

// void	func(unsigned int n, char *s)
// {
// 	printf("%c\n", s[n % ft_strlen(s)]);
// }