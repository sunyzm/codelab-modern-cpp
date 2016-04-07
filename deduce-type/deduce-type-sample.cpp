#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    auto x1 = 27;
    auto x2(27);
    auto x3 = { 27 };
    auto x4{ 27 };
    /* Notice that the type of x1, x2 and x4 is int, while the type of x3 is std::initializer_list<int>.
       cf. "Effective Modern C++", Item 2. */

    system("PAUSE");
}