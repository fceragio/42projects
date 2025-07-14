/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:06:03 by federico          #+#    #+#             */
/*   Updated: 2025/04/25 00:58:12 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie{
private:
	std::string	name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	
	void	announce(void);
	void	set_name(const std::string);
};

Zombie	*zombieHorde(int N, std::string name);

#endif