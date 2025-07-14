/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 03:04:52 by federico          #+#    #+#             */
/*   Updated: 2025/04/25 08:56:31 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_HPP
# define HumanB_HPP

# include "Weapon.hpp"

class	HumanB{
private:
	std::string	name;
	Weapon	*weapon;

public:
	HumanB(const std::string &name);
	~HumanB();

	void	setWeapon(Weapon &weapon);

	void	attack();
};

#endif