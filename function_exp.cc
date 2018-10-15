#include    <iostream>
#include    <algorithm>
#include    <functional>
#include    <cmath>


using namespace std;
using namespace std::placeholders;

int round(double x){ return static_cast<int>(floor(x+0.5)); } // conventional 4/5 rounding (from<cmath>)

function<int(double)> f;  // f can hold anything that can be called with a double and return an int

enum class Round_style{truncate, round};

struct Round{   // function object carrying a state
    Round_style s;
    Round(Round_style ss):s(ss){}
    int operator()(double x) const {return static_cast<int>((s==Round_style::round)?(x+0.5):x);}
};

void t1()
{
    f = round;      // call through f to the function
    cout<<f(7.6)<<'\n';

    f = Round(Round_style::truncate);
    cout<<f(7.6)<<'\n';         // call through f to the function object

    Round_style style = Round_style::round;
    f = [style](double x){return static_cast<int>((style==Round_style::round)? x+0.5 : x);};

    cout<<f(7.6)<<'\n';     // call through f to the lambda

    vector<double> v{7.6};
    f = Round(Round_style::round);
    std::transform(v.begin(),v.end(),v.begin(),f);  // pass f to the transform() algorithm

    cout<<v[0]<<'\n';       // transformed by the function object
}

int main(int argc, char* argv[])
{
    t1();

    return 0;
}
