/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:12:15 by federico          #+#    #+#             */
/*   Updated: 2024/05/24 15:04:50 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	converter(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += print_char(va_arg(ap, int));
	else if (c == 's')
		count += print_string(va_arg(ap, char *));
	else if (c == 'p')
		count += print_pointer(va_arg(ap, void *));
	else if (c == 'd')
		count += print_decimal((long)va_arg(ap, int));
	else if (c == 'i')
		count += print_integer((long)va_arg(ap, int));
	else if (c == 'u')
		count += print_unsigned_int(va_arg(ap, unsigned int));
	else if (c == 'x')
		count += print_exadecimal_low(va_arg(ap, unsigned int));
	else if (c == 'X')
		count += print_exadecimal_upp(va_arg(ap, unsigned int));
	else if (c == '%')
		count += print_percent();
	else
		count += print_else(c);
	return (count);
}
