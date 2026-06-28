#include <iostream>
#include <string>

/*int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "str: " << str << " " << &str <<std::endl;
	std::cout << "PTR: " << stringPTR << " " << &stringPTR << std::endl;
	std::cout << "REF: " << stringREF << " " << &stringREF << std::endl;
	return (0);
}*/

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "str mem: " << &str << std::endl;
	std::cout << "PTR mem: " << stringPTR << std::endl;
	std::cout << "REF mem: " << &stringREF << std::endl;
	std::cout << "content str: " << str << std::endl;
	std::cout << "content PTR: " << *stringPTR << std::endl;
	std::cout << "content REF: " << stringREF << std::endl;

	return (0);
}