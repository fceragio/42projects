/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 05:51:37 by federico          #+#    #+#             */
/*   Updated: 2025/05/04 03:28:07 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const std::string& type) : Animal("Dog"){
	(void)type;
	std::cout << "Dog parameter constructor called (parameter discarded in favor of \"Dog\")\n";
}

Dog::Dog(const Dog& other) : Animal(other){
	std::cout << "Dog copy constructor called\n";
}

Dog&	Dog::operator=(const Dog& other){
	if (this != &other){
		Animal::operator=(other);
		std::cout << "Dog assign operator called\n";
	}
	else{
		std::cout << "Dog double assignation prevented\n";
	}
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog destructor called\n";
}

void	Dog::makeSound() const{
	std::cout << "*Woof*\n";
}