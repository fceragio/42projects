/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:40:13 by federico          #+#    #+#             */
/*   Updated: 2025/04/24 20:32:57 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	Zombie *zombie1;

	zombie1 = newZombie("zombie1");
	randomChump("zombie2");
	
	delete zombie1;
	
	return 0;
}
