/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 06:57:12 by federico          #+#    #+#             */
/*   Updated: 2025/05/13 01:42:45 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(){
	double double_array[6] = {1.65, 12.0, 42.1, 64312, 13.13, 75.05};
	::iter(double_array, 6, ::print<double>);
	std::cout << '\n';

	int int_array[6] = {1, 12, 42, 64312, 13, 75};
	::iter(int_array, 6, ::print<int>);
	std::cout << '\n';

	std::string str_array[6] = {"hello", "how are", "you", "today?", "more strings!", "one last"};
	::iter(str_array, 6, ::print<std::string>);
	std::cout << '\n';

	const char *c_string = "these letters should be printed 1 by 1";
	::iter(c_string, strlen(c_string), ::print<char>);
	std::cout << '\n';

	return 0;
}
