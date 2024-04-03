#include "PmergeMe.hpp"
#include <deque>
#include <vector>
#include <algorithm>

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

	std::cout << "Before: ";
    for (int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "After: ";
    for (int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << vecTime.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << deqTime.count() << " us" << std::endl;
}


template<typename Container>
void merge(Container& arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    Container L(n1), R(n2);

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement the merge-insert sort algorithm
template<typename Container>
void mergeInsertSort(Container& arr, int l, int r) {
    if (l < r) {
        // Same as (l + r) / 2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeInsertSort(arr, l, m);
        mergeInsertSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
