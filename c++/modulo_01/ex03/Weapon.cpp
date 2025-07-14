/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 03:12:27 by federico          #+#    #+#             */
/*   Updated: 2025/04/25 08:05:46 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type(type){
}

Weapon::~Weapon(){
	std::cout << type << " has been destroyed" << std::endl;
}

const std::string	&Weapon::getType(){
	return type;
}

void		Weapon::setType(std::string type){
	this->type = type;
}
