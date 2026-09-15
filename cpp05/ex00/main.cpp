#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "===== Valid bureaucrat =====" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 3);
		std::cout << alice << std::endl;
		alice.incrementGrade();
		std::cout << "After increment: " << alice << std::endl;
		alice.decrementGrade();
		alice.decrementGrade();
		std::cout << "After 2 decrements: " << alice << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Grade too high on construction =====" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 0);
		std::cout << boss << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Grade too low on construction =====" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 151);
		std::cout << intern << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Increment past grade 1 =====" << std::endl;
	try
	{
		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
		top.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Decrement past grade 150 =====" << std::endl;
	try
	{
		Bureaucrat bottom("Bottom", 150);
		std::cout << bottom << std::endl;
		bottom.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
