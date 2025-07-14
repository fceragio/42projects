/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 05:38:35 by federico          #+#    #+#             */
/*   Updated: 2025/05/08 10:14:30 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137){
	this->target = "Default_target";
	std::cout << "ShrubberyCreationForm default constructor called\n";
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137){
	this->target = target;
	std::cout << "ShrubberyCreationForm parameter constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), other.getSnGrade(), other.getExGrade()){
	this->target = other.target;
	std::cout << "ShrubberyCreationForm copy constructor called \n";
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this != &other){
		AForm::operator=(other);
		this->target = other.target;
		std::cout << "ShrubberyCreationForm assign operator called\n";
	}
	else{
		std::cout << "ShrubberyCreationForm double assignation avoided\n";
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "ShrubberyCreationForm destructor called\n";
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const{
	AForm::execute(executor);
	
	std::string filename = target + "_shrubbery";
	std::ofstream	wfile(filename.c_str());
	if (wfile.is_open() == false){
		std::cerr << "Couldn't open the file\n";
		return ;
	}
	wfile		<< "    *           *                         *                          * \n"
				<< "       ^             *                                      *          \n"
				<< " ____/  \\______________________________________________________________\n"
				<< "       |                                                               \n"
				<< "                                                       ^               \n"
				<< "                                                     /   \\             \n"
				<< "                        ^                           /     \\            \n"
				<< "                      /   \\                         /     \\            \n"
				<< "                     /     \\                       /       \\           \n"
				<< "                    /       \\                     /         \\          \n"
				<< "                   /  w      \\               @_y      | |              \n"
				<< "                  /           \\                                        \n"
				<< "                 /w/ w w  w  \\w\\                                       \n"
				<< "                  /           \\                                        \n"
				<< "                 /   w         \\                                       \n"
				<< "                /     w         \\                                      \n"
				<< "               /              w  \\                                     \n"
				<< "              /                   \\                                    \n"
				<< "             /                     \\                                   \n"
				<< "            /w/  ww  w   w w  w  w\\w\\                                  \n"
				<< "             /                     \\                                   \n"
				<< "            /                       \\                                  \n"
				<< "           /   w                     \\                                 \n"
				<< "          /      w           w        \\                                \n"
				<< "         /        ww                   \\                               \n"
				<< "        /   w                     ww    \\             ASCII trees ;P   \n";
	wfile.close();
}