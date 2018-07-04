#include <cctype>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>

void lambdaAsFunctor()
{
    int va[] = { 1, 2, 3, 4, 5, 6, 7, 8 };    
    std::for_each(std::begin(va), std::end(va), [=](int a) { std::cout << a*a << ' '; });
    std::cout << std::endl;

    std::vector<int> vb = { 1, -2, 3, -4, 5, -6, -7, 8};
    std::transform(std::begin(vb), std::end(vb), std::begin(vb), [](int c) { return std::abs(c); });
    for (int b : vb) std::cout << b << ' ';
    std::cout << std::endl;

    std::string s("hello");
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return std::toupper(c); });
    std::cout << s << std::endl;
}

int main()
{
    lambdaAsFunctor();

    return 0;
}