//Vector.h

class Vector {
    public:
        Vector(int s):elem{new double[s]}, sz{z}   // constructor: acquire resources
        {
            for (int i=0; i!=s; ++i)    // initialize elements
                elem[i]=0;
        }
        
        ~Vector() {delete[] elem;}  // destructor: release resources

        Vector(const Vector& a);    // copy constructor
        Vector& operator=(const Vector& a); // copy assignment

        Vector(Vector&& a);     // move constructor
        Vector& operator=(Vector&& a);  // move assignment

        
        double& operator[](int i);
        const double& operator[](int i) const;

        int size()const;
    private:
        double* elem;       // elem points to an array of sz doubles
        int sz;

};

Vector::Vector(const Vector& a)  // copy constructor
    :elem{new double[a.sz]},    // allocate space for elements
    sz{a.sz}
{
    for (int i=0; i!=sz; ++i)
        elem[i] = a.elem[i];
}

Vector& Vector::operator=(const Vector& a)    // copy assignment
{
    double* p = new double[a.sz];
    for (int i=0; i!=a.sz; ++i)
        p[i]=a.elem[i];
    delete[] elem;    // delete old elements
    elem = p;
    sz = a.sz;
    return *this;
}

// Abstract Types.
// superclass
class Container {
public:
    virtual double& operator[](int)=0;      // pure virtual function
    virtual int size() const = 0;           // const member function
    virtual ~Container(){}                  // destructor

};

// subclass
// polymorphic type
class Vector_container : public Container { // Vector_container implements Container
    Vector v;
public:
    Vector_container(int s) : v(s) {}   // Vector of s elements
    ~Vector_container(){}

    double& operatorp[](int i){ return v[i]; }
    int size() const { return v.size(); }

};

class List_container : public Container {   // List_container implements Container
    std::list<double> ld;   // (standard-library) list of doubles 
public:
    List_container(){}  // empty list
    List_container(initialize_list<double> il) : ld{il}{}
    ~List_container(){}

    double& operator[](int i);
    int size() const { return ld.size(); }

};

double& List_container::operator[](int i)
{
    for (auto& x : ld) {
        if (0 == i) return x;
        --i;
    }
    throw out_of_range{"List container"};
}

// use Container class
void use(Container& c)
{
    const int sz = c.size();

    for (int i=0; i!=sz; ++i)
        cout<<c[i]<<'\n';
}

// example
void g()
{
    Vector_container vc(10);    // ten elements
    // ... fill vc ...
    use(vc);

}

void h()
{
    List_container lc = {1,2,3,4,5,6,7,8,9};
    use(lc);
}

// 4.5 class Hierarchies
class Shape {
public:
    Shape(const Shape&)=delete;     // no copy operations
    Shape& operator=(const Shape&)=delete;

    Shape(Shape&&)=delete;  //no move operations
    Shape& operator=(Shape&&)=delete;



    virtual Point center() const=0; // pure virtual
    virtual void  move(Point to)=0;

    virtual void draw() const = 0;  // draw on current "Canvas"
    virtual void rotate(int angle) = 0;

    virtual ~Shape(){}      // destructor
    //...
};

class Circle : public Shape {
public:
    Circle(Point p, int rr);    // constructor

    Point center() const{ return x; }
    void move(Point to) { x=to; }

    void draw() const;
    void rotate(int){}      // nice simple algorithm
private:
    Point x;    // center
    int r;      // radius
};

class Smiley : public Circle {  // use the circle as the base for a face
public:
    Smiley(Point p, int r) : Circle{p, r}, mouth{nullptr}{}

    ~Smiley()
    {
        delete mouth;
        for (auto p : eyes)
            delete p;
    }

    void move(Point to);

    void draw()const;
    void rotate(int);

    void add_eye(Shape* s) { eyes.push_back(s); }
    void set_mouth(Shape* s);
    virtual void wink(int i);   // wink eye number i

    //...
private:
    vector<Shape*> eyes;    // usually two eyes
    Shape* mouth;
};

void Smiley::draw()const
{
    Circle::draw();
    for (auto p : eyes)
        p->draw();
    mouth->draw();
}


