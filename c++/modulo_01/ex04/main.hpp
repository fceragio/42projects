/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:06:21 by federico          #+#    #+#             */
/*   Updated: 2025/04/28 04:01:55 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# ifndef DEBUG
#  define DEBUG(x, y)
# else
#  define DEBUG(x, y) std::cout << x << y << std::endl;
# endif

# include <iostream>
# include <string>
# include <cstring>
# include <fstream>

# define MAX_READ 4096
# define W_FILE_SUFFIX ".replace"

bool	replace_file_strings(std::ifstream &r_file,
							std::ofstream &w_file,
							std::string &old_str,
							std::string &new_str);

bool	replace_with_empty(std::ifstream &r_file,
							std::ofstream &w_file,
							std::string &new_str);

#endif