#include "ClapTrap.hpp"

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cout << "Uso: ./ClapTrap nombre1 nombre2" << std::endl;
		return 1;
	}
	ClapTrap pone(argv[1]);
	ClapTrap ptwo(argv[2]);
	
	pone.attack(argv[2]);
	ptwo.takeDamage(5);
	ptwo.beRepaired(2);
	ptwo.attack(argv[1]);

	for (int i = 0; i < 11; i++)
		pone.attack(argv[2]);
	
	ClapTrap pone2(pone);
	ClapTrap pthree;
	pthree = pone;

	return 0;
}