#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class Character : public ICharacter{
	private:
		std::string	_name;
		AMateria	*inventory[4];

	public:
		Character();
		Character(const std::string& name);
		Character(const Character& other);
		Character& operator=(const Character &other);
		virtual ~Character() override;
		virtual std::string const & getName() const override;
		virtual void equip(AMateria* m) override;
		virtual void unequip(int idx) override;
		virtual void use(int idx, ICharacter& target) override;
};

#endif