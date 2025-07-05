#include "Point.hpp"

static Fixed area(Point const a, Point const b, Point const c)
{
	Fixed x1 = a.getX();
	Fixed y1 = a.getY();
	Fixed x2 = b.getX();
	Fixed y2 = b.getY();
	Fixed x3 = c.getX();
	Fixed y3 = c.getY();

	Fixed area = ((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2))) / Fixed(2);

	if (area < Fixed(0))
		area = area * Fixed(-1);
	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaABC = area(a, b, c);

	if (areaABC == Fixed(0))
		return false;

	Fixed areaPAB = area(point, a, b);
	Fixed areaPBC = area(point, b, c);
	Fixed areaPCA = area(point, c, a);

	if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0))
		return false;
	return (areaPAB + areaPBC + areaPCA == areaABC);
}
