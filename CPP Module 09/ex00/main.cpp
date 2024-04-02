#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2){
		std::cerr << "Error, please put a database. ex) ./btc input.txt" << std::endl;
		exit (1);
	}
	try {
		Bitcoin bitcoin(argv[1]);
	} catch (std::exception &e){
		std::cout << &e << std::endl; 
	}
}