#include "ScavTrap.hpp"

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

	/*for (int i = 0; i < 11; i++)
		pone.attack(argv[2]);
	
	ClapTrap pone2(pone);
	ClapTrap pthree;
	pthree = pone;*/

	std::cout << "\n" << argv[1] << " TRANSCIENDEEE!!" << "\n" << std::endl;
	ScavTrap s1(argv[1]);
	
	s1.attack(argv[2]);
	s1.guardGate();
	
	std::cout << "\n" ;
	ScavTrap s2(s1);
	s2.beRepaired(5);
	std::cout << "\n" ;

	ScavTrap s3;
	s3 = s1;
	s3.takeDamage(5);
	std::cout << "\n" << std::endl;

	return 0;
}