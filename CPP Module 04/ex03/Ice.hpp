#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class ICharacter;

class Ice: public AMateria {
		public:
			Ice();
			virtual ~Ice() override;
			Ice(const Ice& other);
			Ice& operator=(const Ice& other);
			virtual AMateria* clone() const override;
			virtual void use(ICharacter& target) override;
};

#endif