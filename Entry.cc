#if 0
#include <vector>
#include <list>
#include <string>
#include <iostream>

using namespace std;


struct Entry {
    string name;
    int number;
};
#endif

#include    "Entry.h"


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

bool operator<(const Entry& x, const Entry& y)   // less than
{
    return x.name<y.name;    // order Entrys by their names
}


