/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 06:57:46 by federico          #+#    #+#             */
/*   Updated: 2025/05/13 01:37:35 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cstring>

template <typename T, typename F>
void	iter(T* arr, size_t size, F func){
	for (size_t i = 0; i < size; i++){
		func(arr[i]);
	}
}

template <typename T>
void	print(const T& to_print){
	std::cout << to_print << '\n';
}

#endif