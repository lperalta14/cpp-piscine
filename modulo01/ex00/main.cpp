#include "Zombie.h"

int main (int argc, char **argv)
{
	Zombie *zombie = newZombie("Sergay");
	zombie->announce();

	for (int i=1; i < argc; ++i)
		randomChump (argv[i]);
	delete zombie;
	return (0);
}