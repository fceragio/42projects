/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 00:47:38 by federico          #+#    #+#             */
/*   Updated: 2025/05/15 05:05:49 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}

// int main(){
// 	std::vector<int>	range;
// 	int					range_start = 1;
// 	int					range_end = range_start + 99999;

// 	for (int i = range_start; i <= range_end; i++){
// 		range.push_back(i);
// 	}

// 	Span	span1(100001);
// 	std::cout << '\n';

// 	try{
// 		span1.addNumber(range_start);
// 		std::cout << "Added " << range_start << '\n';
// 	}
// 	catch (std::exception& e){
// 		std::cerr << e.what() << '\n';
// 	}
// 	std::cout << '\n';

// 	try{
// 		span1.addRange(range.begin(), range.end());
// 	}
// 	catch (std::exception& e){
// 		std::cerr << e.what() << '\n';
// 	}
// 	std::cout << '\n';

// 	try{
// 		std::cout << "ShortestSpan-> " << span1.shortestSpan() << '\n';
// 	}
// 	catch (std::exception& e){
// 		std::cerr << e.what() << '\n';
// 	}
// 	try{
// 		std::cout << "LongestSpan-> " << span1.longestSpan() << '\n';
// 	}
// 	catch (std::exception& e){
// 		std::cerr << e.what() << '\n';
// 	}
// 	std::cout << '\n';

// 	return 0;
// }

// int main(){
// 	Span	test(5);

// 	test.addNumber(INT_MAX);
// 	test.addNumber(INT_MIN);
// 	test.addNumber(2);
// 	test.addNumber(-2);
// 	test.addNumber(100);

// 	std::cout << "short-> " << test.shortestSpan() << '\n';
// 	std::cout << "long-> " << test.longestSpan() << '\n';
// 	std::cout << '\n';

// 	return 0;
// }
