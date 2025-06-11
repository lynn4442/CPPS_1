#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0) {}

std::string PhoneBook::truncate(std::string str) const 
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::displayField(std::string str) const 
{
    std::cout << std::setw(10) << std::right << truncate(str) << "|";
}

void PhoneBook::addContact(const std::string& first, const std::string& last,
                          const std::string& nick, const std::string& phone,
                          const std::string& secret) 
{
    contacts[currentIndex].setContact(first, last, nick, phone, secret);
    currentIndex = (currentIndex + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
}

void PhoneBook::searchContact() const 
{
    if (totalContacts == 0) 
	{
        std::cout << "oops your phonebook is empty, no friends left :(" << std::endl;
        return;
    }
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
    for (int i = 0; i < totalContacts; i++) 
	{
        std::cout << std::setw(10) << i << "|";
        displayField(contacts[i].getFirstName());
        displayField(contacts[i].getLastName());
        displayField(contacts[i].getNickname());
        std::cout << std::endl;
    }
    std::cout << "Enter index to display: ";
    int index;
    std::cin >> index;
	std::cin.ignore(10000, '\n'); //added this it was going into infinite loop while ctrl+d
    if (std::cin.fail() || index < 0 || index >= totalContacts) 
	{
        std::cout << "no such index :(" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n'); //added this it was going into infinite loop while ctrl+d
        return;
    }
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
} 