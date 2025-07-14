/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 02:12:13 by federico          #+#    #+#             */
/*   Updated: 2025/05/12 03:07:02 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

void print_data(Data* data){
	std::cout << "Data pointer: " << data << '\n';
	std::cout << "Data name: " << data->name << '\n';
	std::cout << "Data num: " << data->num << std::endl;
}
