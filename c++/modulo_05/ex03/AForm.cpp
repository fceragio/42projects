/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 06:29:22 by federico          #+#    #+#             */
/*   Updated: 2025/05/07 21:01:50 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("basic_form"), sign(false), sn_grade(BOTTOM_GRD), ex_grade(BOTTOM_GRD) {
	std::cout << "AForm default constructorn called\n";
}
AForm::AForm(const std::string& name, int sn_grade, int ex_grade) : name(name),
																sign(false),
																sn_grade(sn_grade),
																ex_grade(ex_grade){
	if (sn_grade < TOP_GRD || ex_grade < TOP_GRD){
		throw GradeTooHighException();
	}
	if (sn_grade > BOTTOM_GRD || ex_grade > BOTTOM_GRD){
		throw GradeTooLowException();
	}
	std::cout << "AForm parameter constructor called\n";
}

AForm::AForm(const AForm& other) : name(other.name), sign(false), sn_grade(other.sn_grade), ex_grade(other.ex_grade){
	std::cout << "AForm copy constructor called (notice that sign is generated false regardless)\n";
}

AForm&	AForm::operator=(const AForm& other){
	if (this != &other){
		this->sign = other.sign;
		std::cout << "AForm assignation called (only sign is copied)\n";
	}
	else{
		std::cout << "AForm double assignation avoided\n";
	}
	return *this;
}

AForm::~AForm(){
	std::cout << "AForm destructor called\n";
}

const std::string&	AForm::getName() const{
	return this->name;
}
bool			AForm::getSign() const{
	return this->sign;
}
int				AForm::getSnGrade() const{
	return this->sn_grade;
}
int				AForm::getExGrade() const{
	return this->ex_grade;
}

void	AForm::beSigned(const Bureaucrat& signer){
	if (this->sn_grade < signer.getGrade()){
		throw GradeTooLowException();
	}
	this->sign = true;
}
void	AForm::execute(const Bureaucrat& executor) const{
	if (this->ex_grade < executor.getGrade()){
		throw GradeTooLowException();
	}
	if (this->getSign() == false){
		throw FormIsNotSignedException();
	}
	std::cout << "Execution granted\n";
}

const char*	AForm::GradeTooLowException::what() const throw(){
	return "grade too low!";
}
const char*	AForm::GradeTooHighException::what() const throw(){
	return "grade too high!";
}
const char*	AForm::FormIsNotSignedException::what() const throw(){
	return "form lacking sign!";
}

std::ostream&	operator<<(std::ostream& stream, const AForm& form){
	stream << "AForm name: " << form.getName() << '\n';
	stream << "sign stat: " << form.getSign() << '\n';
	stream << "signGrade: " << form.getSnGrade() << '\n';
	stream << "execGrade: " << form.getExGrade() << '\n';
	return stream;
}
