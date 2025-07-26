#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void testDeepCopy()
{
	std::cout << "\n----- DEEP COPY TEST -----\n" << std::endl;

	Cat* originalCat = new Cat();
	originalCat->getBrain()->setIdea(0, "I want to catch mice");
	originalCat->getBrain()->setIdea(1, "I want to sleep");

	Cat* copyCat = new Cat(*originalCat);

	std::cout << "Original cat idea[0]: " << originalCat->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy cat idea[0]: " << copyCat->getBrain()->getIdea(0) << std::endl;

	copyCat->getBrain()->setIdea(0, "I want to play with yarn");

	std::cout << "\nAfter modifying the copy:" << std::endl;
	std::cout << "Original cat idea[0]: " << originalCat->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy cat idea[0]: " << copyCat->getBrain()->getIdea(0) << std::endl;

	delete originalCat;
	delete copyCat;
}

int main()
{
	std::cout << "\n----- ABSTRACT CLASS TEST -----\n" << std::endl;
	std::cout << "Trying to create Animal object..." << std::endl;
	std::cout << "Animal class is abstract, so it cannot be instantiated." << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\nJ Type: " << j->getType() << std::endl;
	std::cout << "I Type: " << i->getType() << std::endl;

	std::cout << "\nCat sound: ";
	i->makeSound();
	std::cout << "Dog sound: ";
	j->makeSound();

	delete j;
	delete i;

	const int animalCount = 4;
	Animal* animals[animalCount];

	std::cout << "\n----- CREATING ANIMALS -----\n" << std::endl;
	int k = 0;
	while (k < animalCount)
	{
		if (k < animalCount / 2)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
		k++;
	}

	std::cout << "\n----- ANIMAL SOUNDS -----\n" << std::endl;
	int a = 0;
	while (a < animalCount)
	{
		std::cout << "Animal " << a << " (" << animals[a]->getType() << "): ";
		animals[a]->makeSound();
		a++;
	}

	std::cout << "\n----- DELETING ANIMALS -----\n" << std::endl;
	int b = 0;
	while (b < animalCount)
	{
		delete animals[b];
		b++;
	}
	testDeepCopy();
	return 0;
}
