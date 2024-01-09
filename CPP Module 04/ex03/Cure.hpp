#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

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