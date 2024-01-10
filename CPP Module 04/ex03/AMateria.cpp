# include "AMateria.hpp"

AMateria::AMateria() : _type("random") {
	// std::cout << "[ AMateria ] default constructor called" << std::endl;
}

AMateria::~AMateria() {
	// std::cout << "[ AMateria ] destructor for [" << this->_type << "] called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type) {
	// std::cout << "[ AMateria ] constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
	// std::cout << "[ AMateria ] copy constructor called" << std::endl;
};

AMateria&	AMateria::operator=(const AMateria &other){
	if (this->_type != other._type){
		this->_type = other._type;
	}
	return *this;
}

std::string	const&	AMateria::getType() const {
	return(this->_type);
}

void	AMateria::use(ICharacter &target){
	 std::cout << "[ AMateria ]'s use does nothing to " << target.getName() << ", as this is just base function" << std::endl;
}
