#include    <sstream>
#include    <iostream>

using namespace std;

void test()
{
    ostringstream oss;
    oss<<"{temperature,"<<scientific<<123.4567890<<"}";
    cout<<oss.str()<<'\n';
}

template<typename Target=string,typename Source=string>
Target to(Source arg)    // convert Source to Target
{
    stringstream interpreter;
    Target result;

    if (!(interpreter<<arg)      // write arg into stream
            || !(interpreter>>result)    // read result from stream
            || !(interpreter >> std::ws).eof()) //stuff left in stream?
        throw runtime_error{"to<>() failed"};

    return result;
}

int main(int argc, char* argv[])
{
    auto x1 = to<string,double>(1.2);   // very explicit (and verbose)
    auto x2 = to<string>(1.2);         // Source is deduced to double
    auto x3 = to<>(1.2);            // Target is defaulted to string; Source is deduced to double
    auto x4 = to(1.2);          // the <> is redundant;
                                // Target is defaulted to string; Source is deduced to double
}
