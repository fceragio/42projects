/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:58:03 by federico          #+#    #+#             */
/*   Updated: 2025/05/13 04:50:06 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(){
	size_t	size = 5;

	Array<std::string>	strArray(size);
	strArray[0] = "asd only one string initialized at the time :(";
	for (size_t i = 0; i < size; i++){
		std::cout << strArray[i] << '\n';
	}
	std::cout << '\n';

	Array<int>	intArray(size);
	intArray[0] = 37;
	for (size_t i = 0; i < size; i++){
		std::cout << intArray[i] << '\n';
	}
	std::cout << '\n';

	Array<char>	charArray(size);
	charArray[0] = 'c';
	for (size_t i = 0; i < size; i++){
		std::cout << charArray[i] << '\n';
	}
	std::cout << '\n';

	return 0;
}
