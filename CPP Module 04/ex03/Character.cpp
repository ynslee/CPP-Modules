#include "Character.hpp"

Character::Character() : _name("random") {
	for (int i = 0; i < 4; i++) {
    	this->weapons[i] = NULL;
	}
};

Character::Character(const std::string name) : _name(name) {
	for (int i = 0; i < 4; i++) {
    	this->weapons[i] = NULL;
	}
};

Character::Character(const Character& other) : _name(other._name) {
	for(int i = 0; i < 4; i++){
		if (this->weapons[i])
			delete weapons[i];
		if (other.weapons[i])
			this->weapons[i] = other.weapons[i]->clone();
	}
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        delete weapons[i];
    }
}

Character& Character::operator=(const Character& other)
{
    if (this == &other)
        return *this;
	else{
		this->_name = other._name;
		for (int i = 0; i < 4; i++){
			delete weapons[i];
			weapons[i] = other.weapons[i]->clone();
		}
	}
    return *this;
}

const std::string& Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria* m)
{
    if (m = NULL)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (weapons[i] = NULL)
        {
            weapons[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return ;
    weapons[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= (int)4 || !weapons[idx])
        return ;
    weapons[idx]->use(target);
}