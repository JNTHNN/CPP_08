#include "../includes/Span.hpp"

const char* Span::FullStorage::what() const throw()
{
    return "Error: the storage is full.";
}

const char* Span::SmallStorage::what() const throw()
{
    return "Error: the storage has less than 2 numbers.";
}

Span::Span(unsigned int n): _v(n)
{
    return;
}

Span::Span(const Span& copied): _v(copied._v)
{
    return;
}

Span    Span::operator=(const Span& base)
{
    if (this != &base)
        this->_v = base._v;
    return *this;
}

Span::~Span(void)
{
    return;
}

void    Span::addNumber(int num)
{
    try
    {
        _v.push_back(num);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}

int    Span::shortestSpan(void)
{
    if (_v.size() < 2)
        throw SmallStorage();

    int span = 100;
    Span    copy(*this);

    for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); ++it)
    {
        for(std::vector<int>::iterator itc = copy._v.begin(); itc != copy._v.end(); ++itc)
        {
            if (std::abs(*it - *itc) < span)
                span = std::abs(*it - *itc);
            std::cout << span << ": " << *it << ": " << *itc << std::endl;
        }
    }
    return span;   
}
    
void    Span::longestSpan(void)
{
    if (_v.size() < 2)
        throw SmallStorage();

}