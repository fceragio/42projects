/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 02:44:08 by federico          #+#    #+#             */
/*   Updated: 2025/05/08 03:17:31 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define TOP_GRD	1
# define BOTTOM_GRD 150

# include <iostream>
# include <exception>
# include "AForm.hpp"

class	AForm;

class	Bureaucrat{
private:
	const std::string	name;
	int					grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);

	Bureaucrat(const Bureaucrat& other);

	Bureaucrat&	operator=(const Bureaucrat& other);

	~Bureaucrat();

	const std::string	getName() const;
	int					getGrade() const;

	void				upGrade();
	void				downGrade();

	void				signForm(AForm& to_sign);
	void				execForm(AForm& to_exec);

	class	GradeTooHighException : public std::exception{
	public:
		const char* what() const throw();
	};
	class	GradeTooLowException : public std::exception{
	public:
		const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& brc);

#endif