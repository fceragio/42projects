/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 06:13:41 by federico          #+#    #+#             */
/*   Updated: 2025/05/07 20:32:10 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm{
private:
	const std::string	name;
	bool				sign;
	const int			sn_grade;
	const int			ex_grade;

public:
	AForm();
	AForm(const std::string& name, int sn_grade, int ex_grade);

	AForm(const AForm& other);

	AForm&	operator=(const AForm& other);
	
	~AForm();

	const std::string&	getName() const;
	bool				getSign() const;
	int					getSnGrade() const;
	int					getExGrade() const;

	void				beSigned(const Bureaucrat& signer);

	class	GradeTooLowException : public std::exception{
	public:
		const char*	what() const throw();
	};
	class	GradeTooHighException : public std::exception{
	public:
		const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& stream, const AForm& form);

#endif