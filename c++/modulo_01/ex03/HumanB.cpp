/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 08:19:16 by federico          #+#    #+#             */
/*   Updated: 2025/04/25 08:56:44 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name){
	weapon = NULL;
}
HumanB::~HumanB(){
	std::cout << name << " has been destroyed" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}

void	HumanB::attack(){
	if (weapon != NULL){
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	}
	else{
		std::cout << name << " attacks with their " << "bear hands" << std::endl;
	}
}
