
#include "Iter.hpp"

int main(void)
{
	int numbers[] = {1, 2, 3, 4, 5};
	std::string str[] = {"chuchi", "chacha", "chichi", "chuchu", "chacho"};

	std::cout << "Numbers array is : " << std::endl;
	iter(numbers, 5, print<int>);
	std::cout << "increasing number of 1 fucntion applied to each element" << std::endl;
	iter(numbers, 5, addOne<int>);
	std::cout << "Numbers array is now : " <<std::endl;
	iter(numbers, 5, print<int>);

	std::cout << "str array is : " << std::endl;
	::iter(str, 5, print<std::string>);
	std::cout << "adding string '.add' to each element" << std::endl;
	::iter(str, 5, addString<std::string>);
	std::cout << "str array is now : " << std::endl;
	::iter(str, 5, print<std::string>);

	return 0;
}