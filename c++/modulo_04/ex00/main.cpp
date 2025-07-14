/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:35:25 by federico          #+#    #+#             */
/*   Updated: 2025/05/03 01:04:04 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main(){
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
	
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
	
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
	
// 	delete meta;
// 	delete j;
// 	delete i;

// 	return 0;
// }

// int main(){
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const WrongAnimal* i = new WrongCat();
	
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
	
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// 	delete meta;
// 	delete j;
// 	delete i;
	
// 	return 0;
// }

int main(){
	Animal animal1;
	Animal animal2("another_generic_type");
	Animal animal3;

	animal3 = animal1;

	std::cout << '\n';
	animal1.makeSound();
	animal2.makeSound();
	animal3.makeSound();

	std::cout << '\n';
	Cat	cat1;
	Animal*	cat2 = new Cat();
	Animal	cat3;
	cat3 = cat1;

	std::cout << '\n';
	cat1.makeSound();
	cat2->makeSound();
	cat3.makeSound();

	std::cout << '\n';
	Dog		dog1;
	Animal*	dog2 = new Dog();
	Animal	dog3;
	dog3 = dog1;

	std::cout << '\n';
	dog1.makeSound();
	dog2->makeSound();
	dog3.makeSound();

	std::cout << '\n';
	delete cat2;
	delete dog2;
	
	std::cout << '\n';
	WrongCat		wcat1;
	WrongAnimal*	wcat2 = new WrongCat();
	WrongAnimal		wcat3;
	wcat3 = wcat1;

	std::cout << '\n';
	wcat1.makeSound();
	wcat2->makeSound();
	wcat3.makeSound();

	std::cout << '\n';
	delete wcat2;

	std::cout << std::endl;

	return 0;
}
