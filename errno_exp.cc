#include    <cerrno>
#include    <iostream>
#include    <cmath>
#include    <limits>
#include    <cstdlib>

using namespace std;

void f()
{
    errno = 0; // clear old error state
    sqrt(-1);
    if (errno == EDOM)
        cerr<<"sqrt() not defined for negative argument"<<'\n';

    errno = 0; // clear old error state
    pow(numeric_limits<double>::max(),20000);
    if (errno == ERANGE)
        cerr<<"result of pow() too large to represent as a double"<<'\n';
        

}

int main(int argc, char* argv[])
{
    f();

    return 0;
}
