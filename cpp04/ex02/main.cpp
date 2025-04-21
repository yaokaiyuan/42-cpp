/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:13:15 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/04/21 20:20:11 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	// animal meta to show only inherrite work
	std::cout << "=== Basic Sound Test ===" << std::endl;
	const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // will output the WrongAnimal sound!
    wrongMeta->makeSound();

    delete meta;
    delete j;
    delete i;
    delete wrongMeta;
    delete wrongCat;
    
	std::cout << "=== Basic Construction and Destruction Test ===" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    delete dog;
    delete cat;

    std::cout << "\n=== Array of Animals ===" << std::endl;
    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n=== Deleting Array of Animals ===" << std::endl;
    for (int i = 0; i < size; i++) {
        delete animals[i];
    }

    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    Dog originalDog;
    originalDog.setIdea(0, "Chase cats");
    originalDog.setIdea(1, "Eat treats");
	originalDog.setIdea(100, "run into full speed train");

    Dog copyDog = originalDog;
    copyDog.setIdea(0, "Sleep all day");

    std::cout << "Original Dog Idea 0: " << originalDog.getIdea(0) << std::endl;
	std::cout << "Original Dog Idea 1: " << originalDog.getIdea(1) << std::endl;
	std::cout << "Original Dog Idea 100: " << originalDog.getIdea(100) << std::endl;
    std::cout << "Copy Dog Idea 0: " << copyDog.getIdea(0) << std::endl;

    return 0;
}
