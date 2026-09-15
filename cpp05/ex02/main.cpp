#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "===== Shrubbery (sign 145 / exec 137) =====" << std::endl;
	{
		Bureaucrat gardener("Gardener", 130);
		ShrubberyCreationForm shrub("home");
		gardener.signForm(shrub);
		gardener.executeForm(shrub);
	}

	std::cout << "\n===== Robotomy (sign 72 / exec 45) =====" << std::endl;
	{
		Bureaucrat surgeon("Surgeon", 40);
		RobotomyRequestForm robo("Bender");
		surgeon.signForm(robo);
		surgeon.executeForm(robo);
		surgeon.executeForm(robo);
	}

	std::cout << "\n===== Presidential (sign 25 / exec 5) =====" << std::endl;
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		president.signForm(pardon);
		president.executeForm(pardon);
	}

	std::cout << "\n===== Execute unsigned form =====" << std::endl;
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon("Ford");
		boss.executeForm(pardon);
	}

	std::cout << "\n===== Execute with grade too low =====" << std::endl;
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat weak("Weak", 10);
		PresidentialPardonForm pardon("Trillian");
		boss.signForm(pardon);
		weak.executeForm(pardon);
	}

	return (0);
}
