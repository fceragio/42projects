/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 06:01:47 by federico          #+#    #+#             */
/*   Updated: 2025/05/06 10:05:53 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < MTSRC_LIMIT; i++){
		knownMateria[i] = NULL;
	}
	std::cout << "MateriaSource default constructor called\n";
}
MateriaSource::MateriaSource(AMateria* first){
	int i = 0;
	if (first != NULL){
		AMateria* copy = first->clone();
		knownMateria[i] = copy;
		delete first;
		first = NULL;
		i++;
	}
	while (i < MTSRC_LIMIT){
		knownMateria[i] = NULL;
		i++;
	}
	std::cout << "MateriaSource parameter constructor called\n";
}

MateriaSource::MateriaSource(const MateriaSource& other){
	for (int i = 0; i < MTSRC_LIMIT; i++){
		if (other.knownMateria[i]){
			this->knownMateria[i] = other.knownMateria[i]->clone();
		}
		else{
			this->knownMateria[i] = NULL;
		}
	}
	std::cout << "MateriaSource copy constructor called\n";
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other){
	if (this != &other){
		for (int i = 0; i < MTSRC_LIMIT; i++){
			if (this->knownMateria[i]){
				delete this->knownMateria[i];
				this->knownMateria[i] = NULL;
			}
		}
		for (int i = 0; i < MTSRC_LIMIT; i++){
			if (other.knownMateria[i]){
			this->knownMateria[i] = other.knownMateria[i]->clone();
		}
		else{
			this->knownMateria[i] = NULL;
		}
		}
	}
	else{
		std::cout << "MateriaSource double assignation prevented\n";
	}
	return *this;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < MTSRC_LIMIT; i++){
		if (knownMateria[i]){
			delete knownMateria[i];
			knownMateria[i] = NULL;
		}
	}
	std::cout << "MateriaSource destructor called\n";
}

void	MateriaSource::learnMateria(AMateria* toLearn){
	if (toLearn == NULL){
		std::cout << "MateriaSource can not learn NULL Materias\n";
		return ;
	}
	for (int i = 0; i < MTSRC_LIMIT; i++){
		if (knownMateria[i] == NULL){
			knownMateria[i] = toLearn->clone();
			delete toLearn;
			toLearn = NULL;
			std::cout << "MateriaSource learned " << knownMateria[i]->getType() << '\n';
			return ;
		}
	}
	std::cout << "MateriaSource has no space left to learn this materia (materia broke in the process)\n";
	delete toLearn;
}

AMateria*	MateriaSource::createMateria(const std::string& type){
	for (int i = 0; i < MTSRC_LIMIT; i++){
		if (knownMateria[i]){
			if (knownMateria[i]->getType() == type){
				std::cout << "MateriaSource created a new " << type << " Materia\n";
				return knownMateria[i]->clone();
			}
		}
	}
	std::cout << "MateriaSource couldn't produce unknown Materia\n";
	return 0;
}
