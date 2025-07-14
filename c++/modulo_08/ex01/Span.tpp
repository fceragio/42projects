/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 04:21:55 by federico          #+#    #+#             */
/*   Updated: 2025/05/15 05:02:25 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename I>
void	Span::addRange(I begin, I end){
	typename std::iterator_traits<I>::difference_type	total_length = std::distance(begin, end);
	if (total_length < 0){
		throw std::runtime_error("Span ERROR: addRange(begin > end) is undefined behavior!\n");
	}
	if (static_cast<size_t>(this->content.size() + total_length) > this->N){
		throw std::runtime_error("Span ERROR: range too big to be added!\n");
	}
	this->content.insert(this->content.end(), begin, end);
}
