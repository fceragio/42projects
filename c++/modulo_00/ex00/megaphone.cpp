/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 03:34:43 by federico          #+#    #+#             */
/*   Updated: 2025/05/11 10:22:54 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

static std::string	trim_input(const std::string &str, const std::string &white_spaces = " \t"){
	size_t begin = str.find_first_not_of(white_spaces);
	if (begin == std::string::npos){
		return "";
	}
	size_t	end = str.find_last_not_of(white_spaces);
	return str.substr(begin, end - begin + 1);
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}

	std::string str[argc - 1];
	for (int i = 1; i < argc; i++){
		str[i - 1] = trim_input(argv[i]);
	}
	for (int i = 0; i < argc - 1; i++) {
		for (size_t j = 0; j < str[i].length(); ++j) {
			std::cout << (char)std::toupper((unsigned char)str[i][j]);
		}
		if (i < argc - 2)
			std::cout << ' ';
	}
	std::cout << std::endl;

	return 0;
}
