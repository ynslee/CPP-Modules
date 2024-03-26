#include "MutantStack.hpp"
#include <iostream>

int main()
{

	std::cout << "*****stack test*****" << std::endl;
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	std::cout << "top of the stack value is: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "top of the stack value is now: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size is now: " << mstack.size() << std::endl;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);

	MutantStack<int> mstack2;
	mstack2.push(5);
	mstack2.push(4);
	mstack2.push(3);
	mstack2.push(2);
	mstack2.push(1);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "mstack before swap is : ";
	while (it != ite)
	{
		std::cout << *it;
		++it;
	}
	std::cout << std::endl;

	MutantStack<int>::iterator it2 = mstack2.begin();
	MutantStack<int>::iterator ite2 = mstack2.end();
	std::cout << "mstack2 before swap is : ";
	while (it2 != ite2)
	{
		std::cout << *it2;
		++it2;
	}
	std::cout << std::endl;

	mstack.swap(mstack2);
	MutantStack<int>::iterator it3 = mstack.begin();
	MutantStack<int>::iterator ite3 = mstack.end();
	std::cout << "mstack after swap is : ";
	while (it3 != ite3)
	{
		std::cout << *it3;
		++it3;
	}
	std::cout << std::endl;

	MutantStack<int>::iterator it4 = mstack2.begin();
	MutantStack<int>::iterator ite4 = mstack2.end();
	std::cout << "mstack2 after swap is : ";
	while (it4 != ite4)
	{
		std::cout << *it4;
		++it4;
	}
	std::cout << std::endl;
	return 0;
}

// int main()
// {

// 	std::cout << "*****this is with the stack*****" << std::endl;
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
	
// 	std::cout << "*****this is with the list*****" << std::endl;
// 	MutantStack<int> mlist;
// 	mlist.push_back(5);
// 	mlist.push_back(17);
// 	std::cout << mlist.back() << std::endl;
// 	mlist.pop_back();
// 	std::cout << mlist.size() << std::endl;
// 	mlist.push_back(3);
// 	mlist.push_back(5);
// 	mlist.push_back(737);
// 	//[...]
// 	mlist.push_back(0);
// 	MutantStack<int>::iterator it2 = mlist.begin();
// 	MutantStack<int>::iterator ite2 = mlist.end();
// 	++it2;
// 	--it2;
// 	while (it2 != ite2)
// 	{
// 		std::cout << *it2 << std::endl;
// 		++it2;
// 	}
// 	std::stack<int> l(mlist);
// 	return 0;
// }