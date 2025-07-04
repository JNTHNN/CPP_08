#include "../includes/Span.hpp"

const char* Span::FullStorage::what() const throw()
{
    return "Error: the storage is full.";
}

const char* Span::SmallStorage::what() const throw()
{
    return "Error: the storage has less than 2 numbers.";
}

Span::Span(unsigned int n): _v(), _maxSize(n)
{
    return;
}

Span::Span(const Span& copied): _v(copied._v), _maxSize(copied._maxSize)
{
    return;
}

Span&    Span::operator=(const Span& base)
{
    if (this != &base)
    {
        this->_v = base._v;
        this->_maxSize = base._maxSize;
    }
    return *this;
}

Span::~Span(void)
{
    return;
}

void    Span::addNumber(int num)
{
    if (this->_v.size() < this->_maxSize)
        this->_v.insert(this->_v.end(), num);
    else
        throw FullStorage();
}

void    Span::addMultiplesNumbers(const std::vector<int>& v)
{
    if (this->_v.size() + v.size() > this->_maxSize)
        throw FullStorage();
    this->_v.insert(this->_v.end(), v.begin(), v.end());
}

int    Span::shortestSpan(void)
{
    if (_v.size() < 2)
        throw SmallStorage();

    int     span = INT_MAX;
    Span    copy(*this);

    std::sort(copy._v.begin(), copy._v.end());
    for (std::vector<int>::iterator it = copy._v.begin(); it != copy._v.end() - 1 ; ++it)
    {
            if (span > std::abs(*(it + 1) - *it))
                span  = std::abs(*(it + 1) - *it);
    }
    return span;   
}
    
int    Span::longestSpan(void)
{
    if (_v.size() < 2)
        throw SmallStorage();

    std::vector<int>::iterator min = std::min_element(this->_v.begin(), this->_v.end());
    std::vector<int>::iterator max = std::max_element(this->_v.begin(), this->_v.end());

    return std::abs(*max - *min);

}
