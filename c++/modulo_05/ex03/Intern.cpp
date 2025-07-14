/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 03:45:02 by federico          #+#    #+#             */
/*   Updated: 2025/05/10 01:59:13 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

static AForm*	makePresidentialPardonForm(const std::string& target){
	return new PresidentialPardonForm(target);
}
static AForm*	makeRobotomyRequestForm(const std::string& target){
	return new RobotomyRequestForm(target);
}
static AForm*	makeShrubberyCreationForm(const std::string& target){
	return new ShrubberyCreationForm(target);
}

struct	form_function_pair{
	std::string	name;
	AForm* (*creation_function) (const std::string& target);
};

Intern::Intern(){
	std::cout << "Intern default constructor called\n";
}

Intern::Intern(const Intern& other){
	(void)other;
	std::cout << "Intern copy constructor called\n";
}

Intern&	Intern::operator=(const Intern& other){
	(void)other;
	if (this != &other){
		std::cout << "Intern assign operator called\n";
	}
	else{
		std::cout << "Intern double assignation avoided\n";
	}
	return *this;
}

Intern::~Intern(){
	std::cout << "Intern destructor called\n";
}

AForm*	Intern::makeForm(const std::string& form, const std::string& target){
	form_function_pair	pairs[3] = {
		{"PresidentialPardonForm" , makePresidentialPardonForm},
		{"RobotomyRequestForm", makeRobotomyRequestForm},
		{"ShrubberyCreationForm", makeShrubberyCreationForm}
	};

	for (int i = 0; i < 3; i++){
		if (form == pairs[i].name){
			std::cout << "Intern creates " << form << '\n';
			return pairs[i].creation_function(target);
		}
	}
	std::cerr << "ERROR: " << form << " is not an available type of AForm! (returning NULL)\n";
	return NULL;
}
