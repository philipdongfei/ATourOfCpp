#include    <vector>
#include    <thread>
#include    <iostream>
#include    <utility>
#include    <chrono>
#include    <atomic>
#include    <future>
#include    <functional>

using namespace std;

void f(promise<int>& px)    // a task: place the result in px
{
    //...
    try {
        int res;
        // ... compute a value for res...
        res = 10.0;
        px.set_value(res);
        cout<<"f: "<<res<<'\n';

    }
    catch(...) {    // oops: couldn't compute res
        px.set_exception(current_exception());    // pass the exception to the future's thread
    }

}

void g(future<int>& fx)    // a task: get the result from fx
{
    // ...
    try {
        int v = fx.get();    // if necessary,wait for the value to get computed
        v *= 10;
        cout<<"g: "<< v <<'\n';
        // ... use v ...
    }
    catch(...) {    // oops: someone couldn't compute v
        // ... handle error ..
        cerr<<"g get v error"<<'\n';
    }
}

int main(void)
{

    promise<int> px;

    future<int> fut = px.get_future();
    thread t1{f, ref(px)};
    thread t2{g, ref(fut)};

    t1.join();
    t2.join();

    return 0;
}

