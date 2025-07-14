/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:13:43 by federico          #+#    #+#             */
/*   Updated: 2025/04/30 09:11:31 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractional_bits = 8;

Fixed::Fixed() : raw_bits(0){
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int value){
	std::cout << "Int constructor called" << std::endl;
	int	fractional_pow = 1;
	for(int i = 0; i < fractional_bits; i++){
		fractional_pow *= 2;
	}
	raw_bits = value * fractional_pow;
}
Fixed::Fixed(const float value){
	std::cout << "Float constructor called" << std::endl;
	int	fractional_pow = 1;
	for(int i = 0; i < fractional_bits; i++){
		fractional_pow *= 2;
	}
	raw_bits = roundf(value * fractional_pow);
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other){
	if (this != &other){
		std::cout << "Copy assigment operator called" << std::endl;
		this->raw_bits = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}


int		Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return raw_bits;
}
float	Fixed::toFloat(void) const{
	int	fractional_pow = 1;
	for(int i = 0; i < fractional_bits; i++){
		fractional_pow *= 2;
	}
	return ((float)raw_bits / (float)fractional_pow);
}
int		Fixed::toInt(void) const{
	int	fractional_pow = 1;
	for(int i = 0; i < fractional_bits; i++){
		fractional_pow *= 2;
	}
	return (raw_bits / fractional_pow);
}

void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	raw_bits = raw;
}

std::ostream& operator<<(std::ostream& stream, const Fixed &fixed){
	stream << fixed.toFloat();
	return stream;
}
