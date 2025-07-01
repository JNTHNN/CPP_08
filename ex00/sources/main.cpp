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
    std::vector<int> v = {1, 101, 3, 42};

    // Test valide
    try
    {
        easyfind(v, 101);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Test invalide
    try
    {
        easyfind(v, 19);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}