#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "--- Animal Tests ---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;
    std::cout << "J Type: " << j->getType() << std::endl;
    std::cout << "I Type: " << i->getType() << std::endl;
    
    std::cout << std::endl;
    std::cout << "Cat sound: ";
    i->makeSound();
    std::cout << "Dog sound: ";
    j->makeSound();
    std::cout << "Animal sound: ";
    meta->makeSound();

    std::cout << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << std::endl << "--- Wrong Animal Tests ---" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << std::endl;
    std::cout << "WrongCat Type: " << wrongCat->getType() << std::endl;
    
    std::cout << std::endl;
    std::cout << "WrongCat sound (through WrongAnimal pointer): ";
    wrongCat->makeSound(); // This will call WrongAnimal::makeSound()
    std::cout << "WrongAnimal sound: ";
    wrongMeta->makeSound();

    std::cout << std::endl;
    // Direct call to WrongCat
    const WrongCat* directWrongCat = new WrongCat();
    std::cout << "Direct WrongCat sound: ";
    directWrongCat->makeSound(); // This calls WrongCat::makeSound directly

    std::cout << std::endl;
    delete wrongMeta;
    delete wrongCat;
    delete directWrongCat;

    return 0;
} 