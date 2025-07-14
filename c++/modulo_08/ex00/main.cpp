/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 05:22:28 by federico          #+#    #+#             */
/*   Updated: 2025/05/14 05:48:52 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"


int main(){
	int					size = 10;
	int					arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int>	vec(0, 0);
	std::deque<int>		deq(0, 0);
	std::list<int>		lst(0, 0);

	for (int i = 0; i < size; i++){
		vec.push_back(arr[i]);
		deq.push_back(arr[i]);
		lst.push_back(arr[i]);
	}
	for (int i = 0; i < size; i++){
		std::cout << "vec-> " << vec[i] << '\n';
	}
	for (int i = 0; i < size; i++){
		std::cout << "deq-> " << deq[i] << '\n';
	}
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it){
		std::cout << "lst-> " << *it << '\n';
	}
	std::cout << '\n';

	int	target;

	target = 3;
	try{
		std::cout << "Trying easyfind(vec, " << target << ")-> " << *(easyfind(vec, target)) << '\n';
	}
	catch (std::exception& e){
		std::cerr << "(vec) " << e.what() << '\n';
	}
	try{
		std::cout << "Trying easyfind(deq, " << target << ")-> " << *(easyfind(deq, target)) << '\n';
	}
	catch (std::exception& e){
		std::cerr << "(deq) " << e.what() << '\n';
	}
	try{
		std::cout << "Trying easyfind(lst, " << target << ")-> " << *(easyfind(lst, target)) << '\n';
	}
	catch (std::exception& e){
		std::cerr << "(lst) " << e.what() << '\n';
	}
	std::cout << '\n';
	
	target = 10;
	try{
		std::cout << "Trying easyfind(vec, " << target << ")-> " << *(easyfind(vec, target)) << '\n';
	}
	catch (std::exception& e){
		std::cerr << "(vec) " << e.what() << '\n';
	}
	try{
		std::cout << "Trying easyfind(deq, " << target << ")-> " << *(easyfind(deq, target)) << '\n';
	}
	catch (std::exception& e){
		std::cerr << "(deq) " << e.what() << '\n';
	}
	try{
		std::cout << "Trying easyfind(lst, " << target << ")-> " << *(easyfind(lst, target)) << '\n';
	}
	catch (std::exception& e){
		std::cerr << "(lst) " << e.what() << '\n';
	}
	std::cout << '\n';
	
	target = 11;
	try{
		std::cout << "Trying easyfind(vec, " << target << ")-> " << *(easyfind(vec, target)) << '\n';
	}
	catch (std::exception& e){
		std::cerr << "(vec) " << e.what() << '\n';
	}
	try{
		std::cout << "Trying easyfind(deq, " << target << ")-> " << *(easyfind(deq, target)) << '\n';
	}
	catch (std::exception& e){
		std::cerr << "(deq) " << e.what() << '\n';
	}
	try{
		std::cout << "Trying easyfind(lst, " << target << ")-> " << *(easyfind(lst, target)) << '\n';
	}
	catch (std::exception& e){
		std::cerr << "(lst) " << e.what() << '\n';
	}
	std::cout << '\n';
	
	return 0;
}



// int main(){
// 	int					size = 10;
// 	int					arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// 	std::vector<int>	vec(0, 0);
// 	std::deque<int>		deq(0, 0);
// 	std::list<int>		lst(0, 0);

// 	for (int i = 0; i < size; i++){
// 		vec.push_back(arr[i]);
// 		deq.push_back(arr[i]);
// 		lst.push_back(arr[i]);
// 	}
// 	for (int i = 0; i < size; i++){
// 		std::cout << "vec-> " << vec[i] << '\n';
// 	}
// 	for (int i = 0; i < size; i++){
// 		std::cout << "deq-> " << deq[i] << '\n';
// 	}
// 	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it){
// 		std::cout << "lst-> " << *it << '\n';
// 	}
// 	std::cout << '\n';

// 	int	target;

// 	try{
// 		target = 3;
// 		std::cout << "target-> " << target << '\n';
// 		std::cout << "easyfind(vec), easyfind(deq), easyfind(lst) { " << *(easyfind(vec, target)) << ' ' << *(easyfind(deq, target)) << ' ' << *(easyfind(lst, target)) << " }\n";
// 		std::cout << '\n';

// 		target = 10;
// 		std::cout << "target-> " << target << '\n';
// 		std::cout << "easyfind(vec), easyfind(deq), easyfind(lst) { " << *(easyfind(vec, target)) << ' ' << *(easyfind(deq, target)) << ' ' << *(easyfind(lst, target)) << " }\n";
// 		std::cout << '\n';	

// 		target = 11;
// 		std::cout << "target-> " << target << '\n';
// 		std::cout << "easyfind(vec), easyfind(deq), easyfind(lst) { " << *(easyfind(vec, target)) << ' ' << *(easyfind(deq, target)) << ' ' << *(easyfind(lst, target)) << " }\n";
// 		std::cout << '\n';
// 	}
// 	catch (std::exception& e){
// 		std::cerr << e.what() << '\n';
// 	}
	
// 	return 0;
// }
