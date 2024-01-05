#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

	private:
		Brain*	notInUse;

	public:
		Dog();
		~Dog() override;
		Dog(const Dog &other);
		Dog& operator=(const Dog &other);
		void	makeSound() const override;
		Brain& getBrain();
};


#endif