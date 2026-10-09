#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    try
    {
        Bureaucrat chief("Chief", 1);
        Bureaucrat junior("Junior", 140);

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "\n--- Unsigned form ---" << std::endl;
        junior.executeForm(shrubbery);

        std::cout << "\n--- Sign and execute shrubbery ---" << std::endl;
        junior.signForm(shrubbery);
        junior.executeForm(shrubbery);

        std::cout << "\n--- Robotomy ---" << std::endl;
        chief.signForm(robotomy);
        chief.executeForm(robotomy);

        std::cout << "\n--- Presidential pardon ---" << std::endl;
        chief.signForm(pardon);
        chief.executeForm(pardon);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
