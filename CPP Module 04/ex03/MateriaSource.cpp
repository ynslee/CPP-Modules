#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for(int i = 0; i < 4; i++){
		this->inventory[i] = NULL;
	}
	std::cout << "[ MateriaSource ] default constructor called" << std::endl;
};

MateriaSource::~MateriaSource() {
	for(int i = 0; i < 4; i++){
		delete inventory[i];
	}
	std::cout << "[ MateriaSource ] destructor called" << std::endl;
};

MateriaSource::MateriaSource(const MateriaSource& other) {
	for(int i = 0; i < 4; i++){
		this->inventory[i] = other.inventory[i];
	}
	std::cout << "[ MateriaSource ] copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other){
	if (this == &other)
		return *this;
	for(int i = 0; i < 4; i++){
		if (this->inventory[i] != other.inventory[i])
			this->inventory[i] = other.inventory[i];
		else
			this->inventory[i] = NULL;
	}
	std::cout << "[ MateriaSource ] copy assignment constructor called" << std::endl;
	return *this;
}

void	MateriaSource::learnMateria(AMateria* _materia){
	if (!_materia)
    	return;
	for (int i = 0; i < 4; i++) {
		if (!inventory[i]) {
			inventory[i] = _materia;
			return;
		}
	}
	delete _materia;
}

AMateria*	MateriaSource::createMateria(std::string const &type){
	for (int i = 0; i < 4; i++) {
		if (inventory[i] && inventory[i]->getType() == type) {
			return inventory[i]->clone();
		}
	}
	return NULL;
}
