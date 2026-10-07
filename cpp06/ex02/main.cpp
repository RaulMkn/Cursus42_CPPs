#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i = 0; i < 6; i++)
	{
		Base	*p = generate();
		std::cout << "  identify(ptr): ";
		identify(p);
		std::cout << "  identify(ref): ";
		identify(*p);
		std::cout << std::endl;
		delete p;
	}
	return (0);
}
