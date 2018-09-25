//Vector.h

class Vector {
    public:
        Vector(int s):elem{new double[s]}, sz{z}   // constructor: acquire resources
        {
            for (int i=0; i!=s; ++i)    // initialize elements
                elem[i]=0;
        }
        
        ~Vector() {delete[] elem;}  // destructor: release resources
        
        double& operator[](int i);
        int size()const;
    private:
        double* elem;       // elem points to an array of sz doubles
        int sz;

};

