#include    <vector>
#include    <list>
#include    <algorithm>
#include    <string>
#include    <iostream>

using namespace std;

template<typename C, typename V>
vector<typename C::iterator> find_all(C& c, V v)    // find all occurrences of v in c
{
    vector<typename C::iterator> res;
    for(auto p = c.begin(); p!=c.end();++p)
        if (*p==v)
            res.push_back(p);
    return res;
}

/*********
 *
 *  We can hide this implementation detail by introducing a type alias for iterator
 *
 ***********************/
#if 0
template<typename T>
using iterator = typename T::iterator;    // T's iterator

template<typename C, typename V>
vector<iterator<C>>find_all(C& c, V v)    // find all occurrences of v in c
{
    vector<iterator<C>> res;
    for (auto p = c.begin();p!=c.end();++p)
        if (*p==v)
            res.push_back(p);
    return res;
}

#endif

void test()
{
    string m{"Mary had a little lamb."};

    for (auto p : find_all(m,'a'))    // p is a string::iterator
        if(*p!='a')
            cerr<<"string bug!\n";

    list<double> ld{1.1,2.2,3.3,1.1};
    for(auto p : find_all(ld,1.1))
        if(*p!=1.1)
            cerr<<"list bug!\n";

    vector<string> vs {"red","blue","green","green","orange","green"};
    for(auto p : find_all(vs,"red"))
        if(*p!="red")
            cerr<<"vector bug!\n";
    for (auto p : find_all(vs,"gree"))
        *p = "vert";

}

int main(int argc, char* argv[])
{
    test();

    return 0;
}
