
#include "Whatever.hpp"
#include <iostream>

int main(void) {

	int a = 6;
	int b = 3;
	char c = 'A';
	char d = 'Z';
	std::string str = "Hello";
	std::string str2 = "World";

	std::cout << "----------TEST MIN---------" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "str= " << str << ", str2 = " << str2 << std::endl;
	std::cout << "\n\nFinding Min initiating.......bzzzz\n" << std::endl;	std::cout << "---------------------------" << std::endl;

	if (::min(a, b) == a)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << " ::min is " << ::min(a, b) << std::endl;
	if (::min(c, d) == d)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << " min is " << ::min(c, d) << std::endl;
	if (::min(str, str2) == str2)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << " min is " << ::min(str, str2) << std::endl;
	std::cout << "---------------------------\n" << std::endl;

	std::cout << "----------TEST MAX---------" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "str= " << str << ", str2 = " << str2 << std::endl;
	std::cout << "\n\nFinding Max initiating.......bzzzz\n" << std::endl;

	if (::max(a, b) == b)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << " max is " << ::max(a, b) << std::endl;
	if (::max(c, d) == c)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << " max is " << ::max(c, d) << std::endl;
	if (::max(str, str2) == str)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << " max is " << ::max(str, str2) << std::endl;
	std::cout << "---------------------------\n" << std::endl;

	std::cout << "\n----------TEST SWAP--------" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "str= " << str << ", str2 = " << str2 << std::endl;
	std::cout << "\n\nSwapping initiating.......bzzzz\n" << std::endl;

	swap(a, b);
	swap(c, d);
	swap(str, str2);

	if (a == 2)
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << " a is " << a << " b is " << b << std::endl;
	if (c == 'A')
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << " c is " << c << " d is " << d << std::endl;
	if (str == "Hello")
		std::cerr << "\033[33mTEST FAIL\033[0m" << std::endl;
	else
		std::cout << "\033[32mTEST OKAY\033[0m" << " str is " << str << " str2 is " << str2 << std::endl;
	
	std::cout << "---------------------------" << std::endl;

  return (0);
}

// int main( void ) {
// 	int a = 2;
// 	int b = 3;
// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return 0;
// }