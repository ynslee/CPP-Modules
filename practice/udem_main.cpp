
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
	// int width (0);
	// int length (0);

	std::cout << "Hello welcome to Carpmet cleaning service" << std::endl;
	std::cout << "\nHow many small rooms would you like clearned? ";
	int num_small_rooms (0);
	std::cin >> num_small_rooms;
	std::cout << "\nHow many large rooms would you like clearned? ";

	int num_large_rooms (0);
	std::cin >> num_large_rooms;
	const double price_small (25);
	const double price_large (35);
	const double sales_tax (0.06);
	const int estimate_expiry(30);

	std::cout << "nEstimate for carpet cleaning services" << std::endl;
	std::cout << "Number of small rooms : " << num_small_rooms << std::endl;
	std::cout << "Number of large rooms : " << num_large_rooms << std::endl;
	std::cout << "Price per small rooom : $" << price_small << std::endl;
	std::cout << "Price per large rooom : $" << price_large << std::endl;
	std::cout << "Cost :$" << (price_small * num_small_rooms) + (price_large * num_large_rooms) << std::endl;
	std::cout << "TAX : $" << ((price_small * num_small_rooms) + (price_large * num_large_rooms)) * sales_tax << std::endl;

	std::cout << "========================================" << std::endl;
	std::cout << "Total estimate: $" << (price_small * num_small_rooms) + (price_large * num_large_rooms) + ((price_small * num_small_rooms) + (price_large * num_large_rooms)) * sales_tax << std::endl;
	std::cout << "This estimate is valid for " << estimate_expiry << " days" << std::endl;

	std::cout << std::endl;


	// std::cout << "Enter width: ";
	// std::cin >> width;
	// std::cout << "Enter length: ";
	// std::cin >> length;

	// std::cout << "The area is " << width * length << " square feet" << std::endl;

	return 0;

}