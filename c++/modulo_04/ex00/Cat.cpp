/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:56:22 by federico          #+#    #+#             */
/*   Updated: 2025/05/04 03:22:21 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const std::string& type) : Animal("Cat"){
	(void)type;
	std::cout << "Cat parameter constructor called (parameter discarded in favor of \"Cat\")\n";
}

Cat::Cat(const Cat& other) : Animal(other){
	std::cout << "Cat copy constructor called\n";
}

Cat&	Cat::operator=(const Cat& other){
	if (this != &other){
		Animal::operator=(other);
		std::cout << "Cat assign operator called\n";
	}
	else{
		std::cout << "Cat double assignation prevented\n";
	}
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat destructor called\n";
}

void	Cat::makeSound() const{
	std::cout << "Meow~\n";
}
