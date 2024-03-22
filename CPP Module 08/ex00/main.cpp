#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <deque>

int main(){
	std::cout << "----------TEST EASYFIND WITH ARRAY---------" << std::endl;
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

	std::cout << "----------TEST EASYFIND WITH VECTOR---------" << std::endl;
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

	std::cout << "----------TEST EASYFIND WITH LIST---------" << std::endl;
	std::list<int> lst;
	for (int i = 0; i < 10; i++)
		lst.push_back(i * 2);
	std::cout << "List: ";
	std::list<int>::iterator it;
	for (it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	try{
		easyfind(lst, 8);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(lst, 13);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "----------TEST EASYFIND WITH DEQUE---------" << std::endl;

	std::deque<int> deq;
	for (int i = 0; i < 10; i++)
		deq.push_back(i - 5);
	std::cout << "Deque: ";
	std::deque<int>::iterator it2;
	for (it2 = deq.begin(); it2 != deq.end(); it2++)
		std::cout << *it2 << " ";
	std::cout << std::endl;
	try{
		easyfind(deq, 0);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(deq, -10);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}