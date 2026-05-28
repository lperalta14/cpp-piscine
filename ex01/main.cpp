#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phonebook;
	std::string	input;

	while (true)
	{
		std::cout << "¿Qué hacemos?" << std::endl;
		std::cout << "ADD    -> AÑADIR CONTACTO" << std::endl;
		std::cout << "SEARCH -> BUSCAR CONTACTO" << std::endl;
		std::cout << "EXIT   -> CERRAR" << std::endl;
		std::cout << "PARA TODO LO DEMÁS, MÁSTER CARD" << std::endl;
		if (!std::getline(std::cin, input))
			break;
		if (!input.compare("ADD"))
			phonebook.addContact();
		else if (!input.compare("SEARCH"))
			phonebook.searchContact();
		else if (!input.compare("EXIT"))
			break;
	}
	return (0);
}
