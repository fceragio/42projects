/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 00:41:49 by federico          #+#    #+#             */
/*   Updated: 2025/05/03 00:43:13 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal{
protected:
	std::string	type;

public:
	WrongAnimal();
	WrongAnimal(const std::string& type);

	WrongAnimal(const WrongAnimal& other);

	WrongAnimal&	operator=(const WrongAnimal& other);
	
	~WrongAnimal();

	const std::string&	getType() const;

	void				setType(const std::string& type);

	void				makeSound() const;
};

#endif