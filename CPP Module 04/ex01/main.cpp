
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <memory>
#include <string>

#define RESET "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define RED  "\033[31m"

int	main(void)
{
  {
    std::cout << "1. brain example test\n" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;
  }
  {
    std::cout << "\n\n2. brain mandatory test\n" << std::endl;

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
    std::cout << "\n\n3. brain deep copy test\n" << std::endl;

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

	std::cout << "\n\n********cat = copy cat now!!********\n" << std::endl;
	
	cat = copyCat;
	std::cout << "Now cat's first idea is " << cat.getBrain().getIdeas(0) << std::endl;
	std::cout << "Now copy cat's first idea is " << copyCat.getBrain().getIdeas(0) << std::endl;
	std::cout << "Address of cat's first idea- \n";
	cat.objectAddress();
	std::cout << "Now copy cat's first idea- \n";
	copyCat.objectAddress();
	std::cout << "\n\n" << std::endl;	
  }
	return 0;
}

// int main() {
//     {
//         std::cout << BLUE;
//         std::cout << "________________________________________________________________________________\n";
//         std::cout << "Exercise00: Animal base class's makeSound() is virtual:" << std::endl;
//         std::cout << "________________________________________________________________________________\n";
//         std::cout << CYAN;
//         std::cout << "-> Animal(), Dog() or Cat():\n";
//         std::cout << RESET;

//         Animal  an_animal;
//         std::cout << an_animal.getType() << " says: ";
//         an_animal.makeSound();

//         std::cout << std::endl;
//         Dog     a_dog;
//         std::cout << a_dog.getType() << " says: ";
//         a_dog.makeSound();

//         std::cout << std::endl;
//         Cat     a_cat;
//         std::cout << a_cat.getType() << " says: ";
//         a_cat.makeSound();


        
//         std::cout << CYAN;
//         std::cout << "\n-> Animal pointer to new Animal(), Dog() or Cat():\n";
//         std::cout << RESET;
//         const Animal* meta = new Animal();
//         std::cout << meta->getType() << " says: ";
//         meta->makeSound();

//         std::cout << std::endl;
//         const Animal* j = new Dog();
//         std::cout << j->getType() << " says: ";
//         j->makeSound();

//         std::cout <<  std::endl;
//         const Animal* i = new Cat();
//         std::cout << i->getType() << " says: ";
//         i->makeSound(); 


//         std::cout << BLUE;
//         std::cout << "\n________________________________________________________________________________\n";
//         std::cout << "Exercise00: Additional tests with WrongAnimal's makeSound attribute not being 'virtual'" << std::endl;
//         std::cout << "________________________________________________________________________________\n";

//         std::cout << CYAN;
//         std::cout << "\n-> WrongAnimal(), WrongCat():\n";
//         std::cout << RESET;
//         WrongAnimal a_wrong_animal;
//         std::cout << a_wrong_animal.getType() << " says: ";
//         a_wrong_animal.makeSound();

//         std::cout <<  std::endl;
//         WrongCat a_wrong_cat;
//         std::cout << a_wrong_cat.getType() << " says: ";
//         a_wrong_cat.makeSound();


//         std::cout << CYAN;
//         std::cout << "\n-> WrongAnimal pointer to WrongCat:\n";
//         std::cout << RESET;
//         const WrongAnimal* wrongJ = new WrongCat();
//         std::cout << wrongJ->getType() << " says: ";
//         wrongJ->makeSound(); 

//         std::cout <<  std::endl;
//         std::cout << "\n- - - - - - - - - - - - - - - - - - - - \n";
//         delete meta;
//         std::cout << std::endl;
//         delete j;
//         std::cout << std::endl;
//         delete i;
//         std::cout << std::endl;
//         delete wrongJ;
//     }

//     {
//         std::cout << BLUE;
//         std::cout << "\n________________________________________________________________________________\n";
//         std::cout << "Exercise 01: Animal array of Cat and Dog - Deepcopy" << std::endl;
//         std::cout << "________________________________________________________________________________\n";
//         std::cout << CYAN;
//         std::cout << "\n-> Preamble:\n";
//         std::cout << RESET;
//         const Animal    *j = new Dog();
//         std::cout << j->getType() << " says: ";
//         j->makeSound();
//         std::cout << std::endl;

//         const Animal    *i = new Cat();
//         i->makeSound();

//         std::cout << std::endl;
//         std::cout << "\n- - - - - - - - - - - - - - - - - - - - \n";
//         delete j;
//         delete i;
//         std::cout << std::endl;

//         std::cout << CYAN;
//         std::cout << "\n-> Animal array of Cat and Dog instances:\n";
//         std::cout << RESET;
//         int     size = 10;
//         int     thought_amount = 5;
//         Animal  *animal_array[size];

//         for (int i = 0; i < size; i++)
//         {
//             if (i%2 == 0)
//             {
//                 animal_array[i] = new Cat;
//             }
//             else
//                animal_array[i] = new Dog;
//              std::cout << "Instantiated animal #" << i+1 << " of type: " << animal_array[i]->getType() << std::endl;
//         }

//         std::cout << std::endl;
//         std::cout << CYAN;
//         std::cout << "\n-> non-human Animal having thoughts:\n";
//         std::cout << RESET;
//         for(int i = 0; i < size; i++){
//             if (dynamic_cast<Cat*>(animal_array[i]))
//                 dynamic_cast<Cat*>(animal_array[i])->getBrain().setIdeas(0, "Miaou! Miaou!");
//             else
//                 dynamic_cast<Dog*>(animal_array[i])->getBrain().setIdeas(0, "Ouaf! Ouaf!");
//         }
//         for(int i = 0, j = 1; i < size; i++){
//             std::cout << animal_array[i]->getType() << "[" << j << "]'s 1st thought [0]:\t";
//             if (dynamic_cast<Cat*>(animal_array[i]))
//                 std::cout << dynamic_cast<Cat*>(animal_array[i])->getBrain().getIdeas(0);
//             else
//             {
//                 std::cout << dynamic_cast<Dog*>(animal_array[i])->getBrain().getIdeas(0);
//                 j++;
//             }
//             std::cout << std::endl;
//         }

//         std::cout << std::endl;
//         std::cout << "Nothing to see beyond 1st thought e.g. Cat instance # 1:\n";
//         for (int i = 0; i < thought_amount; i++){
//             std::cout << "Thought [" << i << "] ";
//             std::cout << dynamic_cast<Cat*>(animal_array[0])->getBrain().getIdeas(0) << std::endl;
//         }

//         std::cout << std::endl;
//         std::cout << "\n- - - - - - - - - - - - - - - - - - - - \n";
//         for (int i = 0; i < size; i++)
//         {
//             delete animal_array[i];
//              std::cout << "Animal #" << i+1 << " is gone\n";
//         }

//     }

//     {
//         int     thought_amount = 5;

//         std::cout << std::endl;
//         std::cout << CYAN;
//         std::cout << "\n-> Deep copy - Setting up a thinker Cat:\n";
//         std::cout << RESET;
//         Cat a_new_cat;
//         a_new_cat.getBrain().setIdeas(0, "Miaou! Miaou!");
//         for (int i = 0; i < thought_amount; i++){
//             std::cout << a_new_cat.getType() << "'s thought [" << i << "] ";
//             std::cout << a_new_cat.getBrain().getIdeas(i) << std::endl;
//         }
        
//         std::cout << std::endl;
//         std::cout << CYAN;
//         std::cout << "\nA copy constructed cat got an idea from the thinking Cat:\n";
//         std::cout << RESET;
//         Cat copy_constructed_cat(a_new_cat);
//         for (int i = 0; i < thought_amount; i++){
//             std::cout << copy_constructed_cat.getType() << "'s thought [" << i << "] ";
//             std::cout << copy_constructed_cat.getBrain().getIdeas(i) << std::endl;
//         }
        
//         std::cout << std::endl;
//         std::cout << CYAN;
//         std::cout << "\nAn operator assigned cat under influence of a thinking Cat:\n";
//         std::cout << RESET;
//         Cat another_cat = a_new_cat;
//         for (int i = 0; i < thought_amount; i++){
//             std::cout << another_cat.getType() << "'s thought [" << i << "] ";
//             std::cout << another_cat.getBrain().getIdeas(i) << std::endl;
//         }

//         std::cout << std::endl;
//         std::cout << CYAN;
//         std::cout << "\nThinker Cat got a second idea:\n";
//         std::cout << RESET;
//         a_new_cat.getBrain().setIdeas(1, "Miaou! Miaou! Miaaaaaaaouuuuuu!");
//         for (int i = 0; i < thought_amount; i++){
//             std::cout << a_new_cat.getType() << "'s thought [" << i << "] ";
//             std::cout << a_new_cat.getBrain().getIdeas(i) << std::endl;
//         }
 
//         std::cout << std::endl;
//         std::cout << CYAN;
//         std::cout << "\nCopy constructed cat has still one idea:\n";
//         std::cout << RESET;
//         for (int i = 0; i < thought_amount; i++){
//             std::cout << copy_constructed_cat.getType() << "'s thought [" << i << "] ";
//             std::cout << copy_constructed_cat.getBrain().getIdeas(i) << std::endl;
//         }
//         std::cout << std::endl;
//         std::cout << CYAN;
//         std::cout << "\nThe operator assigned cat still has only one idea:\n";
//         std::cout << RESET;
//         for (int i = 0; i < thought_amount; i++){
//             std::cout << another_cat.getType() << "'s thought [" << i << "] ";
//             std::cout << another_cat.getBrain().getIdeas(i) << std::endl;
//         }
//         std::cout << std::endl;
//         std::cout << "\n- - - - - - - - - - - - - - - - - - - - \n";
//     }

//     {
//         int     thought_amount = 5;

//         std::cout << std::endl;
//         std::cout << GREEN;
//         std::cout << "\n-> Deep copy - Setting up a thinker Dog:\n";
//         std::cout << RESET;
//         Dog a_new_dog;
//         a_new_dog.getBrain().setIdeas(0, "Ouaf! Ouaf!");
//         for (int i = 0; i < thought_amount; i++){
//             std::cout << a_new_dog.getType() << "'s thought [" << i << "] ";
//             std::cout << a_new_dog.getBrain().getIdeas(i) << std::endl;
//         }
        
//         std::cout << std::endl;
//         std::cout << GREEN;
//         std::cout << "\nA copy constructed dog got an idea from the thinking Dog:\n";
//         std::cout << RESET;
//         Dog copy_constructed_dog(a_new_dog);
//         for (int i = 0; i < thought_amount; i++){
//             std::cout << copy_constructed_dog.getType() << "'s thought [" << i << "] ";
//             std::cout << copy_constructed_dog.getBrain().getIdeas(i) << std::endl;
//         }
        
//         std::cout << std::endl;
//         std::cout << GREEN;
//         std::cout << "\nAn operator assigned dog under influence of a thinking Dog:\n";
//         std::cout << RESET;
//         Dog another_dog = a_new_dog;
//         for (int i = 0; i < thought_amount; i++){
//             std::cout << another_dog.getType() << "'s thought [" << i << "] ";
//             std::cout << another_dog.getBrain().getIdeas(i) << std::endl;
//         }

//         std::cout << std::endl;
//         std::cout << GREEN;
//         std::cout << "\nThinker Dog got a second idea:\n";
//         std::cout << RESET;
//         a_new_dog.getBrain().setIdeas(1, "Ouaf! Ouaf! Ouuuaaaaaaaffffffffffff!");
//         for (int i = 0; i < thought_amount; i++){
//             std::cout << a_new_dog.getType() << "'s thought [" << i << "] ";
//             std::cout << a_new_dog.getBrain().getIdeas(i) << std::endl;
//         }
 
//         std::cout << std::endl;
//         std::cout << GREEN;
//         std::cout << "\nCopy constructed dog has still one idea:\n";
//         std::cout << RESET;
//         for (int i = 0; i < thought_amount; i++){
//             std::cout << copy_constructed_dog.getType() << "'s thought [" << i << "] ";
//             std::cout << copy_constructed_dog.getBrain().getIdeas(i) << std::endl;
//         }
//         std::cout << std::endl;
//         std::cout << GREEN;
//         std::cout << "\nThe operator assigned dog still has only one idea:\n";
//         std::cout << RESET;
//         for (int i = 0; i < thought_amount; i++){
//             std::cout << another_dog.getType() << "'s thought [" << i << "] ";
//             std::cout << another_dog.getBrain().getIdeas(i) << std::endl;
//         }
//         std::cout << std::endl;
//         std::cout << "\n- - - - - - - - - - - - - - - - - - - - \n";

//     }
//     {
//         std::cout << std::endl;
//         std::cout << CYAN;
//         std::cout << "\n-> Eval form Cat's deep copy check:\n";
//         std::cout << RESET;
//         Cat a_cat;
//         {
//             Cat another_cat(a_cat);
//             std::cout << "\n- - - - - - - - - - - - - - - - - - - - \n";
//         }
//         std::cout << "\n- - - - - - - - - - - - - - - - - - - - \n";
//         {
//             Cat another_cat = a_cat;
//             std::cout << "\n- - - - - - - - - - - - - - - - - - - - \n";
//         }
//         std::cout << "\n- - - - - - - - - - - - - - - - - - - - \n";
//     }
//     {
//         std::cout << std::endl;
//         std::cout << GREEN;
//         std::cout << "\n-> Eval form Dog's deep copy check:\n";
//         std::cout << RESET;
//         Dog a_dog;
//         {
//             Dog another_dog(a_dog);
//             std::cout << "\n- - - - - - - - - - - - - - - - - - - - \n";
//         }
//         std::cout << "\n- - - - - - - - - - - - - - - - - - - - \n";
//         {
//             Dog another_dog = a_dog;
//             std::cout << "\n- - - - - - - - - - - - - - - - - - - - \n";
//         }
//         std::cout << "\n- - - - - - - - - - - - - - - - - - - - \n";
//     }

//     return 0;
// }