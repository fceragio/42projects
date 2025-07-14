/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:57:57 by federico          #+#    #+#             */
/*   Updated: 2025/05/03 03:32:55 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <climits>

# define NAME "GenericDefaultName"
# define COST 1

class	ClapTrap{
private:
	std::string	Name;
	unsigned int	Hit_pts;
	unsigned int	Energy_pts;
	unsigned int	Attack_dmg;

public:
	ClapTrap();
	ClapTrap(const std::string& Name);

	ClapTrap(const ClapTrap& other);

	ClapTrap& operator=(const ClapTrap& other);
	
	~ClapTrap();

	std::string	getName()const;
	int			getHitPts()const;
	int			getEnergyPts()const;
	int			getAttackDmg()const;

	void		setName(const std::string& Name);
	void		setHitPts(const unsigned int Hit_pts);
	void		setEnergyPts(const unsigned int Energy_pts);
	void		setAttackDmg(const unsigned Attack_dmg);

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};

#endif
