
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int	main(void)
{
  {
    std::cout << "1. brain example test" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;
  }
  {
    std::cout << "2. brain mandatory test" << std::endl;

	Animal* animals[10];

    for (int i = 0; i < 10; i++) {
		if (i % 2)
			animals[i] = new Cat;
		else
			animals[i] = new Dog;
	}

	for (int i = 0; i < 10; i++){
		delete animals[i];
	}
  }
  {
    std::cout << "3. brain deep copy test" << std::endl;

    Cat cat;
    Dog dog;

	dog.getBrain().setIdeas(4, "I would love to pee on that rock!🐕");
	cat.getBrain().setIdeas(1, "Don't provoke me or I'll break your water glass🥛");

	std::cout << "\n-------Time for some doggos!----------\n" << std::endl;
	Dog copyDog(dog);
	for (int i = 0; i < 5; i++){
		std::cout << "dog's first five idea is " << "[" << i << "]" << dog.getBrain().getIdeas(i) << std::endl;
		}
	for (int i = 0; i < 5; i++){
		std::cout << "copy dog's first five idea is " << "[" << i << "]" << copyDog.getBrain().getIdeas(i) << std::endl;
		}

	std::cout << "\n\n****** copy dog starts to think new idea! ******\n" << std::endl;
	copyDog.getBrain().setIdeas(0, "OOOOOOOh that is a nice stick!🎋");

	std::cout << "dog's first idea is " << dog.getBrain().getIdeas(0) << std::endl;
	std::cout << "copy dog's first idea is " << copyDog.getBrain().getIdeas(0) << std::endl;

	std::cout << "\n-------Time for some whiskers!----------\n" << std::endl;
	Cat copyCat(cat);
	for (int i = 0; i < 5; i++){
		std::cout << "cat's first five idea is " << "[" << i << "]" << cat.getBrain().getIdeas(i) << std::endl;
		}
	for (int i = 0; i < 5; i++){
		std::cout << "copy cat's first five idea is " << "[" << i << "]" << copyCat.getBrain().getIdeas(i) << std::endl;
		}

	std::cout << "\n\n****** copy cat starts to think new idea! ******\n" << std::endl;
	copyCat.getBrain().setIdeas(0, "Is that a catnip I am smelling? 🌱");

	std::cout << "cat's first idea is " << cat.getBrain().getIdeas(0) << std::endl;
	std::cout << "copy cat's first idea is " << copyCat.getBrain().getIdeas(0) << std::endl;
	
  }
	return 0;
}
