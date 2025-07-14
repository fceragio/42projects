/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 02:46:41 by federico          #+#    #+#             */
/*   Updated: 2025/04/23 11:19:30 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
	:	first_name("EMPTY"),
		last_name("EMPTY"),
		nickname("EMPTY"),
		phone_number("EMPTY"),
		darkest_secret("EMPTY"){
	set = false;

}
Contact::Contact(const std::string &first_name,
			const std::string &last_name,
			const std::string &nickname,
			const std::string &phone_number,
			const std::string &darkest_secret)
	:	first_name(first_name),
		last_name(last_name),
		nickname(nickname),
		phone_number(phone_number),
		darkest_secret(darkest_secret){
	set = true;
}

bool		Contact::get_set() const{
	return set;
}
std::string Contact::get_first_name() const {
	return first_name;
}
std::string Contact::get_last_name() const {
	return last_name;
}
std::string Contact::get_nickname() const {
	return nickname;
}
std::string Contact::get_phone_number() const {
	return phone_number;
}
std::string Contact::get_darkest_secret() const {
	return darkest_secret;
}

void	Contact::set_set(const bool set){
	this->set = set;
}
void	Contact::set_first_name(const std::string first_name){
	this->first_name = first_name;
}
void	Contact::set_last_name(const std::string last_name){
	this->last_name = last_name;
}
void	Contact::set_nickname(const std::string nickname){
	this->nickname = nickname;
}
void	Contact::set_phone_number(const std::string phone_number){
	this->phone_number = phone_number;
}
void	Contact::set_darkest_secret(const std::string darkest_secret){
	this->darkest_secret = darkest_secret;
}
