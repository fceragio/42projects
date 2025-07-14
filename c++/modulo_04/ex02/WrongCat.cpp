/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 00:47:17 by federico          #+#    #+#             */
/*   Updated: 2025/05/04 03:38:18 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(const std::string& type) : WrongAnimal("WrongCat"){
	(void)type;
	std::cout << "WrongCat parameter constructor called (parameter discarded in favor of \"WrongCat\")\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other){
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat&	WrongCat::operator=(const WrongCat& other){
	if (this != &other){
		WrongAnimal::operator=(other);
		std::cout << "WrongCat assign operator called\n";
	}
	else{
		std::cout << "WrongCat double assignation prevented\n";
	}
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called\n";
}

void	WrongCat::makeSound() const{
	std::cout << "#Honk-Honk#\n";
}
