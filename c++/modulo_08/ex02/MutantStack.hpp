/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 05:12:18 by federico          #+#    #+#             */
/*   Updated: 2025/05/17 02:13:59 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <vector>
# include <list>
# include <deque>


template <typename T, typename baseContainer = std::deque<T> >
class MutantStack : public std::stack<T, baseContainer>{
public:
	MutantStack();
	MutantStack(const MutantStack& other);

	MutantStack&	operator=(const MutantStack& other);

	~MutantStack();

	typedef	typename baseContainer::iterator		iterator;
	typedef typename baseContainer::const_iterator	const_iterator;

	iterator	begin();
	iterator 	end();

	const_iterator	begin() const;
	const_iterator	end() const;
};

# include "MutantStack.tpp"

#endif