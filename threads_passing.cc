#include    <thread>
#include    <iostream>
#include    <utility>
#include    <chrono>
#include    <atomic>
#include    <vector>

using namespace std;

void f(vector<double>& v);    // function do something whith v

struct F {     // function object: do something with V
    vector<double>& v;
    F(vector<double>& vv):v{vv}{}
    void operator()(){ for(auto& x : v) cout<<"F:"<<x<<'\n'; }     // application operator; 5.5


};


int main(void)
{
    vector<double> some_vec{1,2,3,4,5,6,7,8,9};
    vector<double> vec2{10,11,12,13,14};

    thread t1{f, ref(some_vec)};    // f(some_vec) executes in a separate thread
    thread t2{F{vec2}};      // F(vec2)() executes in a separate thread

    t1.join();
    t2.join();

    return 0;
}

void f(vector<double>& v)
{
    for(auto& x : v)
        cout<<"f:"<<x<<'\n';

}
