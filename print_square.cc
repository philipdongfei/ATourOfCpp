#include    <iostream>      // include ("import") the declarations for the I/O stream library

using namespace std;        // make names from std visible without std::(3.3)

double square(double x)     // square a double precision floating-point number
{
    return x*x;
}

void print_square(double x)
{
    cout<<"the square of "<<x<<" is "<<square(x)<<"\n";
}

void print()
{
    int v[] = {0,1,2,3,4,5,6,7,8,9};

    for (auto x : v)    // for each x in v
        cout<<x<<'\n';

    cout<<"another example:\n";
    for (auto x : {10,21,32,43,54,65})
        cout<<x<<'\n';
}

int count_x(auto *p, auto x)
    // count the number of occurrences of x in p[]
    // p is assumed to point to a zero-terminated array of char(or to nothing)
{
    if (p == nullptr) return 0;
    
    int count = 0;

    while (*p) {
        if (*p == x)
            ++count;
        ++p;
    }
    return count;
}

bool accept()
{
    cout<<"Do you want to proceed(y or n)?\n";  // write question

    char answer = 0;    // initialize to a value that will not appear on input
    cin>>answer;        // read answer

    if (answer == 'y')
        return true;
    return false;
}

bool accept2()
{
    cout<<"Do you want to proceed(y or n)?\n";  // write question

    char answer = 0;    // initialize to a value that will not appear on input

    switch(answer) {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            cout<<"I'll take that for a no.\n";
            return false;
    }
}

/************************
 * test example , lost some function
 */
/*
void action()
{
    while(true) {
        cout<<"enter action:\n";    // request action
        string act;
        cin>>act;       // read characters into a string
        Point delta{0, 0};  // Point holds an {x, y} pair

        for (char ch : act) {
            switch (ch) {
                case 'u': //up
                case 'n':   // north
                    ++delta.y;
                    break;
                case 'r': // right
                case 'e':   //east
                    ++delta.x;
                    break;
                default:
                    cout<<"I freeze!\n";

            }
            move(current+delta*scale);
            update_display();
        }
    }

}
*/


int main()
{
    print_square(1.234);    // print: the square of 1.234 is 1.52276
    print();
    
    int v[] = {1,4,2,3,4,5,6,7,8,9,4};
    int x = 4;
    cout<<"array v's count is " << count_x(v,x) << '\n';

    if(accept())
        cout<<"true"<<'\n';
    else
        cout<<"false"<<'\n';
}
