#include <iostream>
#include "Serializer.hpp"

int main(void)
{
	Data		data;
	data.name = "Luisito";
	data.value = 42;

	uintptr_t	raw = Serializer::serialize(&data);
	Data		*back = Serializer::deserialize(raw);

	std::cout << "original:    " << &data << std::endl;
	std::cout << "serializado: " << raw << std::endl;
	std::cout << "recuperado:  " << back << std::endl;

	if (back == &data)
		std::cout << "OK: mismo puntero" << std::endl;
	else
		std::cout << "KO: punteros distintos" << std::endl;

	std::cout << "name: " << back->name << ", value: " << back->value << std::endl;
	return 0;
}