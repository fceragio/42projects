/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 00:35:31 by federico          #+#    #+#             */
/*   Updated: 2025/05/06 07:52:32 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
	std::cout << "Default Cure constructor called\n";
}
Cure::Cure(const std::string& type) : AMateria("cure"){
	(void)type;
	std::cout << "Parameter Cure constructor called (string ignored)\n";
}

Cure::Cure(const Cure& other) : AMateria(other){
	std::cout << "Cure copy constructor called\n";
}

Cure&	Cure::operator=(const Cure& other){
	if (this != &other){
		AMateria::operator=(other);
		std::cout << "Cure assign operator called\n";
	}
	else{
		std::cout << "Cure double assignation prevented\n";
	}
	return *this;
}

Cure::~Cure(){
	std::cout << "Cure destructor called\n";
}

AMateria*	Cure::clone() const{
	return new Cure(*this);
}
