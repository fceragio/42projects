/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_file_strings.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 05:30:21 by federico          #+#    #+#             */
/*   Updated: 2025/04/28 04:01:41 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

bool	replace_file_strings(std::ifstream &r_file,
							std::ofstream &w_file,
							std::string &old_str,
							std::string &new_str){
	char		buffer[MAX_READ + 1];
	std::string	str_buffer;
	std::string	leftover;

	while(r_file.read(buffer, old_str.length() * 2) || r_file.gcount() > 0){
		buffer[r_file.gcount()] = '\0';
		size_t pos = 0;
		size_t bookmark = 0;
		DEBUG("buffer-> ", buffer);
		str_buffer = leftover + buffer;
		DEBUG("str_buffer-> ", str_buffer);
		while ((bookmark = str_buffer.find(old_str, pos)) != std::string::npos){
			w_file.write(str_buffer.c_str() + pos, bookmark - pos);
			DEBUG("writing-> ", str_buffer.substr(pos, bookmark - pos));
			w_file << new_str;
			DEBUG("writing-> ", new_str);
			pos = bookmark + old_str.length();
		}
		leftover = str_buffer.substr(pos);
		DEBUG("leftover-> ", leftover);
		if (leftover.length() > old_str.length()){
			w_file.write(leftover.c_str(), leftover.length() - old_str.length());
			DEBUG("writing-> ", leftover.substr(0, leftover.length() - old_str.length()));
			leftover.erase(0, leftover.length() - old_str.length());
			DEBUG("new-leftover-> ", leftover);
		}
		std::fill(buffer, buffer + MAX_READ + 1, 0);
	}
	if (leftover.empty() == false){
		w_file << leftover;
		DEBUG("writing final leftover-> ", leftover);
	}
	DEBUG("buffer left clean-> ", buffer);
	
	if (r_file.bad() || w_file.bad()){
		return false;
	}
	return true;
}

bool	replace_with_empty(std::ifstream &r_file,
							std::ofstream &w_file,
							std::string &new_str){
	char		buffer[MAX_READ + 1];
	std::string	str_buffer;
	std::string	leftover;

	while(r_file.read(buffer, MAX_READ) || r_file.gcount() > 0){
		buffer[r_file.gcount()] = '\0';
		size_t pos = 0;
		size_t bookmark = r_file.gcount();
		DEBUG("buffer-> ", buffer);
		str_buffer = leftover + buffer;
		DEBUG("str_buffer-> ", str_buffer);
		while (bookmark > pos){
			w_file.write(str_buffer.c_str() + pos, 1);
			DEBUG("writing-> ", str_buffer[pos]);
			w_file << new_str;
			DEBUG("writing-> ", new_str);
			pos++;
		}
		leftover = str_buffer.substr(pos);
		DEBUG("leftover-> ", leftover);
		std::fill(buffer, buffer + MAX_READ + 1, 0);
	}
	DEBUG("final leftover-> ", leftover);
	DEBUG("buffer left clean-> ", buffer);
	
	if (r_file.bad() || w_file.bad()){
		return false;
	}	
	return true;
}
