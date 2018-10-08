#include <iostream>

using namespace std;

void f()
{
    int i;
    cin >> i;   // read an integer into i

    double d;
    cin >> d;   // read a double-precision floating-point number into d

}

void f1()
{
    int i;
    double d;
    cin>>i>>d;    // read into i and d
}

void hello()
{
    cout<<"Please enter your name\n";
    string str;
    cin>>str;
    cout<<"Hello, "<<str<<"!\n";
}

void hello_line()
{
    cout<<"Please enter your name:\n";
    string str;
    getline(cin, str);
    cout<<"Hello, "<<str<<"!\n";
}

int main(int argc, char* argv[])
{
    //f();
    //cout<<'\n';
   // f1();
    //cout<<'\n';
    hello();
   // cout<<'\n';
    //hello_line();
    //cout<<'\n';

    return 0;
}
