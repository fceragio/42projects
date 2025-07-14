/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:14:02 by federico          #+#    #+#             */
/*   Updated: 2025/04/29 01:25:58 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed{
private:
	int 				raw_bits;
	static const int	fractional_bits;

public:
	Fixed();

	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);

	~Fixed();

	int	getRawBits(void) const;
	
	void	setRawBits(int const raw);
};

#endif