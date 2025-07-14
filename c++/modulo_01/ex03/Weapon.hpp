/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 03:02:54 by federico          #+#    #+#             */
/*   Updated: 2025/04/25 08:04:45 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class	Weapon{
private:
	std::string	type;

public:
	Weapon(const std::string &type);
	~Weapon();

	const std::string	&getType();

	void	setType(std::string type);
};

#endif