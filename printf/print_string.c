/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:15:52 by federico          #+#    #+#             */
/*   Updated: 2024/05/24 18:24:02 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		count = (write(1, "(null)", 6));
		return (count);
	}
	else
	{
		while (*str)
		{
			write(1, str, 1);
			str++;
			count++;
		}
		return (count);
	}
}
