/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 03:18:19 by federico          #+#    #+#             */
/*   Updated: 2025/04/25 08:59:31 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

// int main(){
// 	Weapon	weapon("hammer");
// 	HumanA	human_a("Alan", weapon);
// 	HumanB	human_b("Bob");

// 	human_b.attack();
// 	human_b.setWeapon(weapon);
// 	human_b.attack();
// 	human_a.attack();
// 	weapon.setType("knife");
// 	human_b.attack();
// 	human_a.attack();

// 	return 0;
// }

int main()
{
{
Weapon club = Weapon("crude spiked club");
HumanA bob("Bob", club);
bob.attack();
club.setType("some other type of club");
bob.attack();
}
{
Weapon club = Weapon("crude spiked club");
HumanB jim("Jim");
jim.setWeapon(club);
jim.attack();
club.setType("some other type of club");
jim.attack();
}
return 0;
}
