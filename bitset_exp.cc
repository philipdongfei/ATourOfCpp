#include    <iostream>
#include    <string>
#include    <algorithm>
#include    <bitset>
#include    <chrono>
#include    <unistd.h>

using namespace std;
using namespace std::chrono;


void binary(int i)
{
    bitset<8*sizeof(int)> b = i;    // assume 8-bit byte (see also 12.7)
    cout<<b.to_string()<<'\n';      // write out the bits of i
}

void binary2(int i)
{
    bitset<8*sizeof(int)> b = i;
    cout<<b<<'\n';
}

int main(int argc, char* argv[])
{
    auto t0 = high_resolution_clock::now();
    binary(123);
    binary2(123);
    sleep(1);
    auto t1 = high_resolution_clock::now();
    cout<<duration_cast<milliseconds>(t1-t0).count()<<"msec\n";

    return 0;
}

