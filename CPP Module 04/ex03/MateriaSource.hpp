#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource {
	private:
		AMateria* inventory[4];

	public:
		MateriaSource();
		virtual ~MateriaSource() override;
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		void learnMateria(AMateria* _materia) override;
		AMateria *createMateria(std::string const & type) override;
};

# endif