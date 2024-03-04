#pragma once

#include <iostream>
#include <string>

struct Data
{
	int secret;
};

// reinterpret_cast <new_type> (expression) : used to cast a pointer of data type into a pointer of another data type.
class Serializer
{

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer( Serializer const & src );
		~Serializer();

		Serializer &		operator=( Serializer const & rhs );
};