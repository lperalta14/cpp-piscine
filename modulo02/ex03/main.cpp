#include "Point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);

	Point point1(5, 5);		//inside
	Point point2(15, 5);	//outside
	Point point3(5, -5);	//outside
	Point point4(5, 0);		//on the edge
	Point point5(0, 0);		//on the edge

	if (bsp(a, b, c, point1))
		std::cout << "Point1 is inside the triangle." << std::endl;
	else
		std::cout << "Point1 is outside the triangle." << std::endl;

	if (bsp(a, c, b, point1))
		std::cout << "Point1 is inside the triangle." << std::endl;
	else
		std::cout << "Point1 is outside the triangle." << std::endl;

	if (bsp(a, b, c, point2))
		std::cout << "Point2 is inside the triangle." << std::endl;
	else
		std::cout << "Point2 is outside the triangle." << std::endl;

	if (bsp(a, b, c, point3))
		std::cout << "Point3 is inside the triangle." << std::endl;
	else
		std::cout << "Point3 is outside the triangle." << std::endl;

	if (bsp(a, b, c, point4))
		std::cout << "Point4 is inside the triangle." << std::endl;
	else
		std::cout << "Point4 is outside the triangle." << std::endl;

	if (bsp(a, b, c, point5))
		std::cout << "Point5 is inside the triangle." << std::endl;
	else
		std::cout << "Point5 is outside the triangle." << std::endl;

	return 0;
}