#include "PmergeMe.hpp"
#include <deque>
#include <vector>
#include <algorithm>
#include <chrono>
#include <utility>

void print_vpairs(std::vector<std::pair<int, int>> & arr){
    int size = arr.size();

    for (int i = 0; i < size; i++){
        std::cout << arr[i].first << " " << arr[i].second << std::endl;
    }
}


template <typename T>
static void insertionSort(T &arr, int n)
{
    int size = arr.size();
    int j = 0;

    for (j = size - 2; j >= 0; j--)
    {
        if (arr[j] < n && arr[j + 1] > n)
            break;
    }
    arr.insert(arr.begin() + j + 1, n);
}

static void mergeVector(std::vector<std::pair<int, int>> & arr, int l, int m, int r) {
    int i, j, k;
    int leftHalf = m - l + 1;
    int rightHalf = r - m;
    std::vector<std::pair<int, int>> L(leftHalf);
    std::vector<std::pair<int, int>> R(rightHalf);

    // std::cout << "l is " << l << ", m is " << m << ", r is " << r << std::endl;
    // std::cout << "leftHalf is " << leftHalf << std::endl;
    // std::cout << "rightHalf is " << rightHalf << std::endl;

    for (i = 0; i < leftHalf; i++)
        L[i] = arr[l + i];
    // for (size_t s = 0; s < L.size(); s++)
    //     std::cout << "left: " << L[i].first << " " << L[i].second << std::endl;
    for (j = 0; j < rightHalf; j++)
        R[j] = arr[m + 1 + j];
    // for (size_t s = 0; s < R.size(); s++)
    //     std::cout << "right: " << R[i].first << " " << R[i].second << std::endl;

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

    // Copy the remaining elements of L[], if there are any
    while (i < leftHalf) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
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
        // std::cout << "m is " << m << std::endl;
        mergeSortVector(pairs, l, m);
        mergeSortVector(pairs, m + 1, r);
        mergeVector(pairs, l, m, r);
    }
    else
        return;
}

void insertionSortVec(std::vector<int> &arr, int n)
{
    int size = arr.size();
    int j = 0;

    for (j = size - 2; j >= 0; j--)
    {
        if (arr[j] < n && arr[j + 1] > n)
            break;
    }
    arr.insert(arr.begin() + j + 1, n);
}

void mergeInsertSortVector(std::vector<int> &arr){

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
    std::cout << arr.size() << std::endl;
    int pairSize;
    std::vector<int> temp;
    if (size % 2)
    {
        std::cout << "last one is " << arr[size - 1] << std::endl;
        odd = arr[size - 1];
        arr.erase(arr.end() - 1);
    }
    pairSize = size / 2;
    std::cout << "pair size is " << pairSize << std::endl;
    std::vector<std::pair<int, int>> pairs;
    for (int i = 0; i < size - 1; i+=2)
    {
        int num1 = arr[i];
        int num2 = arr[i + 1];
        pairs.push_back(std::make_pair(num1, num2));
    }
    // for (int i = 0; i < pairSize; i++)
    //     std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
    mergeSortVector(pairs, 0, pairs.size() - 1);
    // for (int i = 0; i < pairSize; i++)
    //     std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
    arr.clear();
    for (int i = 0; i < pairSize; i++)
    {
        arr.push_back(pairs[i].first);
        temp.push_back(pairs[i].second);
    }
    if (odd >= 0)
        temp.push_back(odd);
    // for (size_t i = 0; i < arr.size(); i++)
    //     std::cout << "arr is " << arr[i] << std::endl;
    // for (size_t i = 0; i < temp.size(); i++)
    //     std::cout << "temp is " << temp[i] << std::endl;
    arr.insert(arr.begin(), temp[0]);
    temp.erase(temp.begin());
    for (size_t i = 0; i < temp.size(); i++)
        insertionSort(arr, temp[i]);
}

static void mergeDeque(std::deque<std::pair<int, int>> & arr, int l, int m, int r) {
    int i, j, k;
    int leftHalf = m - l + 1;
    int rightHalf = r - m;
    std::deque<std::pair<int, int>> L(leftHalf);
    std::deque<std::pair<int, int>> R(rightHalf);

    // std::cout << "l is " << l << ", m is " << m << ", r is " << r << std::endl;
    // std::cout << "leftHalf is " << leftHalf << std::endl;
    // std::cout << "rightHalf is " << rightHalf << std::endl;

    for (i = 0; i < leftHalf; i++)
        L[i] = arr[l + i];
    // for (size_t s = 0; s < L.size(); s++)
    //     std::cout << "left: " << L[i].first << " " << L[i].second << std::endl;
    for (j = 0; j < rightHalf; j++)
        R[j] = arr[m + 1 + j];
    // for (size_t s = 0; s < R.size(); s++)
    //     std::cout << "right: " << R[i].first << " " << R[i].second << std::endl;

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

    // Copy the remaining elements of L[], if there are any
    while (i < leftHalf) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
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
        // std::cout << "m is " << m << std::endl;
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
    std::cout << arr.size() << std::endl;
    int pairSize;
    std::deque<int> temp;
    if (size % 2)
    {
        std::cout << "last one is " << arr[size - 1] << std::endl;
        odd = arr[size - 1];
        arr.erase(arr.end() - 1);
    }
    pairSize = size / 2;
    std::cout << "pair size is " << pairSize << std::endl;
    std::deque<std::pair<int, int>> pairs;
    for (int i = 0; i < size - 1; i+=2)
    {
        int num1 = arr[i];
        int num2 = arr[i + 1];
        pairs.push_back(std::make_pair(num1, num2));
    }
    // for (int i = 0; i < pairSize; i++)
    //     std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
    mergeSortDeque(pairs, 0, pairs.size() - 1);
    // for (int i = 0; i < pairSize; i++)
    //     std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
    arr.clear();
    for (int i = 0; i < pairSize; i++)
    {
        arr.push_back(pairs[i].first);
        temp.push_back(pairs[i].second);
    }
    if (odd >= 0)
        temp.push_back(odd);
    // for (size_t i = 0; i < arr.size(); i++)
    //     std::cout << "arr is " << arr[i] << std::endl;
    // for (size_t i = 0; i < temp.size(); i++)
    //     std::cout << "temp is " << temp[i] << std::endl;
    arr.insert(arr.begin(), temp[0]);
    temp.erase(temp.begin());
    for (size_t i = 0; i < temp.size(); i++)
        insertionSort(arr, temp[i]);
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

    std::cout << "After: ";
    for (int i : vec) std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "After: ";
    for (int i : deq) std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << vecTime.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << deqTime.count() << " us" << std::endl;
}