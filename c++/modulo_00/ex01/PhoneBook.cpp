/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 02:47:06 by federico          #+#    #+#             */
/*   Updated: 2025/04/24 04:43:15 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(){
	for (int i = 0; i < MAX_CONT; i++){
		contact_list[i] = Contact();
	}
	bookmark = 0;
}

bool	PhoneBook::get_contact_status(const size_t index) const{
	return contact_list[index].get_set();
}

void	PhoneBook::set_contact(const std::string first_name,
							const std::string last_name,
							const std::string nickname,
							const std::string phone_number,
							const std::string darkest_secret){
	contact_list[bookmark].set_first_name(first_name);
	contact_list[bookmark].set_last_name(last_name);
	contact_list[bookmark].set_nickname(nickname);
	contact_list[bookmark].set_phone_number(phone_number);
	contact_list[bookmark].set_darkest_secret(darkest_secret);
	contact_list[bookmark].set_set(true);
	if (bookmark < MAX_CONT - 1){
		bookmark++;
	}
	else{
		bookmark = 0;
	}
}

void	PhoneBook::show_all() const{
	std::cout << std::setw(MAX_WIDTH) << "index" << '|';
	std::cout << std::setw(MAX_WIDTH) << "first name" << '|';
	std::cout << std::setw(MAX_WIDTH) << "last name" << '|';
	std::cout << std::setw(MAX_WIDTH) << "nickname" << '|';
	std::cout << std::endl;
	for (int i = 0; i < MAX_CONT; i++){
		std::cout << std::setw(MAX_WIDTH) << i + 1 << '|';
		if (contact_list[i].get_first_name().length() <= MAX_WIDTH){
			std::cout << std::setw(MAX_WIDTH) << contact_list[i].get_first_name() << '|';
		}
		else{
			std::cout << contact_list[i].get_first_name().substr(0, MAX_WIDTH - 1) << ".|";
		}
		if (contact_list[i].get_last_name().length() <= MAX_WIDTH){
			std::cout << std::setw(MAX_WIDTH) << contact_list[i].get_last_name() << '|';
		}
		else{
			std::cout << contact_list[i].get_last_name().substr(0, MAX_WIDTH - 1) << ".|";
		}
		if (contact_list[i].get_nickname().length() <= MAX_WIDTH){
			std::cout << std::setw(MAX_WIDTH) << contact_list[i].get_nickname() << std::endl;
		}
		else{
			std::cout << contact_list[i].get_nickname().substr(0, MAX_WIDTH - 1) << '.' << std::endl;
		}
	}
}
void	PhoneBook::show_one(const size_t index) const{
	std::cout << "first name: " << contact_list[index].get_first_name() << '\n';
	std::cout << "last name: " << contact_list[index].get_last_name() << '\n';
	std::cout << "nickname: " << contact_list[index].get_nickname() << '\n';
	std::cout << "phone number: " << contact_list[index].get_phone_number() << '\n';
	std::cout << "darkest secret: " << contact_list[index].get_darkest_secret() << std::endl;
}
