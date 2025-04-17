/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:15:32 by federico          #+#    #+#             */
/*   Updated: 2024/05/24 15:00:15 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_decimal(long d)
{
	int		count;
	char	*digits;

	digits = "0123456789";
	count = 0;
	if (d < 0)
	{
		write(1, "-", 1);
		return (1 + print_decimal(-d));
	}
	else if (d < 10)
		return (print_char(digits[d]));
	else
	{
		count = print_decimal(d / 10);
		return (count + print_decimal(d % 10));
	}
}
