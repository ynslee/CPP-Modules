#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <memory>

Base* generate(void) {
	int i = std::rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void identify(Base *p){
	if (dynamic_cast<A *>(p))
		std::cout << "pointer as A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "pointer as B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "pointer as C" << std::endl;
	else
		std::cout << "Invalid: it is not A, B or C" << std::endl;
}

void identify(Base &p){
	A a;
	B b;
	C c;
	int found = 0;

	try{
		a = dynamic_cast<A &>(p);
		found = 1;
		std::cout << "reference as A" << std::endl;
	} catch (...) {}
	try{
		b = dynamic_cast<B &>(p);
		found = 1;
		std::cout << "reference as B" << std::endl;
	} catch (...) {}
	try{
		c = dynamic_cast<C &>(p);
		found = 1;
		std::cout << "reference as C" << std::endl;
	} catch (...) {}
	if (!found)
		std::cout << "Invalid: it is not A, B or C" << std::endl;
	return ;
}

int main(void)
{
	std::srand(std::time(0));

	{
		std::cout << "---------randomly generated---------" << std::endl;
		Base *random = generate();

		std::cout << "identified by pointer---" << std::endl;
		identify(random);

		std::cout << "\nidentified by reference---" << std::endl;
		identify(*random);

		delete random;
	}

	{
		std::cout << "\n---------Downcasting---------" << std::endl;
		Base *what = new B;

		std::cout << "identified by pointer---" << std::endl;
		identify(what);

		std::cout << "\nidentified by reference---" << std::endl;
		identify(*what);

		delete what;
	}

	return 0;
}