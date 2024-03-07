#pragma once

# include <iostream>
template <typename T>
void print(T const &x){
	std::cout << x << std::endl;
}

template <typename T>
void addOne(T &x){
	x++;
}

template <typename T>
void addString(T &x){
	x += ".add";
}

// to avoid function template to get confused with pointer type references, it is better to have
// the third parameter as a just a function pointer, not a typename input
template <typename T>
void iter(T* array, size_t length, void (*f)(T const &)){
	for (size_t i = 0; i < length; i++){
		f(array[i]);
	}

}
template <typename T>
void iter(T* array, size_t length, void (*f)(T &)){
	for (size_t i = 0; i < length; i++){
		f(array[i]);
	}
}
