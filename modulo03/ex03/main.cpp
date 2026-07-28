#include "DiamondTrap.hpp"

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cout << "Uso: ./DiamondTrap nombre1 nombre2" << std::endl;
		return 1;
	}

	std::cout << "\n" << argv[1] << " TRANSCIENDEEE AL DIAMANTE!!" << "\n" << std::endl;

	DiamondTrap d1(argv[1]);

	d1.whoAmI();
	d1.attack(argv[2]);
	d1.guardGate();
	d1.highFivesGuys();

	std::cout << "\n";

	d1.beRepaired(5);
	d1.takeDamage(10);

	std::cout << "\n";

	DiamondTrap d2(d1);
	d2.whoAmI();

	DiamondTrap d3;
	d3 = d1;
	d3.whoAmI();

	std::cout << "\n" << std::endl;

	return 0;
}