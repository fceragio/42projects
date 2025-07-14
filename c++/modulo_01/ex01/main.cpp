/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:40:13 by federico          #+#    #+#             */
/*   Updated: 2025/04/25 01:15:49 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
	int	n = 10;
	std::string zombies_names = "Zoomer";
	Zombie	*zombie_horde = zombieHorde(n, zombies_names);

	for(int i = 0; i < n; i++){
		zombie_horde[i].announce();
	}
	delete[] zombie_horde;
	
	return 0;
}
