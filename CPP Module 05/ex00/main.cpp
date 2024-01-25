#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "\n******** No Exception ********\n" << std::endl;
    try
    {
        Bureaucrat officer("Officer", 3);
        std::cout << officer<< std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n******** Too High Exception ********\n" << std::endl;
    try
    {
        Bureaucrat Yoonseon("Yoonseon", -2);
        std::cout << Yoonseon << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n******** Too Low Exception ********\n" << std::endl;
    try
    {
        Bureaucrat Chuchi("Chuchi", 152);
        std::cout << Chuchi << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\n******** Increment grade ********\n" << std::endl;
    try
    {
         Bureaucrat test("Yoonseon", 1);
         std::cout << test << std::endl;
		 std::cout << "Incrementing grade of " << test.getName() << ":" << std::endl;
         test.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n******** Decrement grade ********\n" << std::endl;
    try
    {
        Bureaucrat test1("Chuchi", 150);
         std::cout << test1 << std::endl;
		  std::cout << "decrementing grade of " << test1.getName() << ":" << std::endl;
        test1.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


std::cout << "\n******** copy ********\n" << std::endl;
    Bureaucrat test("Yoonseon", 1);
    Bureaucrat test2(test);

    std::cout << test2 << std::endl;

}