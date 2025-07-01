#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <cstdlib>

class   Span
{
    private:
        std::vector<int> _v;
    
    public:
        Span(unsigned int n);
        Span(const Span& copied);
        ~Span();
        Span    operator=(const Span& base);

        void    addNumber(int num);
        int    shortestSpan();
        void    longestSpan();

        class   FullStorage: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class   SmallStorage: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};


#endif
