#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Intern		intern;
	Bureaucrat	boss("Boss", 1);

	std::cout << "===== Intern makes a robotomy request =====" << std::endl;
	{
		AForm *form = intern.makeForm("robotomy request", "Bender");
		if (form)
		{
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	}

	std::cout << "\n===== Intern makes a presidential pardon =====" << std::endl;
	{
		AForm *form = intern.makeForm("presidential pardon", "Arthur");
		if (form)
		{
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	}

	std::cout << "\n===== Intern makes a shrubbery =====" << std::endl;
	{
		AForm *form = intern.makeForm("shrubbery creation", "garden");
		if (form)
		{
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	}

	std::cout << "\n===== Intern with unknown form name =====" << std::endl;
	try
	{
		AForm *form = intern.makeForm("coffee making", "kitchen");
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
