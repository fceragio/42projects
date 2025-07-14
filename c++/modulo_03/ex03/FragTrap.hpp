/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 04:17:08 by federico          #+#    #+#             */
/*   Updated: 2025/05/03 06:24:54 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap{
public:
	FragTrap();
	FragTrap(const std::string Name);

	FragTrap(const FragTrap& other);

	FragTrap& operator=(const FragTrap& other);

	~FragTrap();

	void	highFiveGuys();
};

#endif