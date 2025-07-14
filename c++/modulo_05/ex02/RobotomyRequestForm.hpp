/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:12:53 by federico          #+#    #+#             */
/*   Updated: 2025/05/08 04:55:20 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class	RobotomyRequestForm : public AForm{
private:
	std::string	target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);

	RobotomyRequestForm(const RobotomyRequestForm& other);

	RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);

	~RobotomyRequestForm();

	void	execute(const Bureaucrat& executor) const;
};

#endif

