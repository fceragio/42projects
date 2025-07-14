/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:05:27 by federico          #+#    #+#             */
/*   Updated: 2025/04/25 01:02:49 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
}
Zombie::Zombie(std::string name)
	:	name(name){
}
Zombie::~Zombie(){
	std::cout << name << " has been destroyed" << std::endl;
}

void	Zombie::set_name(std::string name){
	this->name = name;
}

void	Zombie::announce(void){
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
