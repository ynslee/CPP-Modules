#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

/*Used forward class declaration to avoid cicular dependency which could happen with header inclusion only
this is to avoid compilation errors*/

class ICharacter;

class Cure: public AMateria {
		public:
			Cure();
			virtual ~Cure() override;
			Cure(const Cure& ohter);
			Cure& operator=(const Cure& other);
			virtual AMateria* clone() const override;
			virtual void use(ICharacter& target) override;
};

#endif