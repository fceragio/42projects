/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:11:40 by federico          #+#    #+#             */
/*   Updated: 2024/05/24 18:30:16 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			count += converter(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}

// #include <stdio.h>

// int main()
// {
// 	char	c = '-';
// 	char	*s = NULL;
// 	int		d = 0;
// 	int		i = 1000;
// 	int		*p;
// 	int		u = 1000;
// 	int		x = 1000;
// 	int 	X = 1000;
// 	int		wrtnBytes1;
// 	int		wrtnBytes2;

// 	p = NULL;

// 	printf("--Printf--\n");
// 	wrtnBytes1 = printf("%c\n", c);
// 	printf("The number of bytes written is %d\n", wrtnBytes1);
// 	wrtnBytes1 = printf("%s\n", s);
// 	printf("The number of bytes written is %d\n", wrtnBytes1);
// 	wrtnBytes1 = printf("%p\n", p);
// 	printf("The number of bytes written is %d\n", wrtnBytes1);
// 	wrtnBytes1 = printf("%d\n", d);
// 	printf("The number of bytes written is %d\n", wrtnBytes1);
// 	wrtnBytes1 = printf("%i\n", i);
// 	printf("The number of bytes written is %d\n", wrtnBytes1);
// 	wrtnBytes1 = printf("%u\n", u);
// 	printf("The number of bytes written is %d\n", wrtnBytes1);
// 	wrtnBytes1 = printf("%x\n", x);
// 	printf("The number of bytes written is %d\n", wrtnBytes1);
// 	wrtnBytes1 = printf("%X\n", X);
// 	printf("The number of bytes written is %d\n\n", wrtnBytes1);

// 	ft_printf("--ft_printf--\n");
// 	wrtnBytes2 = ft_printf("%c\n", c);
// 	ft_printf("The number of bytes written is %d\n", wrtnBytes2);
// 	wrtnBytes2 = ft_printf("%s\n", s);
// 	ft_printf("The number of bytes written is %d\n", wrtnBytes2);
// 	wrtnBytes2 = ft_printf("%p\n", p);
// 	ft_printf("The number of bytes written is %d\n", wrtnBytes2);
// 	wrtnBytes2 = ft_printf("%d\n", d);
// 	ft_printf("The number of bytes written is %d\n", wrtnBytes2);
// 	wrtnBytes2 = ft_printf("%i\n", i);
// 	ft_printf("The number of bytes written is %d\n", wrtnBytes2);
// 	wrtnBytes2 = ft_printf("%u\n", u);
// 	ft_printf("The number of bytes written is %d\n", wrtnBytes2);
// 	wrtnBytes2 = ft_printf("%x\n", x);
// 	ft_printf("The number of bytes written is %d\n", wrtnBytes2);
// 	wrtnBytes2 = ft_printf("%X\n", X);
// 	ft_printf("The number of bytes written is %d\n\n", wrtnBytes2);

// 	return 0;
// }