/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 03:49:24 by federico          #+#    #+#             */
/*   Updated: 2025/05/06 09:48:26 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# define BASE_INV 4
# define FLOOR_SLOTS 10

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter{
protected:
	std::string	name;
	AMateria*	inventory[BASE_INV];
	AMateria*	onTheFloor[FLOOR_SLOTS];
public:
	Character();
	Character(const std::string& name);

	Character(const Character& other);

	Character&	operator=(const Character& other);

	~Character();

	const std::string& getName() const;
	
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
};

#endif