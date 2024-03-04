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
	(void)other;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t serial = reinterpret_cast <uintptr_t> (ptr);
	return (serial);
}

Data* Serializer::deserialize(uintptr_t raw) {
	Data* deserial = reinterpret_cast <Data*> (raw);
	return (deserial);
}