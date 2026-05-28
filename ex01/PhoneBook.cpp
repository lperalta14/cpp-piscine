#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0) {}

static std::string getInput(const std::string& prompt, bool onlyDigits = false)
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
		for (int i=0; i < (int)input.length(); i++)
		{
			if (input[i] < 32 || input[i] > 126)
				input.clear();
			else if (onlyDigits && (input[i] < '0' || input[i] > '9'))
				input.clear();
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
	contact.setPhoneNumber(getInput("¿Me das tu número?", true));
	contact.setDarkestSecret(getInput("Escribeme tú más oscuro secreto"));
	this->_contacts[_count % 8] = contact;
	_count++;
}
static	std::string truncate(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0,9) + ".";
	return str;
}

static int atoiCpp(const std::string& str)
{
	for (int i=0; i < (int)str.length(); i++)
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	return atoi(str.c_str());
}

void PhoneBook::searchContact()
{
	int limit = (_count < 8) ? _count : 8;
	int id;
	for (int i = 0; i < limit; i++)
	{
		std::cout << std::right << std::setw(10) << i << "|";
		std::cout << std::right << std::setw(10) << truncate(_contacts[i].getName()) << "|";
		std::cout << std::right << std::setw(10) << truncate(_contacts[i].getLastName()) << "|";
		std::cout << std::right << std::setw(10) << truncate(_contacts[i].getNickName()) << "|" << std::endl;
	}
	id = atoiCpp(getInput("¿qué contanto quieres ver?"));
	if (id < 0 || id >= limit)
		return ;
	std::cout << _contacts[id].getName() << std::endl;
	std::cout << _contacts[id].getLastName() << std::endl;
	std::cout << _contacts[id].getNickName() << std::endl;
	std::cout << _contacts[id].getPhoneNumber() << std::endl;
	std::cout << _contacts[id].getDarkestSecret() << std::endl;
}

PhoneBook::~PhoneBook(){}
