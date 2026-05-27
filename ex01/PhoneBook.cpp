#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0) {	
}

static std::string getInput(const std::string& prompt)
{
	std::string input;

	while(input.empty())
	{
		std::cout << prompt << std::endl;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			exit(0);
		}
	}
	return input;
}

void PhoneBook::addContact()
{
	Contact contact;

	contact.setName(getInput("¿qué nombre le ponemos a la criatura?"));
	contact.setLastName(getInput("¿y el apellido?"));
	contact.setNickName(getInput("¿Un mote?"));
	contact.setPhoneNumber(getInput("¿Me das tu número?"));
	contact.setDarkestSecret(getInput("Escribeme tú más oscuro secreto"));
	this->_contacts[_count % 8] = contact;
	_count++;
}

void PhoneBook::searchContact()
{
	int limit = (_count < 8) ? _count : 8;

	for (int i = 0; i < limit; i++)
	{
		std::cout << std::right << std::setw(10) << std::substr(_contacts[i].getName()) << "|";
		std::cout << std::right << std::setw(10) << _contacts[i].getLastName() << "|";
	}
}

PhoneBook::~PhoneBook(){}