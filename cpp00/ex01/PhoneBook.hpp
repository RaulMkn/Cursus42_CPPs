#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <string>

class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_contactCount;
	int		_oldestIndex;

	std::string	_truncate(std::string str) const;
	void		_printColumn(std::string str) const;
	void		_displayContact(int index) const;

public:
	PhoneBook();
	~PhoneBook();

	void	addContact(void);
	void	searchContact(void) const;
};

#endif
