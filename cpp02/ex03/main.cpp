#include "Point.hpp"
#include <iostream>

int	main(void)
{
	Point	a(0, 0);
	Point	b(10, 0);
	Point	c(5, 10);

	Point	inside(5, 5);
	Point	outside(10, 10);
	Point	onEdge(5, 0);

	std::cout << "Point (5, 5) is ";
	if (bsp(a, b, c, inside))
		std::cout << "inside";
	else
		std::cout << "outside";
	std::cout << " the triangle" << std::endl;

	std::cout << "Point (10, 10) is ";
	if (bsp(a, b, c, outside))
		std::cout << "inside";
	else
		std::cout << "outside";
	std::cout << " the triangle" << std::endl;

	std::cout << "Point (5, 0) is ";
	if (bsp(a, b, c, onEdge))
		std::cout << "inside";
	else
		std::cout << "outside";
	std::cout << " the triangle" << std::endl;

	return (0);
}
