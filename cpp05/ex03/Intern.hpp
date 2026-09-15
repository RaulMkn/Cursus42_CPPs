#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class Intern
{
	private:
		static AForm	*makeShrubbery(const std::string &target);
		static AForm	*makeRobotomy(const std::string &target);
		static AForm	*makePresidential(const std::string &target);

	public:
		Intern(void);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern(void);

		AForm	*makeForm(const std::string &formName, const std::string &target) const;

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
};

#endif
