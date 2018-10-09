#include    <vector>
#include    <string>
#include    <iostream>

using namespace std;

struct Entry {
    string name;
    int number;
};

template<typename T>
class Vec : public std::vector<T> {
    public:
        using vector<T>::vector;        // use the constructors from vector (under the name Vec)

        T& operator[](int i)    // range check
        { return vector<T>::at(i); }

        const T& operator[](int i) const    // range check const objects; 4.2.1
        { return vector<T>::at(i); }
};

ostream& operator<<(ostream& os, const Entry& e)
{
    return os<<"{\""<<e.name<<"\","<<e.number<<"}";
}

istream& operator>>(istream& is, Entry& e)
    // read {"name", number} pair. Note: formatted with {"", and}
{
    char c, c2;
    if (is>>c && c=='{' && is>>c2 && c2=='"') {// start with a {"
        string name;    // the default value of a string is the empty string:""
        while(is.get(c) && c!='"')   // anything before a " is part of the name
            name+=c;

        if (is>>c && c==','){
            int number = 0;
            if (is>>number>>c && c=='}') {// read the number and a } 
                e = {name,number};    // assign to the entry
            return is;

            }
        }
    }
    is.setstate(ios_base::failbit); // register the failure in the stream
    return is;

}

vector<Entry> phone_book = {
    {"David Hume", 123456},
    {"Karl Popper", 234567},
    {"Bertrand Arthur William Russsell", 345678}
};

Vec<Entry> phone_book1 = {
    {"David Hume", 123456},
    {"Karl Popper", 234567},
    {"Bertrand Arthur William Russsell", 345678}
};

void print_book(const vector<Entry>& book)
{
#if 0
    for (int i = 0; i!=book.size(); ++i)
        cout<<book[i]<<'\n';
#endif

#if 1
    for(const auto& x : book)    // for "auto"see 1.5
        cout<<x<<'\n';
#endif
}


void checked(Vec<Entry>& book)
{
    try {
        book[book.size()] = {"Joe", 999999};
        //..
    }
    catch(out_of_range){
        cout<<"range error2\n";
    }
}



void input()
{
    for (Entry e; cin>>e;)
        phone_book.push_back(e);
}

int main(int argc, char* argv[])
{
    print_book(phone_book);

    input();

    print_book(phone_book);

    try {
        checked(phone_book1);
    }
    catch(out_of_range){
        cerr<<"range error1\n";

    }
    catch(...) {
        cerr<<"unknown exception thrown\n";
    }

    return 0;
}
