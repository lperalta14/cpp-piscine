
#include "ScalarConverter.hpp"

int main(void)
{
	std::cout << "\n===== CHAR =====" << std::endl;
	ScalarConverter::convert("'a'");
	ScalarConverter::convert("'*'");
	ScalarConverter::convert("'+'");
	ScalarConverter::convert("'0'");
	ScalarConverter::convert("-0.5");
	ScalarConverter::convert("127.9");
	ScalarConverter::convert("128");
	ScalarConverter::convert("-1");
	ScalarConverter::convert("32");
	ScalarConverter::convert("126"); 

	std::cout << "\n===== INT =====" << std::endl;
	ScalarConverter::convert("0");
	ScalarConverter::convert("42");
	ScalarConverter::convert("-");
	ScalarConverter::convert("-42");
	ScalarConverter::convert("2147483647");
	ScalarConverter::convert("2147483648");
	ScalarConverter::convert("-2147483648");
	ScalarConverter::convert("99999999999999999999");

	std::cout << "\n===== FLOAT =====" << std::endl;
	ScalarConverter::convert("0.0f");
	ScalarConverter::convert("42.0f");
	ScalarConverter::convert("-42.5f");
	ScalarConverter::convert("4.2f");
	ScalarConverter::convert(".5f");
	ScalarConverter::convert("5.f");

	std::cout << "\n===== DOUBLE =====" << std::endl;
	ScalarConverter::convert("0.0");
	ScalarConverter::convert("42.0");
	ScalarConverter::convert("-42.5");

	std::cout << "\n===== PSEUDO-LITERALS =====" << std::endl;
	ScalarConverter::convert("nan");
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("-inff");

	std::cout << "\n===== INVALID INPUTS =====" << std::endl;
	ScalarConverter::convert("");
	ScalarConverter::convert("abc");
	ScalarConverter::convert("42abc");
	ScalarConverter::convert("+");
	ScalarConverter::convert("42ff");
	ScalarConverter::convert("4.2.1");
	ScalarConverter::convert(std::string("1") + std::string(400, '0'));
	return (0);
}
