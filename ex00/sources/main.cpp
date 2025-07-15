#include <vector>
#include <iostream>
#include <stdexcept>
#include "../includes/easyfind.hpp"

const char* NotFoundException::what() const throw()
{
	return "Error: occurrence not found";
}

int main(void)
{
	std::vector<int>    v;
	v.push_back(1);
	v.push_back(101);

	// Test valide
	try
	{
		easyfind(v, 101);
	}
	catch(const std::exception&	e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Test invalide
	try
	{
		easyfind(v, 19);
	}
	catch(const std::exception&	e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}