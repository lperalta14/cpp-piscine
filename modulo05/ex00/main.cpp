#include "Bureaucrat.hpp"

int main(int argc, char **argv)
{
    if (argc != 3)
        return(1);
    try
    {
        Bureaucrat First(argv[1], atoi(argv[2]));
        std::cout << First << std::endl;
        if (atoi(argv[2]) != 150)
        {
            First.incrementGrade();
            std::cout << First << std::endl;
        }
        First.decrementGrade();
        std::cout << First << std::endl;

        Bureaucrat Second(First);
        std::cout << Second << std::endl;

        Bureaucrat Third("Jesus", 12);
        std::cout << Third << std::endl;

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
