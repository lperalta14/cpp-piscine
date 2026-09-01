#include "Bureaucrat.hpp"
#include <stdlib.h>
int main(int argc, char **argv)
{
    if (argc != 3)
        return(1);
    try
    {
        std::cout << "-----------------------------------------------\n" << "First Bureaucrat" << std::endl;
        Bureaucrat First(argv[1], atoi(argv[2]));
        std::cout << First << std::endl;
        if (atoi(argv[2]) != 150)
        {
            std::cout << "-----------------------------------------------\n" << "Increment Grade" << std::endl;
            First.incrementGrade();
            std::cout << First << std::endl;
        }
        std::cout << "-----------------------------------------------\n" << "Decrement Grade" << std::endl;
        First.decrementGrade();
        std::cout << First << std::endl;

        std::cout << "-----------------------------------------------\n" << "Second Bureaucrat" << std::endl;
        Bureaucrat Second(First);
        std::cout << Second << std::endl;

        std::cout << "-----------------------------------------------\n" << "Third Bureaucrat" << std::endl;
        Bureaucrat Third("Jesus", 12);
        std::cout << Third << std::endl;
        std::cout << "-----------------------------------------------\n" << "After assignment First to Third:" << std::endl;
        Third = First;
        std::cout << Third << std::endl;
    }
    catch(std::exception& First)
    {
        std::cout << First.what() << std::endl;
        return(1);
    }

    return(0);
}
