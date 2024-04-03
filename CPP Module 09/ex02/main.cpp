#include "PmergeMe.hpp"

int main(int argc, char **argv){

	if (argc > 1)
	{	std::stringstream ss;
		for (int i = 1; i < argc; ++i) {
        ss << argv[i] << " ";
    	}
		PmergeMe pmerge(ss);
	}
	return 0;
}