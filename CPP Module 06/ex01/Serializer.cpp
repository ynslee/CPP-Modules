#include "Serializer.hpp"

Serializer::Serializer(void) {
	return ;
}

Serializer::~Serializer(void) {
	return ;
}

Serializer::Serializer(Serializer const& other) {
	*this = other;
	return ;
}

Serializer& Serializer::operator=(Serializer const& other) {

	if (this == &other){	
		static_cast<void>(other);
	}	
	return *this;
}

/**
 * @brief uintptr_t is a powerful tool where direct manipulation of memory addresses as integers
 * should be used with caution to avoid bugs or portability issues 
 */
uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t serial = reinterpret_cast<uintptr_t>(ptr);
	return serial;
}

Data* Serializer::deserialize(uintptr_t raw) {
	Data* deserial = reinterpret_cast<Data *>(raw);
	return deserial;
}