/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:04:57 by federico          #+#    #+#             */
/*   Updated: 2025/04/28 04:02:32 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char **argv){
	if (argc != 4){
		std::cerr << "ERROR: wrong number of arguments!" << std::endl;
		return 1;
	}
	
	std::string	r_file_name = argv[1];
	std::ifstream	r_file;
	r_file.open(r_file_name.c_str());
	if (r_file.fail()){
		std::cerr << "ERROR: could not open the read_file!" << std::endl;
		return 2;
	}

	std::string	w_file_name = r_file_name + W_FILE_SUFFIX;
	std::ofstream	w_file;
	w_file.open(w_file_name.c_str());
	if (w_file.fail()){
		std::cerr << "ERROR: could not open the write_file!" << std::endl;
		r_file.close();
		return 3;
	}

	std::string	old_str = argv[2];
	std::string	new_str = argv[3];

	if (old_str.length() > MAX_READ / 2 || new_str.length() > MAX_READ / 2){
		std::cerr << "Sorry, strings over " << MAX_READ / 2 << " characters long can not be handled" << std::endl;
		r_file.close();
		w_file.close();
		return 4;
	}

	if (old_str.empty()){
		if (replace_with_empty(r_file, w_file, new_str) == false){
			std::cerr << "ERROR: something went wrong while reading/writing" << std::endl;
			r_file.close();
			w_file.close();
			return 5;
		}
	}
	else{
		if (replace_file_strings(r_file, w_file, old_str, new_str) == false){
			std::cerr << "ERROR: something went wrong while reading/writing" << std::endl;
			r_file.close();
			w_file.close();
			return 6;
		}
	}

	r_file.close();
	w_file.close();
	
	return 0;
}
