/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 00:35:33 by federico          #+#    #+#             */
/*   Updated: 2025/05/06 00:59:53 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class	Cure : public AMateria{
public:
	Cure();
	Cure(const std::string& type);

	Cure(const Cure& other);

	Cure& operator=(const Cure& other);

	~Cure();

	AMateria*	clone() const;
};

#endif