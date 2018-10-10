/*********************
 * some problem.
 * core dumped.
 *
 *********************/
#include    <vector>
#include    <list>
#include    <iostream>
#include    <string>
#include    <algorithm>
#include    "Entry.h"


using namespace std;

vector<Entry> phone_book = {
    {"David Hume", 123456},
    {"Karl Popper", 234567},
    {"Bertrand Arthur William Russsell", 345678}
};

void f(vector<Entry>& vec, list<Entry>& lst)
{
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), lst.begin());
}

list<Entry> f(vector<Entry>& vec)
{
    list<Entry> res;
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), back_inserter(res));  // append to res
    return res;
}

int main(int argc, char* argv[])
{
    list<Entry> lst;
    list<Entry> lst1;
    f(phone_book, lst);
    //for (const auto& x : lst)
    //    cout<<"name: "<<x.name<<'\n';
    for (auto p = lst.begin();p!=lst.end();++p)
        cout<<"name: "<<p->name<<'\n';
    
    lst1 = f(phone_book);
    for (const auto& x : lst1)
        cout<<"lst1 name: "<<x.name<<'\n';

    return 0;
    
}
