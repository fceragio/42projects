/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:47:33 by fceragio          #+#    #+#             */
/*   Updated: 2024/05/03 00:27:30 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len = 1;
		n = -n;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	num;
	size_t		len;

	num = n;
	len = num_len(n);
	str = (char *)malloc(len * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num)
	{
		str[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}

// #include <stdio.h>

// int main(void)
// {
// 	int		num1 = 0;
// 	int		num2 = 2147483647;
// 	int		num3 = -2147483648;
// 	char	*buff;

// 	buff = ft_itoa(num1);
// 	if (buff == NULL)
// 		free (buff);
// 	else
// 	{
// 		printf("%d --> %s\n\n", num1, buff);
// 		free(buff);
// 	}

// 	buff = ft_itoa(num2);
// 	if (buff == NULL)
// 		free (buff);
// 	else
// 	{
// 	printf("%d --> %s\n\n", num2, buff);
// 	free(buff);
// 	}

// 	buff = ft_itoa(num3);
// 	if (buff == NULL)
// 		free (buff);
// 	else
// 	{
// 	printf("%d --> %s\n\n", num3, buff);
// 	free(buff);
// 	}

// 	return 0;
// }