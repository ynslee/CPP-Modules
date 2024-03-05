#pragma once

# include <iostream>
template <typename T>
void print(T &x){
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
template <typename T1, typename T2>
void iter(T1* array, T2 length, void (*f)(T1 &)){
	for (int i = 0; i < length; i++){
		f(array[i]);
	}
}
