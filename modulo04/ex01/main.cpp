#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "--- Test basico (igual que ex00) ---\n" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << "\n--- Array de Animal* (mitad Dog, mitad Cat) ---\n" << std::endl;
	Animal* animals[6];
	for (int k = 0; k < 3; k++)
		animals[k] = new Dog();
	for (int k = 3; k < 6; k++)
		animals[k] = new Cat();

	for (int k = 0; k < 6; k++)
		animals[k]->makeSound();

	std::cout << "\n--- Destruyendo el array como Animal* ---\n" << std::endl;
	for (int k = 0; k < 6; k++)
		delete animals[k];

	std::cout << "\n--- Test de deep copy ---\n" << std::endl;
	Dog original;
	Dog copia(original);
	std::cout << "Si Brain* fuera shallow copy, destruir 'copia' y luego 'original'";
	std::cout << " provocaria un double free. Si no crashea, la copia es profunda.\n" << std::endl;

	return 0;
}