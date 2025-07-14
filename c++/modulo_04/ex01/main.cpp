/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:35:25 by federico          #+#    #+#             */
/*   Updated: 2025/05/05 02:15:16 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


int main(){
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;

	return 0;
}


// int main(){
// 	Animal animal1;
// 	Animal animal2("another_generic_type");
// 	Animal animal3;

// 	animal3 = animal1;

// 	std::cout << '\n';
// 	animal1.makeSound();
// 	animal2.makeSound();
// 	animal3.makeSound();

// 	std::cout << '\n';
// 	Cat	cat1;
// 	Animal*	cat2 = new Cat();
// 	Animal	cat3;
// 	cat3 = cat1;

// 	std::cout << '\n';
// 	cat1.makeSound();
// 	cat2->makeSound();
// 	cat3.makeSound();

// 	std::cout << '\n';
// 	Dog		dog1;
// 	Animal*	dog2 = new Dog();
// 	Animal	dog3;
// 	dog3 = dog1;

// 	std::cout << '\n';
// 	dog1.makeSound();
// 	dog2->makeSound();
// 	dog3.makeSound();

// 	std::cout << '\n';
// 	delete cat2;
// 	delete dog2;

// 	std::cout << std::endl;

// 	return 0;
// }

// int main(){
// 	Dog	d1;
// 	Dog d2;

// 	std::cout << '\n';
// 	d1.getBrain()->setIdea(0, "d1 original idea");
// 	std::cout << d1.getBrain()->getIdea(0) << '\n';
// 	std::cout << d2.getBrain()->getIdea(0) << '\n';

// 	std::cout << '\n';
// 	d2 = d1;
// 	std::cout << d1.getBrain()->getIdea(0) << '\n';
// 	std::cout << d2.getBrain()->getIdea(0) << '\n';

// 	std::cout << '\n';
// 	Dog d3(d2);
// 	std::cout << d3.getBrain()->getIdea(0) << '\n';

// 	std::cout << '\n';
// 	Cat c1;
// 	Cat c2;

// 	std::cout << '\n';
// 	c1.getBrain()->setIdea(0, "c1 original idea");
// 	std::cout << c1.getBrain()->getIdea(0) << '\n';
// 	std::cout << c2.getBrain()->getIdea(0) << '\n';

// 	std::cout << '\n';
// 	c2 = c1;
// 	std::cout << c1.getBrain()->getIdea(0) << '\n';
// 	std::cout << c2.getBrain()->getIdea(0) << '\n';

// 	std::cout << '\n';
// 	Cat c3(c2);
// 	std::cout << c3.getBrain()->getIdea(0) << '\n';

// 	return 0;
// }

// int main(){
// 	Animal*	animals[20];

// 	for(int i = 0; i < 20; i++){
// 		if (i % 2){
// 			animals[i] = new Cat();
// 		}
// 		else{
// 			animals[i] = new Dog();
// 		}
// 	}
	
// 	for(int i = 0; i < 20; i++){
// 		delete animals[i];
// 	}

// 	return 0;
// }