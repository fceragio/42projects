/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 03:06:24 by federico          #+#    #+#             */
/*   Updated: 2025/04/25 07:56:05 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_HPP
# define HumanA_HPP

# include "Weapon.hpp"

class	HumanA{
private:
	std::string	name;
	Weapon	&weapon;

public:
	HumanA(const std::string &name, Weapon &weapon);
	~HumanA();

	void	attack();
};

#endif