/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:34:25 by federico          #+#    #+#             */
/*   Updated: 2025/04/25 02:23:03 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "memory address of the string variable-> " << &str << std::endl;
	std::cout << "memory address held by the string pointer-> " << stringPTR << std::endl;
	std::cout << "memory address held by the string reference-> " << &stringREF << std::endl;

	std::cout << "The value of the string variable-> " << str << std::endl;
	std::cout << "The value pointed by stringPTR-> " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF-> " << stringREF << std::endl;

	return 0;
}
