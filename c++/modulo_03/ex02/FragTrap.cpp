/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 04:17:11 by federico          #+#    #+#             */
/*   Updated: 2025/05/03 05:46:57 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	setHitPts(100);
	setEnergyPts(100);
	setAttackDmg(30);
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const std::string Name) : ClapTrap(Name){
	setHitPts(100);
	setEnergyPts(100);
	setAttackDmg(30);
	std::cout << "FragTrap parameter constructor called\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other){
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other){
	if (this != &other){
		ClapTrap::operator=(other);
		std::cout << "FragTrap assign operator\n";
	}
	else{
		std::cout << "FragTrap double assignation avoided\n";
	}
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called \n";
}

void	FragTrap::highFiveGuys(){
	std::cout << "FragTrap request for positive high-five!\n";
}
