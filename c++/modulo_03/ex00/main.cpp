/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:56:31 by federico          #+#    #+#             */
/*   Updated: 2025/05/01 09:45:14 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(){
	ClapTrap n1("N1");
	ClapTrap n2("N2");
	ClapTrap n3("N3");
	ClapTrap n1_spare(n1);
	ClapTrap n2_spare;
	n2_spare = n2;
	n2 = n2;

	std::cout << '\n';
	n1.attack("something");
	n1.attack("something");
	n1.attack("something");
	n1.attack("something");
	n1.attack("something");
	n1.attack("something");
	n1.attack("something");
	n1.attack("something");
	n1.attack("something");
	n1.attack("something");
	n1.attack("something");
	n1.attack("something");
	n1.attack("something");
	n1.attack("something");
	n1.beRepaired(5);
	n1.takeDamage(5);

	std::cout << '\n';
	n2.takeDamage(1);
	n2.takeDamage(3);
	n2.takeDamage(5);
	n2.takeDamage(1);
	n2.takeDamage(1);
	n2.takeDamage(100);
	n2.attack("something alse");
	n2.beRepaired(3);

	std::cout << '\n';
	n3.takeDamage(9);
	n3.beRepaired(1);
	n3.beRepaired(2);
	n3.beRepaired(5);
	n3.beRepaired(10);
	n3.beRepaired(100);
	n3.takeDamage(5);
	n3.beRepaired(1);
	n3.beRepaired(1);
	n3.attack("also something");
	std::cout << std::endl;

	return 0;
}
