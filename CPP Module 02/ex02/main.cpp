#include "Fixed.hpp"

// int main( void ) {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;
//     return 0;
// }

int main(void) {
    Fixed a(2.55f);
    Fixed b(4.75f);
    Fixed c = a;

    std::cout << "\n\na is " << a << " and b is " << b << " and c is " << c << std::endl;

	std::cout << "****************************************\n" << std::endl;

    std::cout << "Comparison operator********\n" << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= c: " << (a >= c) << std::endl;
    std::cout << "a <= c: " << (a <= c) << std::endl;
    std::cout << "a == c: " << (a == c) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    std::cout << "\nArithmetic operator********\n" << std::endl;
    std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "b - a: " << (b - a) << std::endl;
    std::cout << "a * b: " << (a * b) << std::endl;
    std::cout << "b / a: " << (b / a) << std::endl;

    std::cout << "Increment & Decrement********\n" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b--: " << b-- << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "--b: " << --b << std::endl;
    std::cout << "b: " << b << std::endl;

    std::cout << "\nMin & Max********\n" << std::endl;
    Fixed smaller = Fixed::min(a, b);
    const Fixed const_smaller = Fixed::min(a, b);
    Fixed larger = Fixed::max(a, b);
    const Fixed const_larger = Fixed::max(a, b);

    std::cout << "Smaller: " << smaller << std::endl;
    std::cout << "Smaller (const): " << const_smaller << std::endl;
    std::cout << "Larger: " << larger << std::endl;
    std::cout << "Larger (const): " << const_larger << std::endl;

    return (0);
}