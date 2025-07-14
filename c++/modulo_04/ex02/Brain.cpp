/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 07:49:33 by federico          #+#    #+#             */
/*   Updated: 2025/05/04 06:24:06 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	for (int i = 0; i < 100; i++){
		ideas[i] = "Some generic Animal Ideas\n";
	}
	std::cout << "Brain default constructor called\n";
}
Brain::Brain(const std::string& idea){
	for (int i = 0; i < 100; i++){
		ideas[i] = idea;
	}
	std::cout << "Brain parameter constructor called\n";
}

Brain::Brain(const Brain& other){
	for(int i = 0; i < 100; i++){
			this->ideas[i] = other.ideas[i];
		}
	std::cout << "Brain copy constructor called\n";
}

Brain&	Brain::operator=(const Brain& other){
	if (this != &other){
		for(int i = 0; i < 100; i++){
			this->ideas[i] = other.ideas[i];
		}
		std::cout << "Brain assign operator called successfully\n";
	}
	else{
		std::cout << "Brain double assignation prevented\n";
	}
	return *this;
}

Brain::~Brain(){
	std::cout << "Brain destructor called\n";
}

std::string	Brain::getIdea(const int index) const{
	if (index >= 0 && index < 100){
		std::cout << "Brain returning idea-> " << ideas[index] << '\n';
		return ideas[index];
	}
	std::cout << "Brain invalid index\n";
	return "";
}

void	Brain::setIdea(const int index, const std::string& idea){
	if (index >= 0 && index < 100){
		std::cout << "Brain setting idea-> " << idea << '\n';
		ideas[index] = idea;
	}
}
