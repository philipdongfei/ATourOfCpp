#include    <iostream>
#include    <stdexcept>

using namespace std;

class Vector {
    public:
        //Vector(int s):elem{new double[s]}, sz{s}{
        explicit Vector(int s) {
            // construct a Vector
            if (s<0)
                throw length_error{"Vector constructor:negative size"};
            elem = new double[s];
            sz = s;

        }    
        double& operator[](int i){ 
            if (i<0 || size()<=i)
                throw out_of_range{"Vector::operator[]"};
            return elem[i]; 
        }    // element access: subscripting
        int size() {return sz;}
    private: 
        double* elem;    // pointer to the elements
        int sz;     // the number of elements
};

double read_and_sum(int s)
{
    try {
        Vector v(s);
        for (int i=0; i!=v.size(); ++i)
        {
            std::cin>>v[i];      // read into elements
            double sum = 0;
            for (int i=0; i!=v.size(); ++i)
                sum+=v[i];      // take the sum of the elements
            return sum;
        }
    }
    catch(std::length_error) {
        // handle negative size.
        cout<<"test failed: length error\n";
        throw;
        return -1;
    }
    catch(std::bad_alloc) {
        // handle memory exhaustion.
        // Ouch! read_and_sum is not desighned to handle memory exhaustion.
        std::terminate(); // terminate the program.
        return -1;
    }
    catch (out_of_range) { // oops: out_of_range error
        // ... handle range error ...
        return -1;
    }
}
/*
double read_and_sum(int s)
{
    try {
    Vector v(s);        // make a vector of s elements
    }

    }
    catch(std::length_error) {
        // handle negative size.
        return -1;
    }
    catch(std::bad_alloc) {
        // handle memory exhaustion.
        return -1;
    }
    for (int i=0; i!=v.size(); ++i)
    {
        try { // exceptions here are handled by the handler defined below
            std::cin>>v[i];      // read into elements
            double sum = 0;
            for (int i=0; i!=v.size(); ++i)
                sum+=v[i];      // take the sum of the elements
            return sum;
        }
        catch (out_of_range) { // oops: out_of_range error
            // ... handle range error ...

            return -1;
        }
    }


    //double sum = 0;
    //for (int i=0; i!=v.size(); ++i)
    //    sum+=v[i];      // take the sum of the elements
    //return sum;
}
*/

int main(int argc, char* argv[])
{
    double dbValue{0};
    int s{5};

    dbValue = read_and_sum(s);
    std::cout<<"sum="<<dbValue<<'\n';
    return 0;
}


