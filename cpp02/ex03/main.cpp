#include <iostream>
#include "Point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(4, 0);
	Point c(2, 3);

	Point inside(2, 1);
	Point outside(5, 5);
	Point onVertex(0, 0);
	Point onEdge(2, 0);

	std::cout << "Point (2,1) is inside triangle: " << (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
	std::cout << "Point (5,5) is inside triangle: " << (bsp(a, b, c, outside) ? "true" : "false") << std::endl;
	std::cout << "Point (0,0) is inside triangle (on vertex): " << (bsp(a, b, c, onVertex) ? "true" : "false") << std::endl;
	std::cout << "Point (2,0) is inside triangle (on edge): " << (bsp(a, b, c, onEdge) ? "true" : "false") << std::endl;

	return 0;
}
