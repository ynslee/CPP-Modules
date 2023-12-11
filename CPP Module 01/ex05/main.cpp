#include "Harl.hpp"

int main()
{
	Harl chuck;
	chuck.complain("WARNING");
	chuck.complain("DEBUG");
	chuck.complain("INFO");
	chuck.complain("ERROR");
	chuck.complain("");
	chuck.complain("nothing");
	return (0);
}