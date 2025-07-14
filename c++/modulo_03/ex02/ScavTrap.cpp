/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 03:04:38 by federico          #+#    #+#             */
/*   Updated: 2025/05/03 04:10:55 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	setHitPts(100);
	setEnergyPts(50);
	setAttackDmg(20);
	std::cout << "ScavTrap default constructor called\n";
}
ScavTrap::ScavTrap(const std::string& Name) : ClapTrap(Name){
	setHitPts(100);
	setEnergyPts(50);
	setAttackDmg(20);
	std::cout << "ScavTrap parameter constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other){
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
	if (this != &other){
		ClapTrap::operator=(other);
		std::cout << "ScavTrap assign operator\n";
	}
	else{
		std::cout << "ScavTrap double assignation prevented\n";
	}
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called\n";
}

void	ScavTrap::attack(const std::string& target){
	if (this->getHitPts() > 0 && this->getEnergyPts() >= COST){
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << " dealing " << this->getAttackDmg() << " damage points\n";
		std::cout << "ScavTrap Energy_pts: " << this->getEnergyPts() << " -> " << this->getEnergyPts() - COST << '\n';
		this->setEnergyPts(this->getEnergyPts() - COST);
	}
	else{
		std::cout << "ScavTrap " << this->getName() << " couldn't attack " << target << ". [Energy_pts, Hit_pts] [" << this->getEnergyPts() << ", " << this->getHitPts() << "]\n";
	}
}

void	ScavTrap::guardGate(){
	std::cout << "ScavTrap is in Gate_keeper mode\n";
}
