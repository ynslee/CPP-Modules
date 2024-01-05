#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain is constructed 🧠" << std::endl;
	char idea = 'A';
	for (int i = 0; i < 100; i++){
		this->ideas[i] = idea;
		idea++;
		if (idea == '{')
			idea = 'A';
	}
}

Brain::Brain(const Brain &other){
	std::cout << "Brain copy is constructed 🧠" << std::endl;
	*this = other;
}

Brain::~Brain(){
	std::cout << "Brain is destroyed now🚮" << std::endl;
}

Brain &Brain::operator=(const Brain &other){
	std::cout << "Brain copy assignment constructor is called 🧠 🖨 🧠" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++) {
		this->ideas[i] = other.ideas[i];
  		}
	}
	return *this;
}

void	Brain::setIdeas(unsigned int index, std::string idea){
	if (index < 0 || index > 99)
	{
		std::cout << "Can't set the ideas since index is not correct :( please choose between (0 - 99)" << std::endl;
		return ;
	}
	this->ideas[index] = idea;
}

std::string	Brain::getIdeas(unsigned int index){
	if (index < 0 || index > 99){
		std::cout << "I can't have more than 100 ideas! Also my idea is only positive!" << std::endl;
		return ;
	}
	return(this->ideas[index]);
}