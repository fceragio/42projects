/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 02:09:09 by federico          #+#    #+#             */
/*   Updated: 2025/05/12 03:09:03 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>
#include "Data.hpp"
#include "Serializer.hpp"

int main(){
	Data data = {"My data exemple", 1};
	print_data(&data);
	std::cout << '\n';

	uintptr_t	serialized = Serializer::serialize(&data);
	std::cout << &data << " serialized-> " << serialized << '\n';
	std::cout << '\n';

	Data* data_pointer = Serializer::deserialize(serialized);
	std::cout << serialized << " deserialized-> " << data_pointer << '\n';
	std::cout << '\n';

	print_data(data_pointer);
	
	return 0;
}
