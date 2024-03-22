#include "Span.hpp"
#include <iostream>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp2 = Span(10000);
	sp2.fillVector(10000);
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	Span sp3 = Span(10002);
	sp3.addNumber(10001);
	sp3.addNumber(19999);
	sp3.fillVector(10000);
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	// Span s2 = Span(10);
	// s2.fillVector(10);
	// std::cout << s2.shortestSpan() << std::endl;
	// std::cout << s2.longestSpan() << std::endl;
	return 0;
}