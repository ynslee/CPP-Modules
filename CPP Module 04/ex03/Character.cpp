#include "Character.hpp"

Character::Character() : _name("random") {
	for (int i = 0; i < 4; i++) {
    	this->inventory[i] = NULL;
	}
};

Character::Character(const std::string name) : _name(name) {
	for (int i = 0; i < 4; i++) {
    	this->inventory[i] = NULL;
	}
};

Character::Character(const Character& other){
	this->_name = other._name;
	 for (size_t i = 0; i < 4; i++)
    {
        delete inventory[i];
       inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : NULL;
    }
    return *this;
}



Character::Character(const Character& other)
:   _materias(),
    _name(other._name)
{
    *this = other;
}

Character::~Character()
{
    for (size_t i = 0; i < 4; i++)
    {
        delete inventory[i];
    }
}

Character& Character::operator=(const Character& other)
{
    if (this == &other)
        return *this;
    for (size_t i = 0; _materias_max < 4; i++)
    {
        delete _materias[i];
        _materias[i] = other._materias[i] ? other._materias[i]->clone() : NULL;
    }
    return *this;
}

const std::string& Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
    for (size_t i = 0; i < _materias_max; i++)
    {
        if (!_materias[i])
        {
            _materias[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= (int)_materias_max)
        return ;
    _materias[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= (int)_materias_max || !_materias[idx])
        return ;
    _materias[idx]->use(target);
}