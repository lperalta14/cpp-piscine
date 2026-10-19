#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <iomanip>
#include <cmath>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool is_char(const std::string &str)
{
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
        return true;
    if (str.length() == 1)
    {
        unsigned char c = static_cast<unsigned char>(str[0]);
        return !std::isdigit(c) && c != '+' && c != '-';
    }
    return false;
}

bool is_int(const std::string &str)
{
    size_t i = 0;

    if (str.empty())
        return false;
    if ((str[i] == '+' || str[i] == '-'))
        i++;
    if (i == str.length())
        return false;
    for (; i < str.length(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

bool is_floating(const std::string &str, bool require_f)
{
    if (str.empty())
        return false;

    if (require_f)
    {
        if (str == "nanf" || str == "+inff" || str == "-inff")
            return true;
    }
    else
    {
        if (str == "nan" || str == "+inf" || str == "-inf")
            return true;
    }

    std::string core = str;
    if (require_f)
    {
        if (str[str.length() - 1] != 'f')
            return false;
        core = str.substr(0, str.length() - 1);
    }

    if (core.empty())
        return false;

    size_t i = 0;
    if (core[i] == '+' || core[i] == '-')
        i++;
    if (i == core.length())
        return false;

    bool has_point = false;
    bool has_digit = false;

    for (; i < core.length(); i++)
    {
        if (core[i] == '.')
        {
            if (has_point)
                return false;
            has_point = true;
        }
        else if (core[i] >= '0' && core[i] <= '9')
            has_digit = true;
        else
            return false;
    }
    return has_point && has_digit;
}

bool is_float(const std::string &str)
{
    return is_floating(str, true);
}

bool is_double(const std::string &str)
{
    return is_floating(str, false);
}

static bool is_special(const std::string &str)
{
    return str == "nan" || str == "nanf"
        || str == "+inf" || str == "-inf"
        || str == "+inff" || str == "-inff";
}

static void print_impossible_char_int()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
}

static void print_from_number(double value, bool float_source)
{
    std::cout << "char: ";
    if (value != value
        || value <= -1
        || value >= 128)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

    std::cout << "int: ";
    if (value != value
        || value < static_cast<double>(std::numeric_limits<int>::min())
        || value >= -static_cast<double>(std::numeric_limits<int>::min()))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;

    std::cout << std::fixed << std::setprecision(1);

    if (float_source)
    {
        float f = static_cast<float>(value);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
    else
    {
        std::cout << "float: ";
        if (value > std::numeric_limits<float>::max()
            || value < -std::numeric_limits<float>::max())
            std::cout << "impossible" << std::endl;
        else
            std::cout << static_cast<float>(value) << "f" << std::endl;

        std::cout << "double: " << value << std::endl;
    }
}

void ScalarConverter::convert(const std::string &str)
{
    if (is_special(str))
    {
        print_impossible_char_int();

        if (str == "nan" || str == "nanf")
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (str == "-inf" || str == "-inff")
        {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        else
        {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        return;
    }

    if (is_char(str))
    {
        char c = (str.length() == 1) ? str[0] : str[1];
        print_from_number(static_cast<unsigned char>(c), false);
        return;
    }

    if (is_int(str))
    {
        char *end;
        errno = 0;
        long temp = std::strtol(str.c_str(), &end, 10);

        if (errno == ERANGE || *end != '\0'
            || temp < std::numeric_limits<int>::min()
            || temp > std::numeric_limits<int>::max())
        {
            print_impossible_char_int();

            errno = 0;
            double d = std::strtod(str.c_str(), NULL);
            bool double_ok = (errno != ERANGE);

            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: ";
            if (!double_ok || d > std::numeric_limits<float>::max()
                || d < -std::numeric_limits<float>::max())
                std::cout << "impossible" << std::endl;
            else
                std::cout << static_cast<float>(d) << "f" << std::endl;

            std::cout << "double: ";
            if (!double_ok)
                std::cout << "impossible" << std::endl;
            else
                std::cout << d << std::endl;
            return;
        }

        print_from_number(static_cast<double>(temp), false);
        return;
    }

    if (is_float(str))
    {
        std::string core = str.substr(0, str.length() - 1);
        char *end;
        errno = 0;
        double parsed = std::strtod(core.c_str(), &end);

        if (errno == ERANGE || *end != '\0'
            || parsed > std::numeric_limits<float>::max()
            || parsed < -std::numeric_limits<float>::max())
        {
            print_impossible_char_int();
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: " << parsed << std::endl;
            return;
        }

        float f = static_cast<float>(parsed);
        print_from_number(static_cast<double>(f), true);
        return;
    }

    if (is_double(str))
    {
        char *end;
        errno = 0;
        double d = std::strtod(str.c_str(), &end);

        if (errno == ERANGE || *end != '\0')
        {
            print_impossible_char_int();
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }

        print_from_number(d, false);
        return;
    }

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}