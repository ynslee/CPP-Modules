#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria {
		public:
			Ice();
			virtual ~Ice() override;
			virtual AMateria* clone() const;
			virtual void use(ICharacter& target) override;
};

#endif