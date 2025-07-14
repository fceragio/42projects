/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 05:12:20 by federico          #+#    #+#             */
/*   Updated: 2025/05/17 02:11:32 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T, typename baseContainer>
MutantStack<T, baseContainer>::MutantStack() : std::stack<T, baseContainer>(){
	std::cout << "MutantStack default contructor called\n";
}

template <typename T, typename baseContainer>
MutantStack<T, baseContainer>::MutantStack(const MutantStack& other) : std::stack<T, baseContainer>(other){
	std::cout << "MutantStack copy constructor called\n";
}

template <typename T, typename baseContainer>
MutantStack<T, baseContainer>&	MutantStack<T, baseContainer>::operator=(const MutantStack& other){
	if (this != &other){
		std::stack<T, baseContainer>::operator=(other);
		std::cout << "MutantStack assign operator called\n";
	}
	else{
		std::cout << "MutantStack double assignation ovided\n";
	}
	return *this;
}

template <typename T, typename baseContainer>
MutantStack<T, baseContainer>::~MutantStack(){
	std::cout << "MutantStack destructor called\n";
}


template <typename T, typename baseContainer>
typename MutantStack<T, baseContainer>::iterator	MutantStack<T, baseContainer>::begin(){
	return this->c.begin();
}
template <typename T, typename baseContainer>
typename MutantStack<T, baseContainer>::iterator	MutantStack<T, baseContainer>::end(){
	return this->c.end();
}

template <typename T, typename baseContainer>
typename MutantStack<T, baseContainer>::const_iterator	MutantStack<T, baseContainer>::begin() const{
	return this->c.begin();
}
template <typename T, typename baseContainer>
typename MutantStack<T, baseContainer>::const_iterator	MutantStack<T, baseContainer>::end() const{
	return this->c.end();
}