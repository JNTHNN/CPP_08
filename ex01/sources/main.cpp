#include "../includes/Span.hpp"

void testBasics()
{
    std::cout << "=== Test basique ===" << std::endl;
    
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    std::cout << std::endl;
}

void testExceptions()
{
    std::cout << "=== Test des exceptions ===" << std::endl;
    
    // Test FullStorage
    try
    {
        Span sp = Span(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4); // Devrait lever FullStorage
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception attendue: " << e.what() << std::endl;
    }
    
    // Test SmallStorage avec shortestSpan
    try
    {
        Span sp = Span(5);
        sp.addNumber(42);
        sp.shortestSpan(); // Devrait lever SmallStorage
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception attendue: " << e.what() << std::endl;
    }
    
    // Test SmallStorage avec longestSpan
    try
    {
        Span sp = Span(5);
        sp.longestSpan(); // Devrait lever SmallStorage (vide)
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception attendue: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testMultiplesNumbers()
{
    std::cout << "=== Test addMultiplesNumbers ===" << std::endl;
    
    // Test réussi
    Span sp = Span(10);
    int arr[] = {1, 5, 2, 8, 3};
    std::vector<int> vec(arr, arr + 5);
    
    sp.addMultiplesNumbers(vec);
    std::cout << "Après ajout multiple - Shortest: " << sp.shortestSpan() 
              << ", Longest: " << sp.longestSpan() << std::endl;
    
    // Test échec (trop de nombres)
    try
    {
        Span bigsp = Span(6);
        int arr2[] = {4, 5, 8, 2, 6, 10, 3};
        std::vector<int> ok(arr2, arr2 + 7);
        bigsp.addMultiplesNumbers(ok);
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception attendue: " << e.what() << std::endl;
    }

	// Test 10000 nombres

	Span bigSpan = Span(10000);
	std::vector<int> bigNumbers;
	for (int i = 0; i < 10000; ++i)
		bigNumbers.push_back(i);
	
	bigSpan.addMultiplesNumbers(bigNumbers);
	std::cout << "10000 nombres ajoutés avec succès!" << std::endl;
	std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "Longest: " << bigSpan.longestSpan() << std::endl;
	
    std::cout << std::endl;
}

void testCopyConstructorAndAssignment()
{
    std::cout << "=== Test constructeur de copie et assignation ===" << std::endl;
    
    Span original = Span(5);
    original.addNumber(10);
    original.addNumber(20);
    original.addNumber(30);
    
    // Test constructeur de copie
    Span copy(original);
    std::cout << "Original shortest: " << original.shortestSpan() << std::endl;
    std::cout << "Copy shortest: " << copy.shortestSpan() << std::endl;
    
    // Test opérateur d'assignation
    Span assigned = Span(10);
    assigned = original;
    std::cout << "Assigned shortest: " << assigned.shortestSpan() << std::endl;
    
    std::cout << std::endl;
}

void testEdgeCases()
{
    std::cout << "=== Test cas limites ===" << std::endl;
    
    // Test avec 2 éléments identiques
    Span sp = Span(5);
    sp.addNumber(42);
    sp.addNumber(42);
    std::cout << "Deux nombres identiques - Shortest: " << sp.shortestSpan() 
              << ", Longest: " << sp.longestSpan() << std::endl;
    
    // Test avec nombres négatifs
    Span sp2 = Span(5);
    sp2.addNumber(-10);
    sp2.addNumber(5);
    sp2.addNumber(-3);
    std::cout << "Avec nombres négatifs - Shortest: " << sp2.shortestSpan() 
              << ", Longest: " << sp2.longestSpan() << std::endl;
    
}

int main(void)
{
    testBasics();
    testExceptions();
    testMultiplesNumbers();
    testCopyConstructorAndAssignment();
    testEdgeCases();
    
    return 0;
}