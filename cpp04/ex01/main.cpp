#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void testDeepCopy() {
    std::cout << "\n----- DEEP COPY TEST -----\n" << std::endl;
    
    // Original cat
    Cat* originalCat = new Cat();
    // Set some ideas
    originalCat->getBrain()->setIdea(0, "I want to catch mice");
    originalCat->getBrain()->setIdea(1, "I want to sleep");
    
    // Create a copy using copy constructor
    Cat* copyCat = new Cat(*originalCat);
    
    // Show both cats have the same ideas
    std::cout << "Original cat idea[0]: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy cat idea[0]: " << copyCat->getBrain()->getIdea(0) << std::endl;
    
    // Modify copy cat's idea
    copyCat->getBrain()->setIdea(0, "I want to play with yarn");
    
    // Show that modifying the copy does not affect the original (Deep copy)
    std::cout << "\nAfter modifying the copy:" << std::endl;
    std::cout << "Original cat idea[0]: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy cat idea[0]: " << copyCat->getBrain()->getIdea(0) << std::endl;
    
    delete originalCat;
    delete copyCat;
}

int main() {
    // Basic tests
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j; // Should not create a leak
    delete i;
    
    // Array of animals
    const int animalCount = 10;
    Animal* animals[animalCount];
    
    // Fill the array with Dogs and Cats
    std::cout << "\n----- CREATING ANIMALS -----\n" << std::endl;
    for (int k = 0; k < animalCount; k++) {
        if (k < animalCount / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }
    
    // Make them make sounds
    std::cout << "\n----- ANIMAL SOUNDS -----\n" << std::endl;
    for (int k = 0; k < animalCount; k++) {
        std::cout << "Animal " << k << " (" << animals[k]->getType() << "): ";
        animals[k]->makeSound();
    }
    
    // Delete all animals
    std::cout << "\n----- DELETING ANIMALS -----\n" << std::endl;
    for (int k = 0; k < animalCount; k++) {
        delete animals[k];
    }
    
    // Test deep copying
    testDeepCopy();
    
    return 0;
} 