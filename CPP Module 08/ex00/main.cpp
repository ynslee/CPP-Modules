#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <array>

int main(){
	std::cout << "----------TEST EASYFIND WITH ARRAYS---------" << std::endl;
	std::array<int, 10> arr;
	std::cout << "Array: ";
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 20;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	try{
		easyfind(arr, 25);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(arr, 100);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "----------TEST EASYFIND WITH VECTORS---------" << std::endl;
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	std::cout << "Vector: ";
	for (int i = 0; i < 10; i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	try{
		easyfind(vec, 5);
	}
	catch (std::exception &e){
		
		std::cout << e.what() << std::endl;
	}
    try {
        easyfind(vec, 10);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

	std::cout << "----------TEST EASYFIND WITH LISTS---------" << std::endl;
	// std::list 
	
	return 0;
}