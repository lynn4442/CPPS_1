#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Constructors and basic methods
Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const int value) {
    this->_value = value << this->_fractionalBits;
}

Fixed::Fixed(const float value) {
    this->_value = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed& src) {
    *this = src;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
    if (this != &rhs) {
        this->_value = rhs.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->_value / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_value >> this->_fractionalBits;
}

bool Fixed::operator>(const Fixed& rhs) const {
    return this->_value > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed& rhs) const {
    return this->_value < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed& rhs) const {
    return this->_value >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed& rhs) const {
    return this->_value <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed& rhs) const {
    return this->_value == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed& rhs) const {
    return this->_value != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits(this->_value + rhs.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits(this->_value - rhs.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    Fixed result;
    result.setRawBits((this->_value * rhs.getRawBits()) >> this->_fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    if (rhs.getRawBits() == 0) {
        std::cout << "Error: Division by zero" << std::endl;
        return Fixed();
    }
    Fixed result;
    result.setRawBits((this->_value << this->_fractionalBits) / rhs.getRawBits());
    return result;
}

Fixed& Fixed::operator++() {
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

// Min/max static member functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// Stream insertion operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
} 