#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

std::string getValidInput(const std::string& prompt) 
{
    std::string input;
    
    while (true) 
	{
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
        if (!input.empty())
            break;
        std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
    return input;
}

int main(void) 
{
    PhoneBook   phonebook;
    std::string command;

	while (true) 
	{
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (std::cin.eof())//in order not to go into an infinite loop when i press ctrl + D
            break;
        if (command == "EXIT")
            break;
        else if (command == "ADD") 
		{
            std::string firstName = getValidInput("Enter first name: ");
            std::string lastName = getValidInput("Enter last name: ");
            std::string nickname = getValidInput("Enter nickname: ");
            std::string phone = getValidInput("Enter phone number: ");
            std::string secret = getValidInput("Enter darkest secret: ");
            phonebook.addContact(firstName, lastName, nickname, phone, secret);
            std::cout << "Contact added successfully!" << std::endl;
        }
        else if (command == "SEARCH")
		{
            phonebook.searchContact();
		}
    }
    std::cout << "great now you lost all your contacts!" << std::endl;
    return 0;
} 