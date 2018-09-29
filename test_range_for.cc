#include <iostream>
#include <algorithm>

namespace foo{
    int i=0;
    struct A
    {
        A()
        {
            std::generate(&v[0], &v[10], [&i](){return ++i;});

        }
        int v[10];
    };
    int *begin(A &v)
    {
        return &v.v[0];
    }
    int *end(A &v)
    {
        return &v.v[10];
    }

} // namespace foo

int main()
{
    foo::A a;
    for (auto it : a)
    {
        std::cout << it << std::endl;
    }

}

