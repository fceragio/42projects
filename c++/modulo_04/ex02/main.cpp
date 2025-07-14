/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:35:25 by federico          #+#    #+#             */
/*   Updated: 2025/05/05 01:59:05 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


int main(){
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	delete j;
	delete i;

	return 0;
}


// int main(){
// 	std::cout << '\n';
// 	Cat	cat1;
// 	Animal*	cat2 = new Cat();

// 	std::cout << '\n';
// 	cat1.makeSound();
// 	cat2->makeSound();

// 	std::cout << '\n';
// 	Dog		dog1;
// 	Animal*	dog2 = new Dog();

// 	std::cout << '\n';
// 	dog1.makeSound();
// 	dog2->makeSound();

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

// int main(){
// 	Animal* dog = new Dog;
// 	Animal* cat = new Cat;
	
// 	std::cout << '\n';
// 	dog->getBrain()->getIdea(0);
// 	cat->getBrain()->getIdea(0);
	
// 	std::cout << '\n';
// 	dog->getBrain()->setIdea(0, "NEW DOG IDEA");
// 	cat->getBrain()->setIdea(0, "NEW CAT IDEA");

// 	std::cout << '\n';
// 	dog->getBrain()->getIdea(0);
// 	cat->getBrain()->getIdea(0);

// 	std::cout << '\n';
// 	Animal* d_copy = dog->clone();
// 	Animal* c_copy = cat->clone();

// 	std::cout << '\n';
// 	d_copy->getBrain()->getIdea(0);
// 	c_copy->getBrain()->getIdea(0);

// 	std::cout << '\n';
// 	delete dog;
// 	delete cat;
// 	delete d_copy;
// 	delete c_copy;
	
// 	std::cout << std::endl;

// 	return 0;
// }