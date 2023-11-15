
#include <iostream>

/*
int score [5] {100,95,97,87,88};
int array [] {1,2,3} -> calculates size automatically
int array[10] {1,2,3,4,5} -> rest of them becomes zero*/

int main(){

	char abc[] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << "\nfirst abc is: " << abc[0] << std::endl;
	std::cout << "last abc is: " << abc[4] << std::endl;


	double hi_temps[] = {90.1, 89.8, 77.5, 81.6};
	std::cout << "highest temp is : "<< hi_temps[0] << std::endl;
	hi_temps[0] = 100.7;
	std::cout << "highest temp is : "<< hi_temps[0] << std::endl;

	int scores[] = {1,2,3,4,5};
	std::cout << "first is : " << scores[0] << std::endl;
	std::cout << "second is : " << scores[1] << std::endl;
	std::cout << "third is : " << scores[2] << std::endl;
	std::cout << "fourth is : " << scores[3] << std::endl;
	std::cout << "fifh is : " << scores[4] << std::endl;

	return (0);
}