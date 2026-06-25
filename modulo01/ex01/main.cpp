#include "Zombie.hpp"
#include <sstream>

int main(int argc, char **argv)
{
	int n;
	Zombie	*zombie;

	if (argc == 3)
	{
		std::istringstream num(argv[1]);
		num >> n;
		zombie = zombieHorde(n, argv[2]);
		for (int i = 0; i < n; i++)
			zombie[i].announce();
		delete[] zombie;
	}

	return (0);
}