/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:13:05 by federico          #+#    #+#             */
/*   Updated: 2025/04/30 21:36:40 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Point	a;
	Point	b(-12.3f, 56.87f);
	Point	c(b);
	a = b;
	a.get_x();
	a.get_y();
	
	return 0;
}
