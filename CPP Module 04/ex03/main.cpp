
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(2);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	delete bob;
	std::cout << "----[ bob ] deletion ended" << std::endl;
	delete me;
	std::cout << "---- [ me ] deletion ended" << std::endl;
	delete src;
	std::cout << "---- [ source ] deletion ended" << std::endl;
	return 0;
}

// int main() {
//   {
//     std::cout << "--- example test ---" << std::endl;

//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     ICharacter* me = new Character("me");

//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);

//     ICharacter* bob = new Character("bob");

//     me->use(0, *bob);
//     me->use(1, *bob);

//     delete bob;
//     delete me;
//     delete src;
//   }
//   {
//     std::cout  << "--- copy test ---"  << std::endl;

//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     IMateriaSource* src_copy =
//         new MateriaSource(dynamic_cast<MateriaSource&>(*src));

//     ICharacter* orig = new Character("orig");
//     orig->equip(src_copy->createMateria("ice"));
//     orig->equip(src_copy->createMateria("cure"));
//     orig->use(0, *orig);
//     orig->use(1, *orig);

//     ICharacter* copy = new Character(dynamic_cast<Character&>(*orig));
//     copy->use(0, *copy);
//     copy->use(1, *copy);

//     delete src;
//     delete src_copy;
//     delete orig;
//     delete copy;
//   }
//   {
//     std::cout << "--- overfill Character inventory test ---"
//                << std::endl;

//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     ICharacter* me = new Character("me");

//     me->equip(src->createMateria("ice"));
//     me->equip(src->createMateria("ice"));
//     me->equip(src->createMateria("ice"));
//     me->equip(src->createMateria("ice"));
//     me->equip(src->createMateria("cure"));

//     me->use(0, *me);
//     me->use(1, *me);
//     me->use(2, *me);
//     me->use(3, *me);

//     me->unequip(2);
//     me->equip(src->createMateria("cure"));

//     me->use(0, *me);
//     me->use(1, *me);
//     me->use(2, *me);
//     me->use(3, *me);

//     delete src;
//     delete me;
//   }
//   {
//     std::cout << "--- overfill MateriaSource inventory test ---"
//                << std::endl;

//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Ice());
//     src->learnMateria(new Ice());
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     delete src;
//   }
//   {
//     std::cout << "--- overfill Character pile test ---"
//                << std::endl;

//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     ICharacter* me = new Character("me");

//     // fill the pile, inventory empty
//     for (int i = 0; i < 100; i++) {
//       me->equip(src->createMateria("ice"));
//       me->unequip(0);
//     }

//     // fill the inventory as well
//     for (int i = 0; i < 4; i++) {
//       me->equip(src->createMateria("ice"));
//     }

//     // unequip slot 1 and equip cure
//     // should not unequip because pile full, should not equip because inventory full
//     me->unequip(1);
//     me->equip(src->createMateria("cure"));

//     // check that slot 1 is still ice, not cure
//     me->use(1, *me);

//     delete src;
//     delete me;
//   }
//   return 0;
// }