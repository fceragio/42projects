/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:56:22 by federico          #+#    #+#             */
/*   Updated: 2025/05/05 01:43:32 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	catBrain = new Brain("Cat ideas");
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const std::string& type) : Animal("Cat"){
	(void)type;
	catBrain = new Brain("Cat ideas");
	std::cout << "Cat parameter constructor called (parameter discarded in favor of \"Cat\")\n";
}

Cat::Cat(const Cat& other) : Animal(other){
	this->catBrain = new Brain(*other.catBrain);
	std::cout << "Cat copy constructor called\n";
}

Cat&	Cat::operator=(const Cat& other){
	if (this != &other){
		Animal::operator=(other);
		delete catBrain;
		this->catBrain = new Brain(*other.catBrain);
		std::cout << "Cat assign operator called\n";
	}
	else{
		std::cout << "Cat double assignation prevented\n";
	}
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat's Brain destructor called\n";
	delete catBrain;
	std::cout << "Cat destructor called\n";
}

void	Cat::makeSound() const{
	std::cout << "Meow~\n";
}

Brain*	Cat::getBrain() const{
	return catBrain;
}

Animal*	Cat::clone(){
	std::cout << "cloning Cat\n";
	return new Cat(*this);
}
