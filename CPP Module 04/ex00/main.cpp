
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  {
	std::cout << "1. Dynamic allocation on the heap for the object and use pointers for sound" << std::endl;

	const Animal* animal = new Animal();
	const Animal* doggo = new Dog();
	const Animal* whiskers = new Cat();
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << doggo->getType() << " goes ";
	doggo->makeSound();

	std::cout << whiskers->getType() << " goes ";
	whiskers->makeSound();

	std::cout << animal->getType() << " goes ";
	animal->makeSound();

	std::cout << wrongCat->getType() << " goes ";
	wrongCat->makeSound();

	std::cout << wrongAnimal->getType() << " goes ";
	wrongAnimal->makeSound();

	delete animal;
	delete doggo;
	delete whiskers;
	delete wrongAnimal;
	delete wrongCat;
  }
  {
	std::cout << "\n\n2. Creates on the stack and test the sound" << std::endl;

	Cat whiskers;
	Dog doggo;
	Animal animal;
	WrongCat wrongCat;
	WrongAnimal wrongAnimal;

	std::cout << whiskers.getType() << " goes ";
	whiskers.makeSound();

	std::cout << doggo.getType() << " goes ";
	doggo.makeSound();

	std::cout << animal.getType() << " goes ";
	animal.makeSound();

	std::cout << wrongCat.getType() << " goes ";
	wrongCat.makeSound();

	std::cout << wrongAnimal.getType() << " says ";
	wrongAnimal.makeSound();
  }
  {
	std::cout << "\n\n3. Subejct's example test for animal" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
  }
  {
	std::cout << "\n\n4. Subject's example test for wrong animal" << std::endl;

	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();

	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
  }
  return 0;
}
