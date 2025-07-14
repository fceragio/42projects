/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 02:35:55 by federico          #+#    #+#             */
/*   Updated: 2025/05/11 04:45:51 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char* argv[]){
	if (argc != 2){
		std::cerr << "Wrong argument number\n";
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	
	return 0;
}