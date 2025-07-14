#include "../includes/Span.hpp"

int main(void)
{
	Span    sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	Span    bigsp = Span(6);

	int	arr[] = {4, 5, 8, 2, 6, 10, 3};
	std::vector<int>	ok(arr, arr + 7);
	
	try
	{
		bigsp.addMultiplesNumbers(ok);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << bigsp.shortestSpan() << std::endl;

	std::cout << std::endl;
}
