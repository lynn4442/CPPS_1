#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

// Abstract class (cannot be instantiated)
class Animal {
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    std::string getType() const;
    // Pure virtual function makes this class abstract
    virtual void makeSound() const = 0;
};

#endif // ANIMAL_HPP 