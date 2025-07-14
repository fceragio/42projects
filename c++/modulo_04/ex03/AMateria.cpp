/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 02:49:25 by federico          #+#    #+#             */
/*   Updated: 2025/05/06 07:55:45 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("Default Materia"), equipped(false){
	std::cout << "Default Materia created\n";
}
AMateria::AMateria(const std::string& type) : type(type), equipped(false){
	std::cout << type << " Materia created\n";
}

AMateria::AMateria(const AMateria& other) : type(other.type), equipped(false){
	std::cout << type << " Materia copyed\n";
}

AMateria&	AMateria::operator=(const AMateria& other){
	if (this != &other){
		this->type = other.type;
		std::cout << type << " AMateria assignation called\n";
	}
	else{
		std::cout << "AMateria double assignation prevented\n";
	}
	return *this;
}

AMateria::~AMateria(){
	std::cout << type << " Materia destructed\n";
}

const	std::string& AMateria::getType() const{
	return this->type;
}
bool	AMateria::getEquipped() const{
	return this->equipped;
}

void	AMateria::setEquipped(const bool flag){
	this->equipped = flag;
}

void	AMateria::use(ICharacter& target){
	std::cout << type << ": ";
	if (type == "cure"){
		std::cout << "* heals " << target.getName() << "'s wounds *\n";
	}
	else if (type == "ice"){
		std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
	}
	else{
		std::cout << "didn't work! :(\n";
	}
}
