
#include "Iter.hpp"

int main(void)
{
	int numbers[] = {1, 2, 3, 4, 5};
	std::string str[] = {"chuchi", "chacha", "chichi", "chuchu", "chacho"};

	std::cout << "----------TEST CASE ONE-------------\n" << std::endl;
	std::cout << "Numbers array is : " << std::endl;
	iter(numbers, 5, print<int>);
	std::cout << "increasing number of 1 fucntion applied to each element" << std::endl;
	iter(numbers, 5, addOne<int>);
	for (int i = 0; i < 5; i++)
	{
		int check_list[] = {2, 3, 4, 5, 6};
		if (numbers[i] != check_list[i])
		{
			std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
		}
	}
	std::cout << "\033[32mTEST OKAY\033[0m" <<std::endl;
	std::cout << "Numbers array is now : " <<std::endl;
	iter(numbers, 5, print<int>);

	std::cout << "\n----------TEST CASE TWO-------------\n" << std::endl;

	std::cout << "str array is : " << std::endl;
	::iter(str, 5, print<std::string>);
	std::cout << "adding string '.add' to each element" << std::endl;
	::iter(str, 5, addString<std::string>);
	for (int i = 0; i < 5; i++)
	{
		std::string result[] = {"chuchi.add", "chacha.add", "chichi.add", "chuchu.add", "chacho.add"};
		if (str[i].compare(result[i]) != 0)
		{
			std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
		}
	}
	std::cout << "\033[32mTEST OKAY\033[0m" <<std::endl;
	std::cout << "str array is now : " << std::endl;
	::iter(str, 5, print<std::string>);

	return 0;
}

// #include <iostream>

// class Awesome
// {
// 	public:
// 		Awesome(void): _n(42) {}
// 		int get(void) const { return _n; }
// 	private:
// 		int _n;
// };

// std::ostream& operator<<(std::ostream& o, Awesome const& rhs) { o << rhs.get(); return o; }

// template<typename T>
// void print(T const& x) { std::cout << x << std::endl; }

// int main(void)
// {
// 	int tab[] = {0, 1, 2, 3, 4};
// 	Awesome tab2[5];
// 	iter(tab, 5, print);
// 	iter(tab2, 5, print);

// 	return 0;
// }