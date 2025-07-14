/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:42:54 by federico          #+#    #+#             */
/*   Updated: 2025/05/08 00:46:40 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(){
	Bureaucrat* B1 = NULL;
	try {
		B1 = new Bureaucrat("Jim", 12);
	}
	catch (std::exception& e){
		std::cerr << "Bureaucrat ERROR: " << e.what() << '\n';
		return 1;
	}
	std::cout << '\n';

	Form*	F1 = NULL;
	try {
		F1 = new Form("F1_Form", 31, 2);
	}
	catch (std::exception& e){
		std::cerr << "Form ERROR: " << e.what() << '\n';
	}
	std::cout << '\n';

	std::cout << *B1 << *F1;
	std::cout << '\n';
	
	B1->signForm(*F1);
	std::cout << *F1;

	std::cout << '\n';
	delete B1;
	delete F1;
	std::cout << std::endl;

	return 0;
}
