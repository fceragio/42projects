/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 02:44:42 by federico          #+#    #+#             */
/*   Updated: 2025/04/23 11:27:52 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONT	8
# define MAX_WIDTH	10

class PhoneBook{
private:
	Contact	contact_list[MAX_CONT];
	size_t	bookmark;

public:
	PhoneBook();

	bool	get_contact_status(const size_t index) const;

	void	set_contact(const std::string first_name,
						const std::string last_name,
						const std::string nickname,
						const std::string phone_number,
						const std::string darkest_secret);

	void	show_all() const;
	void	show_one(const size_t index) const;
};

#endif