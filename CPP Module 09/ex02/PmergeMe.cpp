#include "PmergeMe.hpp"
#include <deque>
#include <vector>
#include <algorithm>
#include <chrono>
#include <utility>

template <template <typename...> class Container>
static void	insertionSort(Container<int> &large, Container<int> small)
{
	for (typename Container<int>::iterator it = small.begin(); it != small.end(); ++it)
	{
		typename Container<int>::iterator pos = std::lower_bound(large.begin(), large.end(), *it);
		large.insert(pos, *it);
	}
}

static void mergeVector(std::vector<std::pair<int, int>> & arr, int l, int m, int r) {
    int i, j, k;
    int leftHalf = m - l + 1;
    int rightHalf = r - m;
    std::vector<std::pair<int, int>> L(leftHalf);
    std::vector<std::pair<int, int>> R(rightHalf);

    for (i = 0; i < leftHalf; i++)
        L[i] = arr[l + i];
    for (j = 0; j < rightHalf; j++)
        R[j] = arr[m + 1 + j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < leftHalf && j < rightHalf) {
        if (L[i].first <= R[j].first) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < leftHalf) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < rightHalf) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

static void mergeSortVector(std::vector<std::pair<int, int>> &pairs, int l, int r)
{
    if (l < r){
        int m = l + (r - l) / 2;
        mergeSortVector(pairs, l, m);
        mergeSortVector(pairs, m + 1, r);
        mergeVector(pairs, l, m, r);
    }
    else
        return;
}

static void mergeInsertSortVector(std::vector<int> &arr){

    int odd = -1;
    if (arr.size() == 1)
        return ;
    int size = arr.size();
    for (int i = 0; i < size - 1; i+= 2){
        if (arr[i] < arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    int pairSize;
    std::vector<int> temp;
    if (size % 2)
    {
        odd = arr[size - 1];
        arr.erase(arr.end() - 1);
    }
    pairSize = size / 2;
    std::vector<std::pair<int, int>> pairs;
    for (int i = 0; i < size - 1; i+=2)
    {
        int num1 = arr[i];
        int num2 = arr[i + 1];
        pairs.push_back(std::make_pair(num1, num2));
    }
    mergeSortVector(pairs, 0, pairs.size() - 1);
    arr.clear();
    for (int i = 0; i < pairSize; i++)
    {
        arr.push_back(pairs[i].first);
        temp.push_back(pairs[i].second);
    }
    if (odd >= 0)
        temp.push_back(odd);
    arr.insert(arr.begin(), temp[0]);
    temp.erase(temp.begin());
    insertionSort(arr, temp);
}

static void mergeDeque(std::deque<std::pair<int, int>> & arr, int l, int m, int r) {
    int i, j, k;
    int leftHalf = m - l + 1;
    int rightHalf = r - m;
    std::deque<std::pair<int, int>> L(leftHalf);
    std::deque<std::pair<int, int>> R(rightHalf);

    for (i = 0; i < leftHalf; i++)
        L[i] = arr[l + i];
    for (j = 0; j < rightHalf; j++)
        R[j] = arr[m + 1 + j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < leftHalf && j < rightHalf) {
        if (L[i].first <= R[j].first) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < leftHalf) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < rightHalf) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

static void mergeSortDeque(std::deque<std::pair<int, int>> &pairs, int l, int r)
{
    if (l < r){
        int m = l + (r - l) / 2;
        mergeSortDeque(pairs, l, m);
        mergeSortDeque(pairs, m + 1, r);
        mergeDeque(pairs, l, m, r);
    }
    else
        return;
}

static void mergeInsertSortDeque(std::deque<int> &arr){

    int odd = -1;
    if (arr.size() == 1)
        return ;
    int size = arr.size();
    for (int i = 0; i < size - 1; i+= 2){
        if (arr[i] < arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    int pairSize;
    std::deque<int> temp;
    if (size % 2)
    {
        odd = arr[size - 1];
        arr.erase(arr.end() - 1);
    }
    pairSize = size / 2;
    std::deque<std::pair<int, int>> pairs;
    for (int i = 0; i < size - 1; i+=2)
    {
        int num1 = arr[i];
        int num2 = arr[i + 1];
        pairs.push_back(std::make_pair(num1, num2));
    }
    mergeSortDeque(pairs, 0, pairs.size() - 1);
    arr.clear();
    for (int i = 0; i < pairSize; i++)
    {
        arr.push_back(pairs[i].first);
        temp.push_back(pairs[i].second);
    }
    if (odd >= 0)
        temp.push_back(odd);
    arr.insert(arr.begin(), temp[0]);
    temp.erase(temp.begin());
    insertionSort(arr, temp);
}
 
PmergeMe::PmergeMe(std::stringstream &ss){
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

	std::cout << "Before: ";
    for (int i : vec) std::cout << i << " ";
    std::cout << std::endl;

	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    mergeInsertSortVector(vec);
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> vecTime = end - start;
	
	start = std::chrono::high_resolution_clock::now();
    mergeInsertSortDeque(deq);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> deqTime = end - start;

    if (vec.size() != deq.size())
    {
        std::cout << "FAIL: result is not matching" << std::endl;
        return ;
    }
    std::cout << "After: ";
    int size = vec.size();
    for (int i = 0; i < size; i++){
        if (vec[i] == deq[i] && i < size - 1 && vec[i] <= vec[i + 1] && deq[i] <= deq[i + 1])
            std::cout << vec[i] << " ";
        else if (vec[i] == deq[i] && i == size - 1 && vec[i] >= vec[i - 1] && deq[i] >= deq[i - 1])
            std::cout << vec[i] << " ";
        else
        {
            std::cout << "FAIL" << std::endl;
            return;
        }
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << vecTime.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << deqTime.count() << " us" << std::endl;
}