/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:36:30 by federico          #+#    #+#             */
/*   Updated: 2025/05/05 02:03:51 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal{
protected:
	std::string	type;

public:
	Animal();
	Animal(const std::string& type);

	Animal(const Animal& other);

	Animal&	operator=(const Animal& other);
	
	virtual ~Animal();

	const std::string&	getType() const;

	void				setType(const std::string& type);

	virtual void		makeSound() const;
};

#endif