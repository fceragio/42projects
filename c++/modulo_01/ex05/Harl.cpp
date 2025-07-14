/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 04:25:24 by federico          #+#    #+#             */
/*   Updated: 2025/04/28 20:51:19 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
	// std::cout << "Harl just entered the bar" << std::endl;
}
Harl::~Harl(){
	// std::cout << "Harl is leaving" << std::endl;
}

void	Harl::debug(void){
	std::cout << "[ DEBUG ]\n" << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void	Harl::info(void){
	std::cout << "[ INFO ]\n" << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void	Harl::warning(void){
	std::cout << "[ WARNING ]\n" << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::error(void){
	std::cout << "[ ERROR ]\n" << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level){
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int index = -1;
	for (int i = 0; i < 4; i++){
		if (levels[i] == level){
			index = i;
			break;
		}
	}

	switch (index){
		case 0:
			debug();
			// fall through
		case 1:
			info();
			// fall through
		case 2:
			warning();
			// fall through
		case 3:
			error();
			// fall through
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

// long long baby_hash(std::string string){
// 	const int p = 31;
// 	const int m = 1e9 + 9;
// 	long long hash_value = 0;
// 	long long p_pow = 1;
// 	for (size_t i; i < string.length(); i++){
// 		char c = string[i];
// 		hash_value = (hash_value + (c + 1) * p_pow) % m;
// 		p_pow = (p_pow * p) % m;
// 	}
// 	return hash_value;
// }

// void	Harl::complain(std::string level){
// 	long long hash_value = baby_hash(level);
	
// 	long long debug_value = baby_hash("DEBUG");
// 	long long info_value = baby_hash("INFO");
// 	long long warning_value = baby_hash("WARNING");
// 	long long error_value = baby_hash("ERROR");

// 	switch (hash_value){
// 		case debug_value:
// 			debug();
// 			break;
// 		case info_value:
// 			info();
// 			break;
// 		case warning_value:
// 			warning();
// 			break;
// 		case error_value:
// 			error();
// 			break;
// 		default:
// 			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
// 	}
// }
