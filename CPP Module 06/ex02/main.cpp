#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	int i = std::rand() % 3;
	if (i == 0)
		return (new A);
	else if (i == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base *p){
	if (dynamic_cast<A *>(p))
		std::cout << "pointer as A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "pointer as B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "pointer as C" << std::endl;
}

void identify(Base &p){
	A a;
	B b;
	C c;
	try{
		a = dynamic_cast<A &>(p);
		std::cout << "reference as A" << std::endl;
	} catch (...) {
		std::cout << "it is not A" << std::endl;
	}
	try{
		b = dynamic_cast<B &>(p);
		std::cout << "reference as B" << std::endl;
	} catch (...) {
		std::cout << "it is not B" << std::endl;
	}
	try{
		c = dynamic_cast<C &>(p);
		std::cout << "reference as C" << std::endl;
	} catch (...) {
		std::cout << "it is not C" << std::endl;
	}
	return ;
}

int main(void)
{
	std::srand(std::time(0));

	std::cout << "---------randomly generated---------" << std::endl;
	Base *random = generate();

	identify(random);
	std::cout << "identified by pointer" << std::endl;

	identify(*random);
	std::cout << "identified by reference" << std::endl;

	delete random;

	std::cout << "---------Downcasting---------" << std::endl;
	Base *what = new B;

	identify(what);
	std::cout << "identified by pointer" << std::endl;

	identify(*what);
	std::cout << "identified by reference" << std::endl;

	delete what;

	return (0);
}