#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for(int i = 0; i < 4; i++){
		this->inventory[i] = NULL;
	}
	
	// std::cout << "[ MateriaSource ] default constructor called" << std::endl;
};

MateriaSource::~MateriaSource() {
	for(int i = 0; i < 4; i++){
		if (this->inventory[i])
			delete this->inventory[i];
	}
	// std::cout << "[ MateriaSource ] destructor called" << std::endl;
};

MateriaSource::MateriaSource(const MateriaSource& other) {
	for(int i = 0; i < 4; i++){
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	// std::cout << "[ MateriaSource ] copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other){
	for(int i = 0; i < 4; i++){
		if (this->inventory[i]){
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
		else
			this->inventory [i]= NULL;
	}
	for(int i = 0; i < 4; i++){
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
	}
	// std::cout << "[ MateriaSource ] copy assignment constructor called" << std::endl;
	return *this;
}

void	MateriaSource::learnMateria(AMateria* m){
	if (!m)
    	return;
	for (int i = 0; i < 4; i++) {
		if (!inventory[i]) {
			inventory[i] = m;
			return;
		}
	}
	delete m;
	m = NULL;
}

AMateria*	MateriaSource::createMateria(std::string const &type){
	for (int i = 0; i < 4; i++) {
		if (inventory[i] && inventory[i]->getType() == type) {
			return inventory[i]->clone();
		}
	}
	return NULL;
}
