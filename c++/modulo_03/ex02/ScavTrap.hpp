/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 03:04:40 by federico          #+#    #+#             */
/*   Updated: 2025/05/03 04:08:30 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <climits>
# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap{
public:
	ScavTrap();
	ScavTrap(const std::string& Name);

	ScavTrap(const ScavTrap& other);

	ScavTrap& operator=(const ScavTrap& other);

	~ScavTrap();

	void	attack(const std::string& target);

	void	guardGate();
};

#endif