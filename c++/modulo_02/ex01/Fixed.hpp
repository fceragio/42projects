/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:14:02 by federico          #+#    #+#             */
/*   Updated: 2025/04/30 09:10:49 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed{
private:
	int 				raw_bits;
	static const int	fractional_bits;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);

	Fixed(const Fixed& other);

	Fixed& operator=(const Fixed& other);

	~Fixed();

	int		getRawBits(void) const;
	float	toFloat(void) const;
	int		toInt(void) const;

	void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& stream, const Fixed &fixed);

#endif