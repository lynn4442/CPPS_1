#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    Fixed const _x;
    Fixed const _y;

public:
    Point();                           // Default constructor
    Point(const float x, const float y); // Float constructor
    Point(const Point& src);           // Copy constructor
    Point& operator=(const Point& rhs); // Copy assignment operator
    ~Point();                          // Destructor

    Fixed getX() const;
    Fixed getY() const;
};

// BSP function declaration
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif 