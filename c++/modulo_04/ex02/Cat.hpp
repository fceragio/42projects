/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:56:36 by federico          #+#    #+#             */
/*   Updated: 2025/05/05 01:39:51 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat: public Animal{
private:
	Brain*	catBrain;

public:
	Cat();

	Cat(const std::string& type);

	Cat(const Cat& other);

	Cat& operator=(const Cat& other);

	~Cat();

	void	makeSound() const;

	Brain*	getBrain() const;

	Animal*	clone();
};

#endif