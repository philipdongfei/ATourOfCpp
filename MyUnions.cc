enum Type {str, num};

union Value {
    char* s;
    int i;
};

struct Entry {
    char* name;
    Type t;
    Value v;    // use v.s if t==str; use v.i if t==num
}

void f(Entry* p)
{
    if (p->t == str)
        cout<<p->v.s;
    //....
}


