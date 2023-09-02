#include <iostream>
#include <iterator>
#include <vector>
#include <set>
 
int main() 
{
    std::multiset<int> v{3, 1, 4};
 
    auto vi = v.begin();
    std::advance(vi, 2);
    std::cout << *vi << ' ';
 
    vi = v.end();
    std::advance(vi, -2);
    std::cout << *vi << '\n';
}
