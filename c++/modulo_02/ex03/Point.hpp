/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:03:20 by federico          #+#    #+#             */
/*   Updated: 2025/04/30 21:27:33 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point{
private:
	const Fixed	x;
	const Fixed	y;


public:
	Point();
	Point(const float x, const float y);

	Point(const Point& other);

	Point& operator=(const Point& other);

	~Point();

	const Fixed&	get_x()const;
	const Fixed&	get_y()const;
};

#endif