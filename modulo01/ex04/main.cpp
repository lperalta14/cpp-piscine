#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string replaceAll(
	const std::string& content,
	const std::string& s1,
	const std::string& s2)
{
	size_t start = 0;
	size_t pos;
	std::string result;
	while ((pos = content.find(s1, start)) != std::string::npos)
	{

		result += content.substr(start, pos - start) + s2;
		start = pos + s1.length();
	}

	result += content.substr(start);
	return (result);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <file> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream infile(argv[1]);
	if (!infile || s1.empty())
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	std::stringstream buffer;
	buffer << infile.rdbuf();
	std::string content = buffer.str();
	std::string result = replaceAll(content, s1, s2);
	std::string filename = std::string(argv[1]) + ".replace";
	std::ofstream outfile(filename.c_str());
	if (!outfile)
	{
		std::cerr << "Error creating output file" << std::endl;
		return (1);
	}
	outfile << result;
	return (0);
}