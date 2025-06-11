#include <iostream>
#include "Point.hpp"

int main(void) {
    // Create a triangle with vertices at (0,0), (4,0), and (2,3)
    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 3);
    
    // Points to test
    Point inside(2, 1);          // Inside the triangle
    Point outside(5, 5);         // Outside the triangle
    Point onVertex(0, 0);        // On a vertex (a)
    Point onEdge(2, 0);          // On an edge (midpoint of a-b)
    
    // Test the points
    std::cout << "Point (2,1) is inside triangle: " << (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
    std::cout << "Point (5,5) is inside triangle: " << (bsp(a, b, c, outside) ? "true" : "false") << std::endl;
    std::cout << "Point (0,0) is inside triangle (on vertex): " << (bsp(a, b, c, onVertex) ? "true" : "false") << std::endl;
    std::cout << "Point (2,0) is inside triangle (on edge): " << (bsp(a, b, c, onEdge) ? "true" : "false") << std::endl;
    
    return 0;
} 