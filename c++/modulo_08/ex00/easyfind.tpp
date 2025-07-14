/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 05:36:42 by federico          #+#    #+#             */
/*   Updated: 2025/05/14 05:24:55 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::iterator	easyfind(T& container, int target){
	typename T::iterator iter = std::find(container.begin(), container.end(), target);
	if (iter == container.end()){
		throw std::runtime_error("easyfind() ERROR: couldn't find target!\n");
	}
	return iter;
}

template <typename T>
typename T::const_iterator	easyfind(const T& container,  int target){
	typename T::const_iterator iter = std::find(container.begin(), container.end(), target);
	if (iter == container.end()){
		throw std::runtime_error("easyfind() ERROR: couldn't find target!\n");
	}
	return iter;
}
