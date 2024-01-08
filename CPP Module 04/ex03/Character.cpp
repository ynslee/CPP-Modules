#include "Character.hpp"

Character::Character() : _name("random") {
	for (int i = 0; i < 4; i++) {
    	this->inventory[i] = NULL;
	}
};

Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i < 4; i++) {
    	this->inventory[i] = NULL;
	}
};

Character::Character(const Character& other){
	if (this->_name != other._name)
		this->_name = other._name;
	
}