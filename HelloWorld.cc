#include    <iostream>
#include    <vector>

int main()
{
    std::vector<int> v = {0,1,2,3,4,5};

    for (const int& i : v) // access by const reference
        std::cout << i << ' ';
    std::cout << '\n';

    std::cout << "Hello, World!\n";


}


