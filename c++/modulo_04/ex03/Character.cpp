/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 04:00:23 by federico          #+#    #+#             */
/*   Updated: 2025/05/06 05:28:43 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("-UNKNOWN-"){
	for (int i = 0; i < BASE_INV; i++){
		inventory[i] = NULL;
	}
	for (int i = 0; i < FLOOR_SLOTS; i++){
		onTheFloor[i] = NULL;
	}
	std::cout << name << " named Character spawned\n";
}
Character::Character(const std::string& name) : name(name){
	for (int i = 0; i < BASE_INV; i++){
		inventory[i] = NULL;
	}
	for (int i = 0; i < FLOOR_SLOTS; i++){
		onTheFloor[i] = NULL;
	}
	std::cout << name << " named Character spawned\n";
}

Character::Character(const Character& other) : name(other.name){
	for (int i = 0; i < BASE_INV; i++){
		if (other.inventory[i]){
			this->inventory[i] = other.inventory[i]->clone();
		}
		else{
			this->inventory[i] = NULL;
		}
	}
	for (int i = 0; i < FLOOR_SLOTS; i++){
		this->onTheFloor[i] = NULL;
	}
	std::cout << name << " named Character's copy spawned (dropped materia are not copied)\n";
}

Character&	Character::operator=(const Character& other){
	if (this != &other){
		std::string temp = this->name;
		this->name = other.name;
		for (int i = 0; i < BASE_INV; i++){
			if (this->inventory[i]){
				delete this->inventory[i];
				this->inventory[i] = NULL;
			}
		}
		for (int i = 0; i < BASE_INV; i++){
			if (other.inventory[i]){
				this->inventory[i] = other.inventory[i]->clone();
				this->inventory[i]->setEquipped(true);
			}
			else{
				this->inventory[i] = NULL;
			}
		}
		std::cout << temp << " got changed into " << other.name << ". [inventory also morphed, but dropped objects are not copied]\n";
	}
	else{
		std::cout << "Character double assignation prevented\n";
	}
	return *this;
}

Character::~Character(){
	for (int i = 0; i < BASE_INV; i++){
		if (inventory[i]){
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
	for (int i = 0; i < FLOOR_SLOTS; i++){
		if (onTheFloor[i]){
			delete onTheFloor[i];
			onTheFloor[i] = NULL;
		}
	}
	std::cout << name << " named Character destroyed\n";
}

const	std::string& Character::getName() const{
	return this->name;
}

void	Character::equip(AMateria* m){
	if (!m){
		std::cout << "NULL is not a materia. couldn' t equip.\n";
		return ;
	}
	if (m->getEquipped()){
		std::cout << m->getType() << " materia is already equipped somewhere else. " << name << " couldn't equip it\n";
		return ;
	}
	for (int i = 0; i < 4; i++){
		if (inventory[i] == NULL){
			inventory[i] = m;
			m->setEquipped(true);
			std::cout << name << " equipped (i   Materia) " << i << inventory[i]->getType() << '\n';
			return ;
		}
	}
	std::cout << this->name << "'s inventory was full. Couldn't equip " << m->getType() << '\n';
}

void	Character::unequip(int idx){
	if (idx < 0 || idx >= BASE_INV){
		std::cout << idx << " is not an available slot in " << name << " 's inventory\n";
		return ;
	}
	if (inventory[idx] != NULL){
		std::cout << name << " unequipping (i   Materia) " << idx << inventory[idx]->getType() << '\n';
		AMateria* temp = inventory[idx];
		for (int i = 0; i < FLOOR_SLOTS; i++){
			if (onTheFloor[i] == NULL){
				inventory[idx] = NULL;
				onTheFloor[i] = temp;
				temp->setEquipped(false);
				return ;
			}
		}
		std::cout << "The floor around " << name << " was so full of dropped materia, it was impossible to unequip even one more\n";
	}
}

void	Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx >= BASE_INV){
		std::cout << idx << " is not an available slot in " << name << "'s inventory\n";
		return ;
	}
	if (inventory[idx] != NULL){
		std::cout << name << " uses ";
		inventory[idx]->use(target);
	}
	else{
		std::cout << name << " didn't have anything equipped in slot " << idx << '\n';
	}
}
