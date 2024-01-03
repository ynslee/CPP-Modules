#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal{
	protected:
		std::string _type;
	
	public:
		Animal();
		~Animal();
		Animal(const Animal& other);
		Animal& opeartor=(const Animal& other);

		std::string	getType() const;
		void		setType(std::string type);
		void 		makeSound();
};

#endif