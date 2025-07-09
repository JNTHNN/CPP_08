#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <vector>
#include <stack>

template <typename T>
class   MutantStack: public std::stack<T>
{
	private:

	public:
		MutantStack();
		MutantStack(const MutantStack& copied);
		MutantStack&	operator=(const MutantStack& base);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator				begin();
		iterator				end();
		const_iterator			begin() const;
		const_iterator			end() const;
		reverse_iterator		rbegin();
		reverse_iterator		rend();
		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
};

template <typename T>
MutantStack<T>::MutantStack(void)
{
	return;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& copied)
{
	*this = copied;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& base)
{
	if (*this != base)
		std::stack<T>::operator=(base);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	return;
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin() const
{
	return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end() const
{
	return this->c.end();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend()
{
	return this->c.rend();
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rbegin() const 
{
	return this->c.rbegin();
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rend() const
{
	return this->c.rend();
}

#endif
