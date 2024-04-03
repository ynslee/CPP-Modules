#include "PmergeMe.hpp"
#include <deque>
#include <vector>
#include <algorithm>
#include <chrono>

PmergeMe::PmergeMe(std::stringstream ss){
	int num = 0;
	std::vector<int> vec;
	std::deque<int> deq;
    while (ss >> num) {
        if (num < 0) {
            std::cerr << "Error: Negative number provided." << std::endl;
            return;
        }
		vec.push_back(num);
		deq.push_back(num);
    }
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    mergeInsertSort(vec, 0, vec.size() - 1);
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> vecTime = end - start;
	
	start = std::chrono::high_resolution_clock::now();
    mergeInsertSort(deq, 0, deq.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> deqTime = end - start;



    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << vecTime.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << deqTime.count() << " us" << std::endl;
}

