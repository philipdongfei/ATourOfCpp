#include    <cerrno>
#include    <iostream>
#include    <cmath>
#include    <limits>
#include    <cstdlib>
#include    <list>
#include    <numeric>

using namespace std;


void f()
{
    list<double> lst{1,2,3,4,5,9999.99999};
    auto s = accumulate(lst.begin(),lst.end(),0.0);    // calculate the sum
    cout<<s<<'\n';          // print 10014.9999
}

int main(int argc, char* argv[])
{
    f();

    return 0;
}
