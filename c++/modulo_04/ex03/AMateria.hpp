/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 02:41:23 by federico          #+#    #+#             */
/*   Updated: 2025/05/06 04:45:51 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class	AMateria{
protected:
	std::string type;
	bool		equipped;

public:
	AMateria();
	AMateria(const std::string& type);

	AMateria(const AMateria& other);

	virtual		~AMateria();

	const std::string&	getType() const;
	bool				getEquipped() const;

	void				setEquipped(const bool flag);

	virtual	AMateria&	operator=(const AMateria& other);
	virtual	AMateria*	clone() const = 0;
	virtual	void		use(ICharacter& target);
};

#endif