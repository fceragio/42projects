/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 05:51:26 by federico          #+#    #+#             */
/*   Updated: 2025/05/03 06:50:02 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap: public FragTrap, public ScavTrap{
private:
	std::string	Name;
public:
	DiamondTrap();
	DiamondTrap(const std::string& Name);

	DiamondTrap(const DiamondTrap& other);

	DiamondTrap&	operator=(const DiamondTrap& other);

	~DiamondTrap();

	void	whoAmI();

	using ScavTrap::attack;
	using ScavTrap::guardGate;
	using FragTrap::highFiveGuys;
};

#endif