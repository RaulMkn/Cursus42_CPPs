#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base::~Base(void)
{
}

Base	*generate(void)
{
	int	r = std::rand() % 3;

	if (r == 0)
	{
		std::cout << "[generated A]" << std::endl;
		return (new A());
	}
	if (r == 1)
	{
		std::cout << "[generated B]" << std::endl;
		return (new B());
	}
	std::cout << "[generated C]" << std::endl;
	return (new C());
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown / NULL" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::exception &e)
	{
	}
	std::cout << "Unknown" << std::endl;
}
