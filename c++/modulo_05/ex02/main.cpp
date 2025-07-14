/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:42:54 by federico          #+#    #+#             */
/*   Updated: 2025/05/08 05:59:44 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"



/*PRESIDENTIALPARDONFORM TESTS*/

// int main(){
// 	Bureaucrat* B1 = NULL;
// 	try {
// 		B1 = new Bureaucrat("Jim", 6);
// 	}
// 	catch (std::exception& e){
// 		std::cerr << "Bureaucrat ERROR: " << e.what() << '\n';
// 		return 1;
// 	}
// 	std::cout << '\n';

// 	AForm*	F1 = NULL;
// 	try {
// 		F1 = new PresidentialPardonForm();
// 	}
// 	catch (std::exception& e){
// 		std::cerr << "AForm ERROR: " << e.what() << '\n';
// 	}
// 	std::cout << '\n';

// 	std::cout << *B1 << *F1;
// 	std::cout << '\n';
	
// 	B1->signForm(*F1);
// 	std::cout << *F1;

// 	B1->execForm(*F1);
// 	std::cout << '\n';

// 	std::cout << '\n';
// 	delete B1;
// 	delete F1;
// 	std::cout << std::endl;

// 	return 0;
// }



/*ROBOTOMIZATIONREQUESTFORM TESTS*/

// int main(){
// 	Bureaucrat* B1 = NULL;
// 	try {
// 		B1 = new Bureaucrat("Jim", 1);
// 	}
// 	catch (std::exception& e){
// 		std::cerr << "Bureaucrat ERROR: " << e.what() << '\n';
// 		return 1;
// 	}
// 	std::cout << '\n';

// 	AForm*	F1 = NULL;
// 	try {
// 		F1 = new RobotomyRequestForm();
// 	}
// 	catch (std::exception& e){
// 		std::cerr << "AForm ERROR: " << e.what() << '\n';
// 	}
// 	std::cout << '\n';

// 	std::cout << *B1 << '\n' << *F1 << '\n';
// 	std::cout << '\n';
	
// 	B1->signForm(*F1);
// 	std::cout << *F1;

// 	B1->execForm(*F1);
// 	std::cout << '\n';

// 	std::cout << '\n';
// 	delete B1;
// 	delete F1;
// 	std::cout << std::endl;

// 	return 0;
// }



/*SHRUBBERYCREATIONFORM TESTS*/

int main(){
	Bureaucrat* B1 = NULL;
	try {
		B1 = new Bureaucrat("Jim", 1);
	}
	catch (std::exception& e){
		std::cerr << "Bureaucrat ERROR: " << e.what() << '\n';
		return 1;
	}
	std::cout << '\n';

	AForm*	F1 = NULL;
	try {
		F1 = new ShrubberyCreationForm();
	}
	catch (std::exception& e){
		std::cerr << "AForm ERROR: " << e.what() << '\n';
	}
	std::cout << '\n';

	std::cout << *B1 << '\n' << *F1 << '\n';
	std::cout << '\n';
	
	B1->signForm(*F1);
	std::cout << *F1;

	B1->execForm(*F1);
	std::cout << '\n';

	std::cout << '\n';
	delete B1;
	delete F1;
	std::cout << std::endl;

	return 0;
}