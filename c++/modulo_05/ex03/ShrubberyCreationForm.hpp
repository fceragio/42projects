/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 05:38:33 by federico          #+#    #+#             */
/*   Updated: 2025/05/08 05:48:42 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm{
private:
	std::string	target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);

	ShrubberyCreationForm(const ShrubberyCreationForm& other);

	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

	~ShrubberyCreationForm();

	void	execute(const Bureaucrat& executor) const;
};

#endif