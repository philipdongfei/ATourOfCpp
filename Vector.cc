// Vector.cc

#include    "Vector.h" // get the interface

Vector::Vector(int s)
    :elem{new double[s]}, sz{s} // initialize members
{

}

double& Vector::operator[](int i)
{
//    return elem[i];
// Error Handling, Exceptions
    if (i<0 || size()<=1)
        throw out_of_range{"Vector::operator[]"};
    return elem[i];
}

int Vector::size()
{
    return sz;
}
