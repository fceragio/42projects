/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 00:45:57 by federico          #+#    #+#             */
/*   Updated: 2025/05/04 03:37:43 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat: public WrongAnimal{
public:
	WrongCat();

	WrongCat(const std::string& type);

	WrongCat(const WrongCat& other);

	WrongCat& operator=(const WrongCat& other);

	~WrongCat();

	void	makeSound() const;

};

#endif