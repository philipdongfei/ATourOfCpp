#include    <iostream>

using namespace std;

void f()
{
    cout<<10;
}

void g()
{
    int i{10};
    cout<<i;
}

void h(int i)
{
    cout<<"the value of i is ";
    cout<<i;
    cout<<'\n';
}

void h2(int i)
{
    cout<<"the value of i is "<<i<<'\n';
}

void k()
{
    int b = 'b';
    char c = 'c';
    cout<<'a'<<b<<c;
}

int main(int args, char* argv[])
{

    f();
    cout<<'\n';
    g();
    cout<<'\n';
    h(10);
    cout<<'\n';
    h2(12);
    cout<<'\n';
    k();
    cout<<'\n';

    return 0;


}
