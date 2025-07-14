/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 01:42:12 by federico          #+#    #+#             */
/*   Updated: 2025/04/24 07:05:11 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <sstream>

# include "PhoneBook.hpp"
# include "Contact.hpp"

# define NON_VALID 0
# define ADD 1
# define SEARCH 2
# define EXIT 3

void		initial_menu();
std::string get_user_input();
int			translate_input(const std::string &user_input);
void		searching(const PhoneBook &phone_book);
void		adding(PhoneBook &phone_book);

std::string trim_extra_spaces(const std::string &str,
							const std::string &white_spaces = " \t");
std::string	take_first_word(const std::string &str,
							const std::string &white_spaces = " \t");
bool		str_isdigit(const std::string &str);

#endif
