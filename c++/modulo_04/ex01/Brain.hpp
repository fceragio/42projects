/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 07:49:36 by federico          #+#    #+#             */
/*   Updated: 2025/05/04 06:17:07 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class	Brain{
private:
	std::string	ideas[100];

public:
	Brain();
	Brain(const std::string& idea);

	Brain(const Brain& other);

	Brain& operator=(const Brain& other);

	~Brain();

	std::string	getIdea(const int index) const;

	void	setIdea(const int index, const std::string& idea);
};

#endif