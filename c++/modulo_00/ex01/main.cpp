/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 02:07:58 by federico          #+#    #+#             */
/*   Updated: 2025/04/27 08:24:50 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(){
	PhoneBook	phone_book;
	std::string	user_input;
	int			command;

	while (1){
		initial_menu();
		user_input = get_user_input();
		command = translate_input(user_input);
		switch (command){
		case NON_VALID:
			std::cout << "\' " << user_input << " \'" << " is not a valid command" << std::endl;
			break;
		case ADD:
			adding(phone_book);
			break;
		case SEARCH:
			searching(phone_book);
			break;
		case EXIT:
			return 0;
		}
	}
	
	return 1;
}

void	initial_menu(){
	std::cout << "\nWelcome\n" << "Phonebook available actions:\n";
	std::cout << "ADD\tto add a new contact\n";
	std::cout << "SEARCH\tto browse all the contacts\n";
	std::cout << "EXIT\tto close this program\n";	
}

std::string get_user_input(){
	std::string	user_input;

	std::getline(std::cin, user_input);
	user_input = take_first_word(user_input);

	return user_input;
}

std::string get_new_entry(){
	std::string	user_input;

	std::getline(std::cin, user_input);
	user_input = trim_extra_spaces(user_input);

	return user_input;
}

int	translate_input(const std::string &user_input){
	if (user_input.compare("EXIT") == 0){
		return EXIT;
	}
	else if (user_input.compare("SEARCH") == 0){
		return SEARCH;
	}
	else if (user_input.compare("ADD") == 0){
		return ADD;
	}
	else{
		return NON_VALID;
	}
}

void	adding(PhoneBook &phone_book){
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	while(1){
		std::cout << "insert the first name of your new contact:\n";
		first_name = get_new_entry();
		if (first_name.empty() == true){
			std::cout << "this field can not be empty\n";
		}
		else{
			break;
		}
	}
	while(1){
		std::cout << "insert the last name of your new contact:\n";
		last_name = get_new_entry();
		if (last_name.empty() == true){
			std::cout << "this field can not be empty\n";
		}
		else{
			break;
		}
	}
	while(1){
		std::cout << "insert the nickname of your new contact:\n";
		nickname = get_new_entry();
		if (nickname.empty() == true){
			std::cout << "this field can not be empty\n";
		}
		else{
			break;
		}
	}
	while(1){
		std::cout << "insert the phone number of your new contact:\n";
		phone_number = get_new_entry();
		if (phone_number.empty() == true){
			std::cout << "this field can not be empty\n";
		}
		else{
			break;
		}
	}
	while(1){
		std::cout << "insert the darkest secret of your new contact:\n";
		darkest_secret = get_new_entry();
		if (darkest_secret.empty() == true){
			std::cout << "this field can not be empty\n";
		}
		else{
			break;
		}
	}
	phone_book.set_contact(first_name, last_name, nickname, phone_number, darkest_secret);
	std::cout << "contact successfully added" << std::endl;
}

void	searching(const PhoneBook &phone_book){
	size_t		index;
	std::string	user_input;
	
	phone_book.show_all();
	std::cout << "insert the index of the contact you were looking for: ";
	user_input = get_user_input();
	if (user_input.empty() == true || str_isdigit(user_input) == false){
		std::cout << "\' " << user_input << " \'" << " is not a valid index" << std::endl;
		return;
	}
	std::stringstream ss(user_input);
	ss >> index;
	if (ss.fail() == true){
		std::cerr << "stringstream conversion failed" << std::endl;
		return;
	}
	if (index <= 0 || index > MAX_CONT){
		std::cout << "\' " << user_input << " \'" << " is not a valid index" << std::endl;
		return;
	}
	if (phone_book.get_contact_status(index - 1) == true){
		phone_book.show_one(index - 1);
	}
	else{
		std::cout << "this contact is yet to be set" << std::endl;
	}
}