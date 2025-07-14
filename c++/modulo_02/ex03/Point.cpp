/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:03:23 by federico          #+#    #+#             */
/*   Updated: 2025/04/30 21:49:29 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0) , y(0){
	std::cout << "default point constructor-> x = " << x << "  y = " << y << '\n';
}
Point::Point(const float x, const float y) : x(x), y(y){
	std::cout << "point constructor-> x = " << this->x << "  y = " << this->y << '\n';
}
Point::Point(const Point& other) : x(other.x), y(other.y){
	std::cout << "copy point constructor-> x = " << x << "  y = " << y << '\n';
}

Point& Point::operator=(const Point& other){
	std::cout << "operator \'=\' does nothing because x and y are costants\n";
	return *this;
}

Point::~Point(){
	std::cout << "point destructor" << std::endl;
}

const Fixed& Point::get_x()const{
	std::cout << "getting x " << this->x << '\n';
	return this->x;
}
const Fixed& Point::get_y()const{
	std::cout << "getting y " << this->y << '\n';
	return this->y;
}
