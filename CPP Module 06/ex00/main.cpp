#include <iostream>

int main()
{
	std::string	content;

	std::cout << "******************************" << std::endl;
	std::cout << "**Scalar Converter initiated**" << std::endl;
	std::cout << "******************************" << std::endl;
	while (54)
	{
		std::getline (std::cin, content, '\n');
		if (std::cin.eof() == 1)
			exit(0);
		if (content.empty())
		{
			std::cout << "Empty argument! Please type something!" << std::endl;
			continue ;
		}

	}
	return 0;
}