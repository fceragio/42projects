/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:14:27 by federico          #+#    #+#             */
/*   Updated: 2024/05/24 15:02:28 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_int(unsigned int u)
{
	int		count;
	char	*digits;

	digits = "0123456789";
	count = 0;
	if (u < 10)
		return (print_char(digits[u]));
	else
	{
		count = print_unsigned_int(u / 10);
		return (count + print_unsigned_int(u % 10));
	}
}
