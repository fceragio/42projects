/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:58:36 by federico          #+#    #+#             */
/*   Updated: 2025/05/13 04:19:55 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>
# include <iostream>

template <typename T>
class	Array{
private:
	T*	elements;
	size_t	length;
public:
	Array();
	Array(size_t length);
	
	Array(const Array& other);

	Array&	operator=(const Array& other);

	~Array();

	size_t	size() const;
	T&	operator[](size_t index);
	const T& operator[](size_t index) const;
};

# include "Array.tpp"

#endif