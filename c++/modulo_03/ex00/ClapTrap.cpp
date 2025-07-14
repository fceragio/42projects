/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:58:04 by federico          #+#    #+#             */
/*   Updated: 2025/05/03 02:53:28 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name(NAME),
					Hit_pts(10),
					Energy_pts(10),
					Attack_dmg(0){
std::cout << "Default " << "ClapTrap " << this->getName() << " has been constructed\n";
}
ClapTrap::ClapTrap(const std::string& name) : Name(name),
											Hit_pts(10),
											Energy_pts(10),
											Attack_dmg(0){
	std::cout << "ClapTrap " << this->getName() << " has been constructed\n";
}

ClapTrap::ClapTrap(const ClapTrap& other){
	setName(other.getName());
	setHitPts(other.getHitPts());
	setEnergyPts(other.getEnergyPts());
	setAttackDmg(other.getAttackDmg());
	std::cout << "ClapTrap " << this->getName() << " has been copied with a copy constructor\n";
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other){
	if (this == &other){
		std::cout << "Tried to use = operator to doubleassign prevented\n";
		return *this;
	}
	std::cout << "Successfully assigned with = operator\n";
	this->setName(other.Name);
	this->setHitPts(other.Hit_pts);
	this->setEnergyPts(other.Energy_pts);
	this->setAttackDmg(other.Attack_dmg);
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << this->getName() << " has been destroyed\n";
}


std::string	ClapTrap::getName()const{
	return this->Name;
}
int			ClapTrap::getHitPts()const{
	return this->Hit_pts;
}
int			ClapTrap::getEnergyPts()const{
	return this->Energy_pts;
}
int			ClapTrap::getAttackDmg()const{
	return this->Attack_dmg;
}


void		ClapTrap::setName(const std::string& Name){
	this->Name = Name;
}
void		ClapTrap::setHitPts(const unsigned int Hit_pts){
	this->Hit_pts = Hit_pts;
}
void		ClapTrap::setEnergyPts(const unsigned int Energy_pts){
	this->Energy_pts = Energy_pts;
}
void		ClapTrap::setAttackDmg(const unsigned int Attack_dmg){
	this->Attack_dmg = Attack_dmg;
}


void	ClapTrap::attack(const std::string& target){
	if (this->getHitPts() > 0 && this->getEnergyPts() >= COST){
		std::cout << "ClapTrap " << this->getName() << " attacks " << target << " dealing " << this->getAttackDmg() << " damage points\n";
		std::cout << "ClapTrap Energy_pts: " << this->getEnergyPts() << " -> " << this->getEnergyPts() - COST << '\n';
		this->setEnergyPts(this->getEnergyPts() - COST);
	}
	else{
		std::cout << "ClapTrap " << this->getName() << " couldn't attack " << target << ". [Energy_pts, Hit_pts] [" << this->getEnergyPts() << ", " << this->getHitPts() << "]\n";
	}
}
void	ClapTrap::takeDamage(unsigned int amount){
	unsigned int temp = this->getHitPts();
	if (temp >= amount){
		std::cout << "ClapTrap " << this->getName() << " takes " << amount << " points of damage\n";
		this->setHitPts(this->getHitPts() - amount);
		std::cout << "Hit_pts: " << temp << " -> " << this->getHitPts() << '\n';
	}
	else{
		this->setHitPts(0);
		std::cout << "ClapTrap " << this->getName() << " takes " << amount << " points of OVERKILL damage\n";
		std::cout << "Hit_pts: " << temp << " -> " << this->getHitPts() << '\n';
	}
}
void	ClapTrap::beRepaired(unsigned int amount){
	unsigned int temp = this->getHitPts();
	if (temp > 0 && this->getEnergyPts() >= COST){
		if ((10 - temp) > amount){
			this->setHitPts(this->getHitPts() + amount);
			std::cout << "ClapTrap " << this->getName() << " has repaired " << amount << " points of damage\n";
			std::cout << "Hit_pts: " << temp << " -> " << this->getHitPts() << '\n';
			std::cout << "ClapTrap Energy_pts: " << this->getEnergyPts() << " -> " << this->getEnergyPts() - COST << '\n';
		}
		else{
			this->setHitPts(10);
			std::cout << "ClapTrap " << this->getName() << " has repaired " << 10 - temp << " points of damage\n";
			std::cout << "Hit_pts: " << temp << " -> " << this->getHitPts() << '\n';
			std::cout << "ClapTrap Energy_pts: " << this->getEnergyPts() << " -> " << this->getEnergyPts() - COST << '\n';
		}
		this->setEnergyPts(this->getEnergyPts() - COST);
	}
	else{
		std::cout << "ClapTrap " << this->getName() << " couldn't repair" << ". [Energy_pts, Hit_pts] [" << this->getEnergyPts() << ", " << this->getHitPts() << "]\n"; 
	}
}
