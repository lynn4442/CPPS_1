#include "Point.hpp"

// Function to calculate the area of a triangle
static Fixed area(Point const a, Point const b, Point const c) {
    // Using cross product method
    Fixed x1 = a.getX();
    Fixed y1 = a.getY();
    Fixed x2 = b.getX();
    Fixed y2 = b.getY();
    Fixed x3 = c.getX();
    Fixed y3 = c.getY();
    
    Fixed area = ((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2))) / Fixed(2);
    
    // We need the absolute value of the area
    if (area < Fixed(0))
        area = area * Fixed(-1);
    
    return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Calculate area of the triangle ABC
    Fixed areaABC = area(a, b, c);
    
    // If area is zero, the triangle is degenerate (a line or a point)
    if (areaABC == Fixed(0))
        return false;
    
    // Calculate areas of triangles formed by the point and each side of the triangle
    Fixed areaPAB = area(point, a, b);
    Fixed areaPBC = area(point, b, c);
    Fixed areaPCA = area(point, c, a);
    
    // If any of the areas is zero, the point lies on an edge or is a vertex
    if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0))
        return false;
    
    // Check if the sum of areas of triangles equals the area of the original triangle
    return (areaPAB + areaPBC + areaPCA == areaABC);
} 