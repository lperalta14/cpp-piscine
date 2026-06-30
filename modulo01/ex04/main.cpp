#include <iostream>
#include <fstream>
#include <string>
 
// TODO: comprobar argc == 4 (programa + filename + s1 + s2)
 
// TODO: abrir filename con std::ifstream
// TODO: comprobar que el stream abrió bien
 
// TODO: leer todo el contenido del archivo a un std::string
//       (pista: std::getline en bucle, o leer el stream completo
//        con un std::ostringstream como "buffer")
 
// TODO: recorrer el contenido buscando cada aparición de s1
//       (pista: std::string::find devuelve la posición o std::string::npos)
//       construir el string resultado trozo a trozo con substr() + s2
 
// TODO: abrir <filename>.replace con std::ofstream y escribir el resultado
 
int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::ifstream(argv[1]);
	}
	
	return (0);
}