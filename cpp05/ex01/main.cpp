#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "===== Invalid form grades =====" << std::endl;
	try
	{
		Form bad("Bad", 0, 10);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Form bad("Bad", 10, 200);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Signing success =====" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		Form report("TaxReport", 50, 25);
		std::cout << report << std::endl;
		boss.signForm(report);
		std::cout << report << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Signing failure (grade too low) =====" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 100);
		Form report("SecretForm", 50, 25);
		std::cout << report << std::endl;
		intern.signForm(report);
		std::cout << report << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
