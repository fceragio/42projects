/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 01:02:39 by federico          #+#    #+#             */
/*   Updated: 2025/05/08 06:01:48 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5){
	this->target = "Default_target";
	std::cout << "PresidentialPardonForm default constructor called\n";
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5){
	this->target = target;
	std::cout << "PresidentialPardonForm parameter constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other.getName(), other.getSnGrade(), other.getExGrade()){
	this->target = other.target;
	std::cout << "PresidentialPardonForm copy constructor called \n";
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	if (this != &other){
		AForm::operator=(other);
		this->target = other.target;
		std::cout << "PresidentialPardonForm assign operator called\n";
	}
	else{
		std::cout << "PresidentialPardonForm double assignation avoided\n";
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "PresidentialPardonForm destructor called\n";
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const{
	AForm::execute(executor);
	
	std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}
