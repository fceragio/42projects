/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 06:29:22 by federico          #+#    #+#             */
/*   Updated: 2025/05/07 21:01:50 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("basic_form"), sign(false), sn_grade(BOTTOM_GRD), ex_grade(BOTTOM_GRD) {
	std::cout << "Form default constructorn called\n";
}
Form::Form(const std::string& name, int sn_grade, int ex_grade) : name(name),
																sign(false),
																sn_grade(sn_grade),
																ex_grade(ex_grade){
	if (sn_grade < TOP_GRD || ex_grade < TOP_GRD){
		throw GradeTooHighException();
	}
	if (sn_grade > BOTTOM_GRD || ex_grade > BOTTOM_GRD){
		throw GradeTooLowException();
	}
	std::cout << "Form parameter constructor called\n";
}

Form::Form(const Form& other) : name(other.name), sign(false), sn_grade(other.sn_grade), ex_grade(other.ex_grade){
	std::cout << "Form copy constructor called (notice that sign is generated false regardless)\n";
}

Form&	Form::operator=(const Form& other){
	if (this != &other){
		this->sign = other.sign;
		std::cout << "Form assignation called (only sign is copied)\n";
	}
	else{
		std::cout << "Form double assignation avoided\n";
	}
	return *this;
}

Form::~Form(){
	std::cout << "Form destructor called\n";
}

const std::string&	Form::getName() const{
	return this->name;
}
bool			Form::getSign() const{
	return this->sign;
}
int				Form::getSnGrade() const{
	return this->sn_grade;
}
int				Form::getExGrade() const{
	return this->ex_grade;
}

void	Form::beSigned(const Bureaucrat& signer){
	if (this->sn_grade < signer.getGrade()){
		throw GradeTooLowException();
	}
	this->sign = true;
}

const char*	Form::GradeTooLowException::what() const throw(){
	return "grade too low!";
}
const char*	Form::GradeTooHighException::what() const throw(){
	return "grade too high!";
}

std::ostream&	operator<<(std::ostream& stream, const Form& form){
	stream << "Form name: " << form.getName() << '\n';
	stream << "sign stat: " << form.getSign() << '\n';
	stream << "signGrade: " << form.getSnGrade() << '\n';
	stream << "execGrade: " << form.getExGrade() << '\n';
	return stream;
}
