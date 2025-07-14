/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 04:18:44 by federico          #+#    #+#             */
/*   Updated: 2025/04/28 20:44:06 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cout << "wrong number of arguments" << std::endl;
		return 1;
	}
	Harl	harl;
	harl.complain(argv[1]);

	return 0;
}