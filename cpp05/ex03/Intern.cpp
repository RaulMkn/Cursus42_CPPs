#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern(void)
{
}

AForm *Intern::makeShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidential(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	const std::string	names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm *(*builders[3])(const std::string &) = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (names[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (builders[i](target));
		}
	}
	std::cout << "Intern could not create form: unknown form \""
		<< formName << "\"" << std::endl;
	throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what(void) const throw()
{
	return ("Requested form does not exist");
}
