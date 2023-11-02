//cin, cout standard input, standard uotput
//<<, >> allow you to copy data flows
//std::endl means carriage return


#include <iostream>

int main(void){
	char buff[512];

	std::cout << "Hello World !" << std::endl;

	std::cout << "Intput a word: ";
	std::cin >> buff;
	std::cout << "You entered: ["<< buff << "]" << std::endl;

	return 0;
}