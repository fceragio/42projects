/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:42:54 by federico          #+#    #+#             */
/*   Updated: 2025/05/07 09:44:38 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
	Bureaucrat* B1 = NULL;
	Bureaucrat* B2 = NULL;
	Bureaucrat* B3 = NULL;
	try{
		B1 = new Bureaucrat("B1", 150);
	}
	catch (std::exception& e){
		std::cerr << "ERROR DETECTED: " << e.what() << std::endl;
	}
		try{
		B2 = new Bureaucrat("B2", 112);
	}
	catch (std::exception& e){
		std::cerr << "ERROR DETECTED: " << e.what() << std::endl;
	}
		try{
		B3 = new Bureaucrat("B3", 1);
	}
	catch (std::exception& e){
		std::cerr << "ERROR DETECTED: " << e.what() << std::endl;
	}
	std::cout << '\n';

	if (!B1 || !B2 || !B3){
		if (B1) delete B1;
		if (B2) delete B2;
		if (B3) delete B3;
		std::cout << '\n';

		std::cerr << "CRITICAL ERROR: One or more failed creations. Stopping execution\n";
		std::cout << std::endl;
		return 1;
	}
	std::cout << *B2 << *B1 << *B3;
	std::cout << '\n';

	*B2 = *B1;
	std::cout << '\n';

	try{
		B2->downGrade();
	}
	catch (std::exception& e){
		std::cerr << "ERROR DETECTED: " << e.what() << std::endl;
	}
	std::cout << *B2;
	std::cout << '\n';

	*B2 = *B3;
	std::cout << '\n';

	try{
		B2->upGrade();
	}
	catch (std::exception& e){
		std::cerr << "ERROR DETECTED: " << e.what() << std::endl;
	}
	std::cout << *B2;
	std::cout << '\n';

	B1->upGrade();
	B3->downGrade();
	std::cout << *B1 << *B3;
	std::cout << '\n';

	if (B1)	delete B1;
	if (B2) delete B2;
	if (B3) delete B3;
	
	std::cout << std::endl;
	
	return 0;
}
