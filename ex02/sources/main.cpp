#include "../includes/MutantStack.hpp"

int main(void)
{
    MutantStack<int> ok;
    const MutantStack<int> ok2;

    ok.push(1);
    ok.push(2);
    ok.push(3);

    std::cout << "top : " << ok.top() << std::endl;

    for (MutantStack<int>::iterator it = ok.begin(); it != ok.end(); ++it)
        std::cout << *it << std::endl;
        
    for (MutantStack<int>::const_iterator it2 = ok.begin(); it2 != ok.end(); ++it2)
        std::cout << "const: " << *it2 << std::endl;

}
