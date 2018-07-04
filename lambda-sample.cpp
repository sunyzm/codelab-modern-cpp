#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

void lambdaAsFunctor()
{
    int va[] = { 1, 2, 3, 4, 5, 6, 7, 8 };    
    for_each(begin(va), end(va), [=](int a) { cout << a*a << ' '; });
    cout << endl;

    vector<int> vb = { 1, -2, 3, -4, 5, -6, -7, 8};
    transform(std::begin(vb), std::end(vb), std::begin(vb), [](int c) { return abs(c); });
    for (int b : vb) cout << b << ' ';
    cout << endl;

    std::string s("hello");
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return std::toupper(c); });
    std::cout << s << endl;
}

void main()
{
    lambdaAsFunctor();

    system("PAUSE");
}