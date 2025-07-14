/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:13:21 by federico          #+#    #+#             */
/*   Updated: 2025/05/08 05:29:31 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45){
	this->target = "Default_target";
	std::cout << "RobotomyRequestForm default constructor called\n";
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45){
	this->target = target;
	std::cout << "RobotomyRequestForm parameter constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other.getName(), other.getSnGrade(), other.getExGrade()){
	this->target = other.target;
	std::cout << "RobotomyRequestForm copy constructor called \n";
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if (this != &other){
		AForm::operator=(other);
		this->target = other.target;
		std::cout << "RobotomyRequestForm assign operator called\n";
	}
	else{
		std::cout << "RobotomyRequestForm double assignation avoided\n";
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm destructor called\n";
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const{
	AForm::execute(executor);

	static bool	seeded = false;
	if (seeded == false){
		srand(time(0));
		seeded = true;
	}
	
	bool	success = rand() % 2;
	std::cout << "*Drilling noises*\n";
	if (success == true){
		std::cout << target << " has been successfully robotomized!\n";
	}
	else{
		std::cout << target << "'s robotomy failed!\n";
	}
}
