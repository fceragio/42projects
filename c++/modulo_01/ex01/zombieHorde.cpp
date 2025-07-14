/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:46:49 by federico          #+#    #+#             */
/*   Updated: 2025/04/25 01:13:23 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name){
	if (N <= 0){
		return NULL;
	}
	
	Zombie	*zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++){
		zombieHorde[i].set_name(name);
	}

	return zombieHorde;
}
