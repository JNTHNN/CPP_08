#include "../includes/MutantStack.hpp"
#include <list>

int main(void)
{
    MutantStack<int>        ok;
    const MutantStack<int>  ok2;

    ok.push(1);
    ok.push(2);
    ok.push(3);

    std::cout << "top : " << ok.top() << std::endl;

    for (MutantStack<int>::iterator it = ok.begin(); it != ok.end(); ++it)
        std::cout << " standard: " << *it;
        
    for (MutantStack<int>::const_iterator it2 = ok.begin(); it2 != ok.end(); ++it2)
        std::cout << " const: " << *it2;

    std::cout << std::endl;
    
    for (MutantStack<int>::reverse_iterator it3 = ok.rbegin(); it3 != ok.rend(); ++it3)
    std::cout << " reverse: " << *it3;
    
    for (MutantStack<int>::const_reverse_iterator it4 = ok.rbegin(); it4 != ok.rend(); ++it4)
    std::cout << " const: " << *it4;
    
    std::cout << std::endl;
    
    std::cout << std::endl;
    std::cout << "--= TEST PDF =--" << std::endl;
    std::cout << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << std::endl;
    std::cout << "--= TEST STD::LIST =--" << std::endl;
    std::cout << std::endl;
    {
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);

        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
}
