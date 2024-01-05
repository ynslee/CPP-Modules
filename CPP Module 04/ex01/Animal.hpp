#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal{
	protected:
		std::string _type;
	
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal &other);

		std::string		getType() const;
		void			setType(std::string type);
		void	virtual	makeSound() const;
};

#endif