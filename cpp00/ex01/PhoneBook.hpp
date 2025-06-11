#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook 
{
private:
    Contact contacts[8];
    int currentIndex;
    int totalContacts;
    std::string truncate(std::string str) const;
    void displayField(std::string str) const;

public:
    PhoneBook();
    void addContact(const std::string& first, const std::string& last,
                   const std::string& nick, const std::string& phone,
                   const std::string& secret);
    void searchContact() const;
};

#endif 