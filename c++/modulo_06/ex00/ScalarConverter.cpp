/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 02:40:21 by federico          #+#    #+#             */
/*   Updated: 2025/05/11 06:55:29 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static std::string	trim_input(const std::string &str, const std::string &white_spaces = " \t"){
	size_t begin = str.find_first_not_of(white_spaces);
	if (begin == std::string::npos){
		return "";
	}
	size_t	end = str.find_last_not_of(white_spaces);
	return str.substr(begin, end - begin + 1);
}

static bool	input_is_pseudoliteral(const std::string& input){
	std::string	pseudoliterals[6] = {"+inf", "-inf", "nan", "+inff", "-inff", "nanf"};
	for (int i = 0; i < 6; i++){
		if (input == pseudoliterals[i]){
			return true;
		}
	}
	return false;	
}

static bool input_is_char(const std::string& input){
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\''){
		return true;
	}
	return false;
}

static bool input_is_float(const std::string& input){
	double	value = 0;
	char* end;
	value = strtod(input.c_str(), &end);
	static_cast<void>(value);
	if (input.length() > 1 && *end == 'f' && *(end + 1) == '\0'){
		return true;
	}
	return false;
}

static bool	input_is_numeric(const std::string& input){
	double	value = 0;
	char* end;
	value = strtod(input.c_str(), &end);
	static_cast<void>(value);
	if (*end == '\0'){
		return true;
	}
	return false;
}

static void	set_pseudoliteral_value(double* value, const std::string& input){
	if (input == "+inf" || input == "+inff"){
		*value = std::numeric_limits<double>::infinity();
	}
	else if (input == "-inf" || input == "-inff"){
		*value = -std::numeric_limits<double>::infinity();
	}
	else{
		*value = std::numeric_limits<double>::quiet_NaN();
	}
}

static void set_char_value(double* value, const std::string& input){
	*value = static_cast<double>(input[1]);
}

static void set_numeric_value(double* value, const std::string& input){
	char *end;
	*value = static_cast<double>(strtod(input.c_str(), &end));
}

static void	print_char(double value){
	if (value < 0 || value > 127 || std::isnan(value) || std::isinf(value)){
		std::cout << "char: impossible\n";
		return ;
	}
	char c = static_cast<char>(value);
	if (isprint(c)){
		std::cout << "char: \'" << c << "\'\n";
		return ;
	}
	std::cout << "char: Non displayable\n";
}

static void print_int(double value){
	if (value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max()
		|| std::isnan(value) || std::isinf(value)){
		std::cout << "int: impossible\n";
		return ;
	}
	std::cout << "int: " << static_cast<int>(value) << '\n';
}

static void print_float(double value){
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";
}

static void print_double(double value){
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << '\n';
}

static void	print_scalar_convertion(double value){
	print_char(value);
	print_int(value);
	print_float(value);
	print_double(value);
}

void	ScalarConverter::convert(const std::string& input_str){
	std::string	input = trim_input(input_str);
	if (input == ""){
		std::cerr << "ScalarConverter ERROR: invalid input\n";
		return ;
	}
	
	double	value = 0;
	if (input_is_pseudoliteral(input)){
		set_pseudoliteral_value(&value, input);
	}
	else if (input_is_char(input)){
		set_char_value(&value, input);
	}
	else if (input_is_float(input) || input_is_numeric(input)){
		set_numeric_value(&value, input);
	}
	else{
		std::cerr << "ScalarConverter ERROR: Invalid input\n";
		return ;
	}
	print_scalar_convertion(value);
}
