/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 06:38:39 by federico          #+#    #+#             */
/*   Updated: 2025/05/12 06:44:46 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void	swap(T& x, T& y){
	T	temp;

	temp = x;
	x = y;
	y = temp;
}

template <typename T>
T	min(T x, T y){
	if (x < y){
		return x;
	}
	return y;
}

template <typename T>
T	max(T x, T y){
	if (x > y){
		return x;
	}
	return y;
}


#endif