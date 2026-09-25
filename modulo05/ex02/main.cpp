#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    // =========================================================
    // 1. Crear un Form válido
    // =========================================================
    std::cout << "\n--- 1. Form valido ---\n";

    try
    {
        Form form("Vacation request", 50, 30);

        std::cout << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    // =========================================================
    // 2. Form con grade demasiado alto
    // =========================================================
    std::cout << "\n--- 2. Grade demasiado alto ---\n";

    try
    {
        Form form("Invalid form", 0, 30);

        std::cout << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    // =========================================================
    // 3. Form con grade demasiado bajo
    // =========================================================
    std::cout << "\n--- 3. Grade demasiado bajo ---\n";

    try
    {
        Form form("Invalid form", 151, 30);

        std::cout << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    // =========================================================
    // 4. Bureaucrat con grado suficiente para firmar
    // =========================================================
    std::cout << "\n--- 4. Puede firmar ---\n";

    try
    {
        Bureaucrat bureaucrat("Luis", 40);
        Form form("Vacation request", 50, 30);

        std::cout << "Antes:  " << form << std::endl;

        bureaucrat.signForm(form);

        std::cout << "Despues: " << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    // =========================================================
    // 5. Bureaucrat con grado insuficiente
    // =========================================================
    std::cout << "\n--- 5. NO puede firmar ---\n";

    try
    {
        Bureaucrat bureaucrat("Pepe", 60);
        Form form("Vacation request", 50, 30);

        std::cout << "Antes:  " << form << std::endl;

        bureaucrat.signForm(form);

        std::cout << "Despues: " << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    // =========================================================
    // 6. Caso frontera: mismo grade
    // =========================================================
    std::cout << "\n--- 6. Mismo grade ---\n";

    try
    {
        Bureaucrat bureaucrat("Ana", 50);
        Form form("Exact grade form", 50, 30);

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    // =========================================================
    // 7. Constructor de copia
    // =========================================================
    std::cout << "\n--- 7. Copy constructor ---\n";

    try
    {
        Bureaucrat bureaucrat("Carlos", 20);
        Form original("Original", 50, 30);

        bureaucrat.signForm(original);

        Form copy(original);

        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy:     " << copy << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }


    // =========================================================
    // 8. Operator =
    // =========================================================
    std::cout << "\n--- 8. Assignment operator ---\n";

    try
    {
        Bureaucrat bureaucrat("Maria", 20);

        Form original("Original", 50, 30);
        Form other("Other", 100, 100);

        bureaucrat.signForm(original);

        std::cout << "Antes:\n";
        std::cout << "Original: " << original << std::endl;
        std::cout << "Other:    " << other << std::endl;

        other = original;

        std::cout << "\nDespues de other = original:\n";
        std::cout << "Original: " << original << std::endl;
        std::cout << "Other:    " << other << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return (0);
}
