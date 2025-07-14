/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 02:45:37 by federico          #+#    #+#             */
/*   Updated: 2025/05/13 04:27:44 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : elements(NULL), length(0){
	std::cout << "Array default constructor called\n";
}

template <typename T>
Array<T>::Array(size_t length) : elements(new T[length]()), length(length){
	std::cout << "Array parameter constructor called\n";
}

template <typename T>
Array<T>::Array(const Array& other) : elements(new T[other.length]()), length(other.length){
	for (size_t i = 0; i < length; i++){
		this->elements[i] = other.elements[i];
	}
	std::cout << "Array copy constructor called\n";
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other){
	if (this != &other){
		delete[] this->elements;
		this->length = other.length;
		this->elements = new T[other.length]();
		for (size_t i = 0; i < length; i++){
			this->elements[i] = other.elements[i];
		}
		std::cout << "Array assign operator called\n";
	}
	else{
		std::cout << "Array double assignation avoided\n";
	}
	return *this;
}

template <typename T>
Array<T>::~Array(){
	delete[] elements;
	std::cout << "Array destructor called\n";
}

template <typename T>
size_t	Array<T>::size() const{
	return length;
}

template <typename T>
T&	Array<T>::operator[](size_t index){
	if (index >= length){
		throw std::out_of_range("Array ERROR: index out of range!\n");
	}
	return elements[index];
}

template <typename T>
const T&	Array<T>::operator[](size_t index) const{
	if (index >= length){
		throw std::out_of_range("Array ERROR: index out of range!\n");
	}
	return elements[index];
}
