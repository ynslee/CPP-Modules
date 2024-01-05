#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal{
	protected:
		std::string _type;
	
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal &other);

		std::string		getType() const;
		void			setType(std::string type);
		void			makeSound() const;
};

#endif