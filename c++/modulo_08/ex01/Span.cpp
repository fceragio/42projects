/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 01:10:33 by federico          #+#    #+#             */
/*   Updated: 2025/05/15 04:49:19 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(10){
	std::cout << "Span default constructor called (N = " << N << ")\n";
}
Span::Span(unsigned int N) : N(N){
	std::cout << "Span parameter constructor called (N = " << N << ")\n";
}

Span::Span(const Span& other) : N(other.N){
	this->content = other.content;
	std::cout << "Span copy constructor called (N = " << N << ")\n";
}

Span&	Span::operator=(const Span& other){
	if (this != &other){
		this->N = other.N;
		this->content = other.content;
	}
	else{
		std::cout << "Span double asignment avoided\n";
	}
	return *this;
}

Span::~Span(){
	std::cout << "Span destructor called\n";
}

void	Span::addNumber(int n){
	if (N <= this->content.size()){
		throw std::runtime_error("Span ERROR: reached N!\n");
	}
	this->content.push_back(n);
}
unsigned int	Span::shortestSpan() const{
	if (this->content.size() <= 1){
		throw std::runtime_error("Span ERROR: not enough elements for shortestSpan search!\n");
	}
	std::vector<int> sorted_copy = content;
	std::sort(sorted_copy.begin(), sorted_copy.end());
	unsigned int	shortest = static_cast<unsigned int>(sorted_copy[1] - sorted_copy[0]);
	for (unsigned int i = 1; i < sorted_copy.size() - 1; ++i){
		unsigned int	temp = static_cast<unsigned int>(sorted_copy[i + 1] - sorted_copy[i]);
		if (temp < shortest){
			shortest = temp;
		}
	}
	return shortest;
}
unsigned int	Span::longestSpan() const{
	if (this->content.size() <= 1){
		throw std::runtime_error("Span ERROR: not enough elements for longestSpan serach!\n");
	}
	int	max = *(std::max_element(content.begin(), content.end()));
	int min = *(std::min_element(content.begin(), content.end()));
	unsigned int	result = static_cast<unsigned int>(max - min);
	return result;
}
