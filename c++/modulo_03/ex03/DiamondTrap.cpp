/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 05:51:29 by federico          #+#    #+#             */
/*   Updated: 2025/05/03 07:32:00 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), Name("Default"){
	setHitPts(100);
	setEnergyPts(50);
	setAttackDmg(30);
	std::cout << "DiamondTrap default constructor called\n";
}
DiamondTrap::DiamondTrap(const std::string& Name) : ClapTrap(Name + "_clap_name"), Name(Name){
	setHitPts(100);
	setEnergyPts(50);
	setAttackDmg(30);
	std::cout << "DiamondTrap parameter constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other){
	*this = other;
	std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other){
	if (this != &other){
		ClapTrap::operator=(other);
		std::cout << "DiamondTrap assign operator called\n";
	}
	else{
		std::cout << "DiamondTrap double assignation prevented\n";
	}
	return *this;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap destructor called \n";
}

void	DiamondTrap::whoAmI(){
	std::cout << "Name: " << Name << "\nClapTrap name: " << ClapTrap::getName() << '\n';
}