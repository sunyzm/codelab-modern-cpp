#include <iostream>
#include <typeinfo> 

int main()
{
    auto x1 = 27;
    auto x2(27);
    auto x3 = { 27 };
    auto x4{ 27 };
    // Note that the type of x1, x2 and x4 is int, while the type of x3 is std::initializer_list<int>.
    // cf. "Effective Modern C++", Item 2.

    std::cout << typeid(x1).name() << std::endl;
    std::cout << typeid(x2).name() << std::endl;
    std::cout << typeid(x3).name() << std::endl;
    std::cout << typeid(x4).name() << std::endl;    

    return 0;
}