/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 01:02:31 by federico          #+#    #+#             */
/*   Updated: 2025/05/15 04:30:39 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <cmath>
# include <climits>

class	Span{
private:
	std::vector<int>		content;
	unsigned int			N;
public:
	Span();
	Span(unsigned int N);

	Span(const Span& other);

	Span&	operator=(const Span& other);

	~Span();

	void	addNumber(int n);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	template <typename I>
	void	addRange(I begin, I end);
};

# include "Span.tpp"

#endif