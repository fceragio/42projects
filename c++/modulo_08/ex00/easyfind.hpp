/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 05:23:06 by federico          #+#    #+#             */
/*   Updated: 2025/05/14 05:51:36 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <list>
# include <vector>
# include <deque>

template <typename T>
typename T::iterator	easyfind(T& container, int target);

template <typename T>
typename T::const_iterator	easyfind(const T& container, int target);


# include "easyfind.tpp"

#endif