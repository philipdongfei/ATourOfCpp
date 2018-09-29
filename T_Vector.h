#include    <iostream>
#include    <stdexcept>

using namespace std;

template<typename T>
class Vector {
    private:
        T* elem;    // elem points to an array of sz elements of type T
        int sz;
    public:
        explicit Vector(int s); // constructor: establish invariant, acquire resources
        Vector(std::initializer_list<T>);
        ~Vector(){ delete[] elem; } // destructor: release resources

T* begin(Vector<T>& x)const
{
    return x.size() ? &x[0] : nullptr;  // pointer to first element or nullptr
}
T* end(Vector<T>& x) const
{
    return begin(x)+x.size();   // pointer to one-past-last element
}
        // ... copy and move operations ...
        Vector<T>& operator=(const Vector<T>& a);

        T& operator[](int i);
        const T& operator[](int i)const;
        int size() const {return sz;}
};
/*
template<typename T>
T* begin(Vector<T>& x)const
{
    return x.size() ? &x[0] : nullptr;  // pointer to first element or nullptr
}

template<typename T>
T* end(Vector<T>& x) const
{
    return begin(x)+x.size();   // pointer to one-past-last element
}
*/

