#include "Character.hpp"

Character::Character() : _name("random") {
	for (int i = 0; i < 4; i++) {
    	this->inventory[i] = NULL;
	}
    for (int i = 0; i < MAX; i++) {
    	this->floor[i] = NULL;
	}
    // std::cout << "[ Character ] default constructor called" << std::endl;
};

Character::Character(const std::string name) : _name(name) {
	for (int i = 0; i < 4; i++) {
    	this->inventory[i] = NULL;
	}
    for (int i = 0; i < MAX; i++) {
    	this->floor[i] = NULL;
	}
    // std::cout << "[ Character ] constructor called" << std::endl;
};

Character::Character(const Character& other) : _name(other._name) {
	for(int i = 0; i < 4; i++){
        this->inventory[i] = NULL;
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
	}
    for (int i = 0; i < MAX; i++) {
    	this->floor[i] = NULL;
        if (other.floor[i])
            this->floor[i] = other.floor[i]->clone();
	}
    // std::cout << "[ Character ] copy constructor called" << std::endl;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
         delete this->inventory[i];
    }
    for (int i = 0; i < MAX; i++) {
        if (this->floor[i])
           delete this->floor[i];
    }
    // std::cout << "[ Character ] destructor called" << std::endl;
}

Character& Character::operator=(const Character& other)
{
	this->_name = other._name;
	for (int i = 0; i < 4; i++){
        if (this->inventory[i]){
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
    }
    for (int i = 0; i < 4; i++){
        if (other.inventory[i])
		    this->inventory[i] = other.inventory[i]->clone();
		else
            this->inventory[i] = NULL;
	}
    for (int i = 0; i < MAX; i++){
        if (this->floor[i]){
            delete this->floor[i];
            this->floor[i] = NULL;
        }
    }
    for (int i = 0; i < MAX; i++){
        if (other.floor[i])
		    this->floor[i] = other.floor[i]->clone();
        else
            this->floor[i] = NULL;
	}
    return *this;
}

const std::string& Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria* m)
{
    if (m == NULL)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return ;
        }
    }
    for (int i = 0; i < MAX; i++){
        if(floor[i] == NULL){
            floor[i] = m;
            break;
        }
    }
    delete m;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !inventory[idx])
        return ;
    for (int i = 0; i < MAX; i++){
        if(floor[i] == NULL){
            floor[i] = inventory[idx];
            inventory[idx] = NULL;
            break;
        }
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3 || !inventory[idx])
        return ;
    inventory[idx]->use(target);
}
