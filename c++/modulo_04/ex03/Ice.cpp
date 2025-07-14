/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 00:56:29 by federico          #+#    #+#             */
/*   Updated: 2025/05/06 07:52:51 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
	std::cout << "Default Ice constructor called\n";
}
Ice::Ice(const std::string& type) : AMateria("ice"){
	(void)type;
	std::cout << "Parameter Ice constructor called (string ignored)\n";
}

Ice::Ice(const Ice& other) : AMateria(other){
	std::cout << "Ice copy constructor called\n";
}

Ice&	Ice::operator=(const Ice& other){
	if (this != &other){
		AMateria::operator=(other);
		std::cout << "Ice assign operator called\n";
	}
	else{
		std::cout << "Ice double assignation prevented\n";
	}
	return *this;
}

Ice::~Ice(){
	std::cout << "Ice destructor called\n";
}

AMateria*	Ice::clone() const{
	return new Ice(*this);
}