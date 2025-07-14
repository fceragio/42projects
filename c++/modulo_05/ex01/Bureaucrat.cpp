/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:44:10 by federico          #+#    #+#             */
/*   Updated: 2025/05/07 21:42:48 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Unidentified"), grade(BOTTOM_GRD){
	std::cout << "Bureaucrat default constructor called\n";
}
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade){
	if (grade < TOP_GRD){
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > BOTTOM_GRD){
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << "Bureaucrat parameter constructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade){
	std::cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other){
		this->grade = other.grade;
		std::cout << "Bureaucrat assignment called (name will stay unchanged)\n";
	}
	else{
		std::cout << "Bureaucrat double assignment avoided\n";
	}
	return *this;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor called\n";
}

const std::string	Bureaucrat::getName() const{
	return this->name;
}
int					Bureaucrat::getGrade() const{
	return this->grade;
}

void	Bureaucrat::upGrade(){
	if (grade <= TOP_GRD){
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade--;
}
void	Bureaucrat::downGrade(){
	if (grade >= BOTTOM_GRD){
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade++;
}

void	Bureaucrat::signForm(Form& to_sign){
	try{
		to_sign.beSigned(*this);
	}
	catch (std::exception& e){
		std::cout << name << " couldn't sign form: " << to_sign.getName() << "because " << e.what() << '\n';
	}
	std::cout << name << " signed the form: " << to_sign.getName() << '\n';
}


const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Bureaucrat grade too high!";
}
const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Bureaucrat grade too low!";
}


std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& brc){
	stream << brc.getName() << ", bureaucrat grade " << brc.getGrade() << '\n';
	return stream;
}
