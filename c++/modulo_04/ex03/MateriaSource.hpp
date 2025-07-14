/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 05:48:16 by federico          #+#    #+#             */
/*   Updated: 2025/05/06 06:44:54 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# define MTSRC_LIMIT 4

# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class	MateriaSource: public IMateriaSource{
private:
	AMateria*	knownMateria[MTSRC_LIMIT];

public:
	MateriaSource();
	MateriaSource(AMateria* first);

	MateriaSource(const MateriaSource& other);

	MateriaSource& operator=(const MateriaSource& other);

	~MateriaSource();

	void	learnMateria(AMateria* toLearn);
	AMateria*	createMateria(const std::string& type);
};

#endif