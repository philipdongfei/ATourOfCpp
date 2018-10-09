#include    <list>
#include    <iostream>

using namespace std;


struct Entry {
    string name;
    int number;
};

list<Entry> phone_book = {
    {"David Hume", 123456},
    {"Karl Popper", 234567},
    {"Bertrand Arthur William Russel", 345678}
};

int get_number(const string& s)
{
    for (const auto& x : phone_book)
        if (x.name == s)
            return x.number;
    return 0;  // use 0 to represent "number not found"
}

int get_number_exp(const string& s)
{
    for (auto p = phone_book.begin(); p!=phone_book.end(); ++p)
        if (p->name == s)
            return p->number;
    return 0;  // use 0 to represent "number not found"
}

void f(const Entry& ee, list<Entry>::iterator p, list<Entry>::iterator q)
{
    phone_book.insert(p,ee);    // add ee before the element referred to by p
    phone_book.erase(q);        // remove the element referred to by q
}

int main(int argc, char* argv[])
{
    cout<<"get_number 1: "<<get_number("David Hume")<<'\n';
    cout<<"get_number 2: "<<get_number_exp("David Hume")<<'\n';

    Entry ee{"Tom Johns", 456789};
    list<Entry>::iterator p = phone_book.begin();
    //++p;
    list<Entry>::iterator q = p;
    ++q;
    f(ee, p, q);
    for (const auto& x : phone_book)
        cout<<"name: "<<x.name<<'\n';

    return 0;


}

