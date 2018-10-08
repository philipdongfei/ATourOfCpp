#include    <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    cout<<1234<<','<<hex<<1234<<','<<oct<<1234<<'\n';

    constexpr double d = 123.456;

    cout<<d<<";"        // use the default format for d
        <<scientific<<d<<";"    // use 1.123e2 style format for d
        <<hexfloat<<d<<";"      // use hexadecimal notation for d
        <<fixed<<d<<";"     //use 123.456 style format for d
        <<defaultfloat<<d<<'\n';    // use the default format for d

    cout.precision(8);
    cout<<1234.56789<<' '<<1234.56789<<' '<<123456<<'\n';

    cout.precision(4);
    cout<<1234.56789<<' '<<1234.56789<<' '<<123456<<'\n';

}
