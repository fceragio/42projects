/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 01:02:37 by federico          #+#    #+#             */
/*   Updated: 2025/05/08 04:55:29 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class	PresidentialPardonForm : public AForm{
private:
	std::string	target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);

	PresidentialPardonForm(const PresidentialPardonForm& other);

	PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

	~PresidentialPardonForm();

	void	execute(const Bureaucrat& executor) const;
};

#endif