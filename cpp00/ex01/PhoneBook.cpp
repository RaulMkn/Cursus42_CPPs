#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactCount(0), _oldestIndex(0)
{
}

PhoneBook::~PhoneBook()
{
}

std::string	PhoneBook::_truncate(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::_printColumn(std::string str) const
{
	std::cout << std::setw(10) << this->_truncate(str);
}

void	PhoneBook::_displayContact(int index) const
{
	std::cout << "First Name: " << this->_contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->_contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->_contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << this->_contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
}

void	PhoneBook::addContact(void)
{
	std::string	input;

	if (this->_contactCount < 8)
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input.empty())
			return ;
		this->_contacts[this->_contactCount].setFirstName(input);

		std::cout << "Enter last name: ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input.empty())
			return ;
		this->_contacts[this->_contactCount].setLastName(input);

		std::cout << "Enter nickname: ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input.empty())
			return ;
		this->_contacts[this->_contactCount].setNickname(input);

		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input.empty())
			return ;
		this->_contacts[this->_contactCount].setPhoneNumber(input);

		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input.empty())
			return ;
		this->_contacts[this->_contactCount].setDarkestSecret(input);

		this->_contactCount++;
		std::cout << "Contact added successfully!" << std::endl;
	}
	else
	{
		std::cout << "Phonebook is full. Replacing oldest contact..." << std::endl;

		std::cout << "Enter first name: ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input.empty())
			return ;
		this->_contacts[this->_oldestIndex].setFirstName(input);

		std::cout << "Enter last name: ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input.empty())
			return ;
		this->_contacts[this->_oldestIndex].setLastName(input);

		std::cout << "Enter nickname: ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input.empty())
			return ;
		this->_contacts[this->_oldestIndex].setNickname(input);

		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input.empty())
			return ;
		this->_contacts[this->_oldestIndex].setPhoneNumber(input);

		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input.empty())
			return ;
		this->_contacts[this->_oldestIndex].setDarkestSecret(input);

		this->_oldestIndex = (this->_oldestIndex + 1) % 8;
		std::cout << "Contact added successfully!" << std::endl;
	}
}

void	PhoneBook::searchContact(void) const
{
	if (this->_contactCount == 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return ;
	}

	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < this->_contactCount; i++)
	{
		std::cout << std::setw(10) << i << "|";
		this->_printColumn(this->_contacts[i].getFirstName());
		std::cout << "|";
		this->_printColumn(this->_contacts[i].getLastName());
		std::cout << "|";
		this->_printColumn(this->_contacts[i].getNickname());
		std::cout << std::endl;
	}

	std::cout << "Enter index to display: ";
	std::string	input;
	std::getline(std::cin, input);

	if (std::cin.eof())
		return ;

	if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
	{
		int	index = input[0] - '0';
		if (index < this->_contactCount)
			this->_displayContact(index);
		else
			std::cout << "Invalid index!" << std::endl;
	}
	else
		std::cout << "Invalid index!" << std::endl;
}
