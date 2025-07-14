/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 00:43:35 by federico          #+#    #+#             */
/*   Updated: 2025/05/03 00:51:44 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("generic_animal"){
	std::cout << "Default WrongAnimal constructor for type-> " << type << '\n';
}
WrongAnimal::WrongAnimal(const std::string& type) : type(type){
	std::cout << "WrongAnimal constructor for type-> " << type << '\n';
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type){
	std::cout << "WrongAnimal copy constructor for type-> " << type << '\n';
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other){
	if (this != &other){
		this->type = other.type;
		std::cout << "WrongAnimal assign operator called for WrongAnimal of type->" << this->type << '\n';
	}
	else{
		std::cout << "Preventing double assignation for WrongAnimal of type-> " << this->type << '\n';
	}
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor for type-> " << type << '\n';
}

const std::string& WrongAnimal::getType() const{
	return this->type;
}

void	WrongAnimal::setType(const std::string& type){
	this->type = type;
}

void	WrongAnimal::makeSound() const{
	std::cout << "Base WrongAnimal doesn't make a sound... type-> " << type << '\n';
}
