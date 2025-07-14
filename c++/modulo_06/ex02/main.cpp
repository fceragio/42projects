/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 03:20:13 by federico          #+#    #+#             */
/*   Updated: 2025/05/12 05:49:27 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(){
	Base*	random_object = generate();
	std::cout << '\n';

	identify(random_object);
	std::cout << '\n';

	identify(*random_object);
	std::cout << '\n';

	delete random_object;
	std::cout << '\n';

	return 0;
}


Base*	generate(void){
	static bool	seeded = false;
	if (seeded == false){
		srand(time(0));
		seeded = true;
	}

	int	random_index = std::rand() % 3;
	switch (random_index){
		case 0:
			return new A;
		case 1:
			return new B;
		default:
			return new C;
	}
}

void	identify(Base* p){
	if (dynamic_cast<A*>(p) != NULL){
		std::cout << "Pointer identify: A\n";
		return ;
	}
	if (dynamic_cast<B*>(p) != NULL){
		std::cout << "Pointer identify: B\n";
		return ;
	}
	if (dynamic_cast<C*>(p) != NULL){
		std::cout << "Pointer identify: C\n";
		return ;
	}
}

void	identify(Base& p){
	try{
		dynamic_cast<A&>(p);
		std::cout << "Reference identify: A\n";
	}
	catch (std::exception& e){
	}
		try{
		dynamic_cast<B&>(p);
		std::cout << "Reference identify: B\n";
	}
	catch (std::exception& e){
	}
		try{
		dynamic_cast<C&>(p);
		std::cout << "Reference identify: C\n";
	}
	catch (std::exception& e){
	}
}
