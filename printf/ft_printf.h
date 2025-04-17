/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:19:55 by federico          #+#    #+#             */
/*   Updated: 2024/05/24 17:48:11 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	converter(char c, va_list ap);
int	ft_printf(const char *format, ...);
int	print_char(int c);
int	print_decimal(long d);
int	print_else(char c);
int	print_exadecimal_low(size_t x);
int	print_exadecimal_upp(size_t x);
int	print_integer(long i);
int	print_percent(void);
int	print_pointer(void *ptr);
int	print_string(char *str);
int	print_unsigned_int(unsigned int u);

#endif