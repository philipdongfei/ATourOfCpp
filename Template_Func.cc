#include    <iostream>
#include    <stdexcept>
#include    <list>
#include    <string>
#include    "T_Vector.h"


using namespace std;

template<typename T>
class Less_than{
    const T val;    //value to compare against
public:
    Less_than(const T& v):val(v) {}
    bool operator()(const T& x)const{ return x<val; } // call operator

};

template<typename C, typename P>
int count(const C& c, P pred)
{
    int cnt = 0;
    for (auto& x:c)
    {
        if (pred(x))
            ++cnt;
    }
    return cnt;
}

void f(const Vector<int>& vec, const list<string>& lst, int x, const string& s)
{
    cout<<"number of values less than"<<x \
        <<": "<<count(vec, Less_than<int>{x}) \
        <<'\n';
    cout<<"number of values less than"<<s \
        <<": "<<count(lst,Less_than<string>{s}) \
        <<'\n';
}

int main(int argc, char *argv[])
{
    Vector<int> v{{1,2,3,4,5},5};
    //v = {1,2,3,4,5};
    list<string> lst = {"ab","cd"};

 //   f(v, lst, 3, "ac");
}

