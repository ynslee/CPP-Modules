#include "Serializer.hpp"
#include <string>

int main(void)
{
	Data data ;
	uintptr_t serialised;
	Data* deserialised;

	data.secret = 42;

	std::cout << "Data's value is " << data.secret << std::endl;

	std::cout << "Data structure's address is: " << &data << std::endl;

	serialised = Serializer::serialize(&data);
	std::cout << "Serialised address is: " << serialised << std::endl;

	deserialised = Serializer::deserialize(serialised);
	std::cout << "Deserialised address is: " << deserialised << std::endl;

	std::cout << "Deserialised address's pointing value is: " << deserialised->secret << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	Data *res = Serializer::deserialize(raw);

	std::cout << "raw is : " << raw << " and &data is " << &data << std::endl;
	std::cout << "res is : " << res << " and data value is " << res->secret << std::endl;

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