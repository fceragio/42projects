/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 05:51:35 by federico          #+#    #+#             */
/*   Updated: 2025/05/04 03:27:22 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>

class Dog: public Animal{
public:
	Dog();

	Dog(const std::string& type);

	Dog(const Dog& other);

	Dog& operator=(const Dog& other);

	~Dog();

	void	makeSound() const;

};

#endif