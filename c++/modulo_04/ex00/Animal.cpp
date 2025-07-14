/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:36:27 by federico          #+#    #+#             */
/*   Updated: 2025/05/03 00:23:23 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("generic_animal"){
	std::cout << "Default Animal constructor for type-> " << type << '\n';
}
Animal::Animal(const std::string& type) : type(type){
	std::cout << "Animal constructor for type-> " << type << '\n';
}

Animal::Animal(const Animal& other) : type(other.type){
	std::cout << "Animal copy constructor for type-> " << type << '\n';
}

Animal&	Animal::operator=(const Animal& other){
	if (this != &other){
		this->type = other.type;
		std::cout << "Animal assign operator called for Animal of type->" << this->type << '\n';
	}
	else{
		std::cout << "Preventing double assignation for Animal of type-> " << this->type << '\n';
	}
	return *this;
}

Animal::~Animal(){
	std::cout << "Animal destructor for type-> " << type << '\n';
}

const std::string& Animal::getType() const{
	return this->type;
}

void	Animal::setType(const std::string& type){
	this->type = type;
}

void	Animal::makeSound() const{
	std::cout << "Base Animal doesn't make a sound... type-> " << type << '\n';
}
