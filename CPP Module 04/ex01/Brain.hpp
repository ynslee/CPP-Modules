#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain{
	private:
		std::string ideas[100];

	public:
		Brain();
		~Brain();
		Brain(const Brain &other);
		Brain& operator=(const Brain &other);

		void	setIdeas(unsigned int index, std::string idea);
		std::string	getIdeas(unsigned int index);
};


#endif