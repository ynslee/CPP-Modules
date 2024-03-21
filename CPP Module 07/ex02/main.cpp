#include "Array.hpp"
#include <iostream>

int main( void ) {

    std::cout << "\nTEST int * a = new int(); CASE" << std::endl;
	Array<int> a(10);
	for (int i = 0; i < 10; i++) {
		a[i] = 5 - i;
	}
	std::cout << "   ***print array 'a'***   " << std::endl;
	for (int i = 0; i < 10; i++) {
		std::cout << "array 'a' index[" << i <<"] is " << a[i] << std::endl;
	}

    Array<std::string> b(10);
    for (int i = 0; i < 10; i++) {
        b[i] = "string" + std::to_string(i);
    }
    std::cout << "   ***print array 'b'***   " << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "array 'b' index[" << i <<"] is " << b[i] << std::endl;
    }

    std::cout << "\nTEST COPY CONSTRUCTER CASE" << std::endl;
	Array<int> copy(a);
    std::cout << "   ***print array 'copy'***   " << std::endl;
	for (int i = 0; i < 10; i++) {
        std::cout << "array 'copy' index[" << i <<"] is " << copy[i] << std::endl;
		if (copy[i] != a[i]) {
            std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
        }
	}
    std::cout << "\033[32mTEST OKAY\033[0m" <<std::endl; 

    std::cout << "\nTEST ASSIGNMENT OPERATOR CASE" << std::endl;
    Array<int> assign(10);
    std::cout << "   ***print array 'assign'***   " << std::endl;
    for (int i = 0; i < 10; i++) {
		assign[i] = i;
        std::cout << "array 'assign' index[" << i <<"] is " << assign[i] << std::endl;
	}
    assign = a;
    std::cout << "   ***print array 'assign' after copy assignment***   " << std::endl;
	for (int i = 0; i < 10; i++) {
        std::cout << "array 'assign' index[" << i <<"] is " << assign[i] << std::endl;
		if (assign[i] != a[i]) {
            std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
        }
	}    
    std::cout << "\033[32mTEST OKAY\033[0m" <<std::endl;

    std::cout << "\nTEST IT HAS MALLOCED NEW MEMORY" << std::endl;
    a[5] = 100;
    int flag = 0;
    std::cout << "   ***test with copy constructor array***   " << std::endl;
    for (int i = 0; i < 10; i++) {
		if (assign[i] != a[i]) {
            flag = 1;
            std::cout << "\033[32mTEST OKAY\033[0m" <<std::endl;
        }
	}
    if (flag == 0)
        std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
    std::cout << "   ***test with copy assignment operator array***   " << std::endl;
    flag = 0;
    for (int i = 0; i < 10; i++) {
		if (copy[i] != a[i]) {
            flag = 1;
            std::cout << "\033[32mTEST OKAY\033[0m" <<std::endl;
        }
	}
    if (flag == 0)
        std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;

    std::cout << "\nTEST EXCEPTION CASES" << std::endl;
    try
    {
        assign[-2] = 0;
        std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Failed to access numbers[-2]: " << e.what() << '\n';
        std::cout << "\033[32mTEST OKAY\033[0m" <<std::endl;
    }
    try
    {
        assign[20] = 0;
        std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Failed to access numbers[MAX_VAL]: " << e.what() << '\n';
        std::cout << "\033[32mTEST OKAY\033[0m" <<std::endl;
    }
    Array<int> empty;
    try
    {
        empty[0] = 0;
        std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Failed to access empty[0]: " << e.what() << '\n';
        std::cout << "\033[32mTEST OKAY\033[0m" <<std::endl;
    }

	return (0);
}


// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
