#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>

class   NotFoundException: public std::exception
{
	public:
		virtual const char* what() const throw();
};

template <typename T>
typename T::iterator	easyfind(T& container, int i)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), i);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

#endif
