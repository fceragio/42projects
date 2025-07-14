/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 07:02:55 by federico          #+#    #+#             */
/*   Updated: 2025/04/25 08:12:09 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : name(name), weapon(weapon){
}
HumanA::~HumanA(){
	std::cout << name << " has been destroyed" << std::endl;
}

void	HumanA::attack(){
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
