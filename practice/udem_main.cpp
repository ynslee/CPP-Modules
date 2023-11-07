
#include <iostream>

// int main()
// {
// 	int number;

// 	std::cout << "Enter your favorite number between 1 and 100: ";

// 	std::cin >> number;

// 	std::cout << "Amazing! That's my favorite number too!" << std::endl;
// 	std::cout << "No really!!, " << number << "is my favorite number!" << std::endl;


// 	return 0;
// }

// int main()
// {
// 	int num1;
// 	// int	num2;
// 	double	num3;

// 	// std::cout << "Enter a first integer: ";

// 	// std::cin >> num1;
// 	// std::cout << "Enter a second integer: ";

// 	// std::cin >> num2;

// 	// std::cout << "Enter 2 integers seperated with space: ";
// 	// std::cin >> num1 >> num2;
// 	// std::cout << "You entered: " << num1 << " and " << num2 << std::endl;
// 	// std::cout << "Enter a double: ";

// 	// std::cin >> num3;
// 	// std::cout << "You entered: " << num3;

// 	std::cout << "Enter an integer: ";
// 	std::cin >> num1;

// 	std::cout << "Enter a double: ";
// 	std::cin >> num3;

// 	std::cout << "The integer is: " << num1 << std::endl;
// 	std::cout << "And the double is: " << num3 << std::endl;

// 	return 0;
// }

int main(void)
{
	int width (0);
	int length (0);

	std::cout << "Enter width: ";
	std::cin >> width;
	std::cout << "Enter length: ";
	std::cin >> length;

	std::cout << "The area is " << width * length << " square feet" << std::endl;

	return 0;

}