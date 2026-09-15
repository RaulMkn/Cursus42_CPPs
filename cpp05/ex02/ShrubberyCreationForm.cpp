#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void ShrubberyCreationForm::action(void) const
{
	std::ofstream	file((this->_target + "_shrubbery").c_str());

	if (!file.is_open())
	{
		std::cerr << "ShrubberyCreationForm: could not open output file"
			<< std::endl;
		return ;
	}
	file << "           ,@@@@@@@,\n";
	file << "   ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	file << ",&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	file << ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	file << "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	file << "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	file << "`&%\\ ` /%&'    |.|        \\ '|8'\n";
	file << "    |o|        | |         | |\n";
	file << "    |.|        | |         | |\n";
	file << "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
	file.close();
}
