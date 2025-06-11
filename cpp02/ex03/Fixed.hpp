#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    Fixed();                          // Default constructor
    Fixed(const int value);           // Int constructor
    Fixed(const float value);         // Float constructor
    Fixed(const Fixed& src);          // Copy constructor
    Fixed& operator=(const Fixed& rhs); // Copy assignment operator
    ~Fixed();                         // Destructor

    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    float toFloat(void) const;
    int toInt(void) const;
    
    // Comparison operators
    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;
    
    // Arithmetic operators
    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;
    
    // Increment/decrement operators
    Fixed& operator++();      // Pre-increment
    Fixed operator++(int);    // Post-increment
    Fixed& operator--();      // Pre-decrement
    Fixed operator--(int);    // Post-decrement
    
    // Min/max static member functions
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif 