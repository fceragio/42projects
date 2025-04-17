/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:13:27 by federico          #+#    #+#             */
/*   Updated: 2024/05/24 18:29:19 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
	{
		count = write(1, "(nil)", 5);
		return (count);
	}
	count = write(1, "0x", 2);
	return (count + print_exadecimal_low((size_t)ptr));
}
