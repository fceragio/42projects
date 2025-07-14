/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:13:05 by federico          #+#    #+#             */
/*   Updated: 2025/04/30 09:09:35 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}

// int main(){
// 	Fixed	a(42.42f);
// 	Fixed	b(58.7f);
// 	Fixed	c(42.42f);
// 	const Fixed d(58.7f);
// 	const Fixed e(42.42f);
// 	bool	boolean;

// 	boolean = a > b;
// 	std::cout << a << '>' << b << "="  << boolean << '\n';
// 	boolean = a < b;
// 	std::cout << a << '<' << b << "=" << boolean << '\n';
// 	boolean = a >= b;
// 	std::cout << a << ">=" << b << "=" << boolean << '\n';
// 	boolean = a <= b;
// 	std::cout << a << "<=" << b << "=" << boolean << '\n';
// 	boolean = a == b;
// 	std::cout << a << "==" << b << "=" << boolean << '\n';
// 	boolean = a != b;
// 	std::cout << a << "!=" << b << "=" << boolean << '\n';
	
// 	boolean = a > c;
// 	std::cout << a << ">" << c << "=" << boolean << '\n';
// 	boolean = a < c;
// 	std::cout << a << '<' << c << "=" << boolean << '\n';
// 	boolean = a >= c;
// 	std::cout << a << ">=" << c << "=" << boolean << '\n';
// 	boolean = a <= c;
// 	std::cout << a << "<=" << c << "=" << boolean << '\n';
// 	boolean = a == c;
// 	std::cout << a << "==" << c << "=" << boolean << '\n';
// 	boolean = a != c;
// 	std::cout << a << "!=" << c << "=" << boolean << "\n\n";

// 	std::cout << "min(" << a << ", " << b << ") -> " << Fixed::min(a, b) << '\n';
// 	std::cout << "min(" << e << ", " << d << ") -> " << Fixed::min(e, d) << '\n';
// 	std::cout << "max(" << a << ", " << b << ") -> " << Fixed::max(a, b) << '\n';
// 	std::cout << "max(" << e << ", " << d << ") -> " << Fixed::max(e, d) << "\n\n";

// 	std::cout << a << " + " << b << " = " << a + b << '\n';
// 	std::cout << e << " + " << d << " = " << e + d << '\n';
// 	std::cout << a << " - " << b << " = " << a - b << '\n';
// 	std::cout << e << " - " << d << " = " << e - d << '\n';
// 	std::cout << a << " * " << b << " = " << a * b << '\n';
// 	std::cout << e << " * " << d << " = " << e * d << '\n';
// 	std::cout << a << " / " << b << " = " << a / b << '\n';
// 	std::cout << e << " / " << d << " = " << e / d << "\n\n";
	
// 	std::cout <<  "a = " << a << "\nz = ++a  -->  ";
// 	Fixed z = ++a;
// 	std::cout << "z = " << z << "      a = " << a << "\n\n";

// 	std::cout <<  "a = " << a << "\ny = a++  -->  ";
// 	Fixed y = a++;
// 	std::cout << "y = " << y << "      a = " << a << "\n\n";
	
// 	std::cout <<  "a = " << a << "\nx = --a  -->  ";
// 	Fixed x = --a;
// 	std::cout << "x = " << x << "      a = " << a << "\n\n";
	
// 	std::cout <<  "a = " << a << "\nw = a--  -->  ";
// 	Fixed w = a--;
// 	std::cout << "w = " << w << "      a = " << a << "\n\n";
	
// 	return 0;
// }
