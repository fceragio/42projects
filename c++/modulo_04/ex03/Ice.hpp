/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 00:55:38 by federico          #+#    #+#             */
/*   Updated: 2025/05/06 01:01:13 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class	Ice : public AMateria{
public:
	Ice();
	Ice(const std::string& type);

	Ice(const Ice& other);

	Ice& operator=(const Ice& other);

	~Ice();

	AMateria*	clone() const;
};

#endif