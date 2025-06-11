#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;
    
    std::cout << "Testing Harl's complaints:" << std::endl << std::endl;
    
    std::cout << "--- DEBUG level ---" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    
    std::cout << "--- INFO level ---" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    
    std::cout << "--- WARNING level ---" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    
    std::cout << "--- ERROR level ---" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    
    std::cout << "--- Invalid level ---" << std::endl;
    harl.complain("INVALID");
    std::cout << std::endl;
    
    return 0;
} 