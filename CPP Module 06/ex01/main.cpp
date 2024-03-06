#include "Serializer.hpp"
#include <string>

int main(void)
{
	{
		std::cout << "------------TEST 1------------" << std::endl;
		Data data ;
		uintptr_t serialised;
		Data* deserialised;

		data.secret = 42;

		std::cout << "Data's value is " << data.secret << std::endl;

		std::cout << "Data structure's address is: " << &data << std::endl;

		serialised = Serializer::serialize(&data);
		std::cout << "Address saved as unsigned integer is: " << serialised << std::endl;

		deserialised = Serializer::deserialize(serialised);
		std::cout << "Deserialised address is: " << deserialised << std::endl;

		std::cout << "Deserialised address's pointing value is: " << deserialised->secret << std::endl;
	}
	{
		std::cout << "\n\n------------TEST 2------------" << std::endl;
		Data data;
		uintptr_t raw = Serializer::serialize(&data);
		Data *res = Serializer::deserialize(raw);

		data.secret = 123;

		std::cout << "&data is : " << &data << " and data value is : " << data.secret << "and serialised raw is : " << raw << std::endl;
		std::cout << "res is : " << res << " and res value is : " << res->secret << std::endl;
	}
	return (0);
}

// int main()
// {
// 	{
// 		std::cout << "------------TEST 1------------" << std::endl;
// 		int value = 55;
// 		Data data;
// 		data.secret = value;

// 		std::cout << "SERIALIZING....." << std::endl;
// 		uintptr_t serialized = Serializer::serialize(&data);
// 		std::cout << "DE-SERIALIZING....." << std::endl;
// 		Data *deserialized = Serializer::deserialize(serialized);

// 		if (deserialized->secret != 100)
// 		{
// 			std::cerr << "\033[33mFAIL:\nDE-SERIALIZED DATA SHOULD BE " << value << "\nBUT WAS" << deserialized->secret << " \033[0m" << std::endl;
// 			std::cout << "------------------------------" << std::endl;
// 		}
// 		else
// 			std::cout << "\033[32mOKAY\033[0m" << std::endl;
// 	}

// 	{
// 		std::cout << "------------TEST 2------------" << std::endl;
// 		int value = -55;
// 		Data data;
// 		data.secret = value;

// 		std::cout << "SERIALIZING....." << std::endl;
// 		uintptr_t serialized = Serializer::serialize(&data);
// 		std::cout << "DE-SERIALIZING....." << std::endl;
// 		Data *deserialized = Serializer::deserialize(serialized);

// 		if (deserialized->secret != -100)
// 		{
// 			std::cerr << "\033[33mFAIL:\nDE-SERIALIZED DATA SHOULD BE " << value << "\nBUT WAS" << deserialized->secret << " \033[0m" << std::endl;
// 			std::cout << "------------------------------" << std::endl;
// 		}
// 		else
// 			std::cout << "\033[32mOKAY\033[0m" << std::endl;
// 	}
// }