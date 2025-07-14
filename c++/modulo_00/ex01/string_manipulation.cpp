/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manipulation.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 00:33:03 by federico          #+#    #+#             */
/*   Updated: 2025/04/24 20:38:12 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

std::string trim_extra_spaces(const std::string &str, const std::string &white_spaces){
	size_t	begin = str.find_first_not_of(white_spaces);
	if (begin == std::string::npos){
		return "";
	}
	size_t	end = str.find_last_not_of(white_spaces);
	return str.substr(begin, end - begin + 1);
}

std::string	take_first_word(const std::string &str, const std::string &white_spaces){
	size_t begin = str.find_first_not_of(white_spaces);
	if (begin == std::string::npos){
		return "";
	}
	size_t	end = str.find_first_of(white_spaces, begin);
	return str.substr(begin, end - begin);
}

bool	str_isdigit(const std::string &str){
	for (long unsigned int i = 0; i < str.length(); i++){
		if (isdigit(str[i]) == false){
			return false;
		}
	}
	return true;
}
