#include "PmergeMe.hpp"

int main(int argc, char **argv){

	if (argc < 2)
	{
		std::cout << "please provide positive integers to sort as a string." << std::endl;
		return 1;
	}
	std::stringstream ss;
	for (int i = 1; i < argc; ++i) {
       ss << argv[i] << " ";
   	}
	PmergeMe pmerge(ss);
	return 0;
}