#include "T_Vector.h"


template<typename T>
Vector<T>::Vector(int s)
{
    //if (s<0)
    //    throw Negative_size{};
    elem = new T[s];
    sz = s;
}
template<typename T>
Vector<T>::Vector(std::initializer_list<T> lst)
    :elem{new T[lst.size()]}, sz{static_cast<int>(lst.size())}
{
    copy(lst.begin(),lst.end(), elem);
}

template<typename T>
const T& Vector<T>::operator[](int i) const
{
    if(i<0 || size()<=i)
        throw out_of_range{"Vector::operator[]"};
    return elem[i];
}


template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a)
{
    T* p = new T[a.sz];
    for (int i=0; i!=a.sz; ++i)
        p[i]=a.elem[i];
    delete[] elem;  // delete old elements
    elem = p;
    sz = a.sz;
    return *this;
}
/* 
template<typename T>
T* begin(Vector<T>& x)
{
    return x.size() ? &x[0] : nullptr;  // pointer to first element or nullptr
}

template<typename T>
T* end(Vector<T>& x)
{
    return begin(x)+x.size();   // pointer to one-past-last element
}
*/

