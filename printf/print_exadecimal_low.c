/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exadecimal_low.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:14:03 by federico          #+#    #+#             */
/*   Updated: 2024/05/24 17:46:42 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_exadecimal_low(size_t x)
{
	int		count;
	char	*digits;

	digits = "0123456789abcdef";
	count = 0;
	if (x < 16)
		return (print_char(digits[x]));
	else
	{
		count = (print_exadecimal_low(x / 16));
		return (count + print_exadecimal_low(x % 16));
	}
}
