#pragma once

# include <iostream>

//typename can be changed into class, essentially the same thing
template <typename T>
T max(T a, T b){
	return (a > b) ? a : b;
}

template <typename T>
T min(T a, T b){
	return (a < b) ? a : b;
}

template <typename T>
void swap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
}


