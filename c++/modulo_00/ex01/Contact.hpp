/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 02:43:03 by federico          #+#    #+#             */
/*   Updated: 2025/04/23 11:18:30 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact{
private:
	bool		set;
	std::string	first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact();
	Contact(const std::string &first_name,
			const std::string &last_name,
			const std::string &nickname,
			const std::string &phone_number,
			const std::string &darkest_secret
			);

	bool		get_set() const;
	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_nickname() const;
	std::string get_phone_number() const;
	std::string get_darkest_secret() const;
	
	void	set_set(const bool set);
	void	set_first_name(const std::string first_name);
	void	set_last_name(const std::string last_name);
	void	set_nickname(const std::string nickname);
	void	set_phone_number(const std::string phone_number);
	void	set_darkest_secret(const std::string darkest_secret);
};

#endif