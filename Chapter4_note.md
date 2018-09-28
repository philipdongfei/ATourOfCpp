# 4 Classes

---------------------

## 4.1 Introduction

  The central language feature of C++ is the *class*. A class is a user-defined type provided to reperesent a concept in the code of a program.

## 4.2 Concrete Types

  The basic idea of *concrete classes* is that they behave "just like built-in types".

### 4.2.1 An Arithmetic Type

### 4.2.2 A Container

  A container is an object holding a collection of elements, so we call **Vector** a container because it is the type of objects that are containers.

  We need a mechanism to ensure that the memory allocated by the constructor is deallocated; that mechanism is a destructor:

  ```
  class Vector {
  private:
    double* elem;   // elem points to an array of sz doubles
    int sz;
  public:
    Vector(int s):elem{new double[s]},sz{s} // constructor: acquire resources
    {
        for (int i=0; i!=s; ++i)    // initialize elements
            elem[i]=0;
    }

    ~Vector(){delete[] elem;}   // destructor: release resources

    double& operator[](int i);
    int size() const;

  };

  ```
  The constructor/destructor combination is the basic of many elegant techniques.

  This *handle-to-data model* is very commonly used to manage data that can vary in size during the lifetime of an object. The technique of acquiring resources in a constructor and releasing them in a destructor, known as *Resource Acquisition Is Initialization* or *RAII*, allows us to eliminate "nake **new** operations," that is, to avoid allocations in general code and keep them buried inside the implementation of well-behaved abstractions. Similary, "naked **delete**
  operations" should be avoided.

### 4.2.3 Initializing Containers

  Explicit type conversions (often called *casts* to remind you that they are used to prop up something broken) are best avoided.

## 4.3 Abstract Types

  Types such as **complex** and **Vector** are called *concrete types* because their representation is part of their definition. In that, they resemble built-in types. In contrast, an *abstract type* is a type that completely insulates a user from implementation details.

  First, we define the interface of a class **Container** which we will design as a more abstract version of our **Vector**:
  
  ```
  class Container {
  public:
    virtual double& operator[](int)=0;      // pure virtual function
    virtual int size() const=0;     // const member function
    virtual ~Container(){}      // destructor
  };

  ```

This class is a pure interface to specific containers defined later. The word virtual means "may be redefined later in a class derived from this one." Unsurprisingly, a function declared **virtual** is called a *virtual function*. A class derived from **Container** provides an implementation for the **Container** interface. The curious **=0** syntax says the function is *pure virtual*; that is, some class derived from **Container** *must* define the function.
  A class with a pure virtual function is called an *abstract class*.

  As is common for abstract classes, **Container** does not have a constructor. After all, it does not have any data to initialize. On the other hand, **Container** does have a destructor and that destructor is **virtual**.

  ```

  class Vector_container:public Container { // Vector_container implements Container
    Vector v;
  public:
    Vector_container(int s):v(s){}  // Vector of s elements
    ~Vector_container(){}

    double& operator[](int i){ return v[i]; }
    int size() const { return v.size(); }
    };

  ```

  The **:public** can be read as "is derived from" or "is a subtype of." Class **Vector_container** is said to be *derived* from class **Container**, and class **Container** is said to be *a base* of class **Vector_container**. An alternative terminology calls **Vector_container** and **Container** *subclass* and *superclass*, respectively.

## 4.4 Virtual Functions

  The usual implementation technique is for the compiler to convertthe name of a virtual function into an index into a table of pointers to functions. The table is usually called the *virtual function table* or simple the **vtbl**.

## 4.5 Class Hierarchies

  A *class hierarchy* is a set of classes ordered in a lattice create by derivation (e.g., **:public**). 

### 4.5.1 Explicit Overriding

### 4.5.2 Benefits

- *Interface inheritance*: An object of a derived class can be used wherever an object of a base class is required.
- *Implementation inheritance*: A base class provides functions or data that simplifies the Implementation of derived classes.

  Concrete classes - especially classes with small representations - are much like built-in types: we define them as local variables, access them using their names, copy them around, etc. Classes in class hierarchies are different: we tend to allocate them on the free store using **new**, and we access them through pointers or references.

  ```

  void user()
  {
    std::vector<Shape*> v;
    while(cin)
        v.push_back(read_shape(cin));
    draw_all(v);    //call draw() for each element
    rotate_all(v, 45);  // call rotate(45) for each element
    for(auto p : v)     // remember to delete elements
        delete p;
  }


  ```

  The **user()** code can be compiled once and later used for new **Shape**s added to the program.

### 4.5.3 Hierarchy Navigation

```

Shape* ps{read_shape(cin)};

if (Smiley* p = dynamic_cast<Smiley*>(ps)) { // ... does ps point to a Smiley? ...
    // ... a Smiley; use it
} 
else {
    // ... not a Smiley, try something else.
}

```

If the object pointed to by the argument of **dynamic_cast**(here, **ps**) is not of the exprected type (here, **Smiley**) or a class derived from the expected type, **dynamic_cast** returns **nullptr**.

### 4.5.4 Avoiding Resource Leaks

left open two obvious opportunities for mistakes:
- A user might fail to **delete** the pointer returned by **read_shape()**
- The owner of a container of **Shape** pointers might not **delete** the objects pointed to.

  One solution to both problems is to return a standard-library **unique_ptr**(11.2.1) rather than a "naked pointer" and store **unique_ptr**s in the container:

  ```

  unique_ptr<Shape> read_shape(istream& is)  // read shape descriptions from input stream is
  {
    // read shape header from is and find its Kind k
    switch(k) {
    case Kind::circle:
        // read circle data {Point,int} into p and r
        return unique_ptr<Shape>{new Circle{p,r}};
    // ...
    }
  }

  void user()
  {
    vector<unique_ptr<Shape>> v;
    while(cin)
        v.push_back(read_shape(cin));
    draw_all(v);        // call draw() for each element
    rotate_all(v,45);   // call rotate(45) for each element
  } // all shapes implicitly destroyed

  ```

## 4.6 Copy and Move

  By default, objects can be copied. The default meaning of copy is memberwise copy: copy each member.

### 4.6.1 Copying Containers

  Copying of an object of a class is defined by two members: a *copy constructor* and a *copy assignment*:

  ```

  class Vector {
  private:
    double* elem;   // elem points to an array of sz doubles
    int sz;
  public:
    Vector(int s);
    ~Vector(){delete[] elem;}

    Vector(const Vector& a);    // copy constructor
    Vector& operator=(const Vector& a); // copy assignment

    double& operator[](int i);
    const double& operator[](int i) const;

    int size() const;
  };

  ```

  A suitable definition of a copy constructor for **Vector** allocates the space for the required number of elements and then copies the elements into it, so that after a copy each **Vector** has its own copy of the elements:

  ```

  Vector::Vector(const Vector& a)   // copy constructor
    :elem{new double[a.sz]},        // allocate space for elements
    sz{a.sz}
    {
        for (int i=0; i!=sz; ++i)   // copy elements.
            elem[i] = a.elem[i];
    }
    
  Vector& Vector::operator=(const Vector& a)
  {
    double* p = new double[a.sz];
    for (int i=0; i!=a.sz; ++i)
        p[i] = a.elem[i];
    delete[] elem;  //delete old elements
    elem = p;
    sz = a.sz;
    return *this;
  }

  ```

### 4.6.2 Moving Containers

  We didn't really want a copy; we just wanted to get the result out of a function: we wanted to *move* a **Vector** rather than to *copy* it.

  ```

  class Vector {
    // ...

    Vector(const Vector& a);    // copy constructor
    Vector& operator=(const Vector& a); // copy assignment

    Vector(Vector&& a);     // move constructor
    Vector& operator=(Vector&& a);      // move assignment

  };

  Vector::Vector(Vector&& a)
    :elem{a.elem},      // "grab the elements" from a
    sz{a.sz}
    {
        a.elem = nullptr;   // now a has no elements
        a.sz = 0;
    }


  ```

  The **&&** means "rvalue reference" and is a reference to which we can bind an rvalue. The word "rvalue" is intended to complement "lvalue", which roughly means "something that can appear on the left-hand side of an assignment." So an rvalue is - to a first approximation - a value that you can't assign to, such as an integer returned by a function call. Thus, an rvalue reference is a reference to something that *nobody else* can assign to, so that we can safely "steal" its value.
    A move constructor does *not* take a **const** argument: after all, a move constructor is supposed to remove the value from its argument. A *move assignment* is defined similary.
    
    ```
    
    Vector f()
    {
        Vector x(1000);
        Vector y(1000);
        Vector z(1000);
        z = x;  // we get a copy
        y = std::move(x);   // we get a move
        return z;           // we get a move
    }

    ```
before the **return** we have: x.elem = nullptr.
when **z** is destroyed, it too has been moved from (by the **return**) so that, like **x**, it is empty (it holds no elements, z.elem = nullptr).
    

### 4.6.3 Essential Operations

  If you want to be explicit about generating **[default implementations](https://blog.csdn.net/fengbingchun/article/details/52475155)**, you can:

  ```

  class Y {
  public:
    Y(Sometype);
    Y(const Y&) = default;    // I really do want the default copy constructor
    Y(Y&&)=default;     // and the default move constructor
    // ...

  };

  ```
  If you are explicit about some deafults, other default definitions will not be generated.

  This implicit conversion is sometimes ideal, but not always. For example, **Vector**(4.2.2) provides a constructor from an **int**:

  `Vector v1 = 7; // OK: v1 has 7 elements`
  
  This is typically considered unfortunate, and the standard-library **vector** does not allow this **int**-to-**vector** "conversion."
  The way to avoid this problem is to say that only explicit "conversion" is allowed; that is, we can define the constructor like this;

  ```

  class Vector {
  public:
    explicit Vector(int s); // no implicit conversion from int to Vector
    // ...
  }

  ```
  That gives us:
  `Vector v1(7);  // OK: v1 has 7 elements`
  `Vector v2 = 7;  // error: no implicit conversion from int to Vector`

### 4.6.4 Resource Management

  C++ also offers a garbage collection interface so that you can plug in a garbage collector. However, I consider garbage collection the last alternative after cleaner, more general, and better localized alternatives to resource management have been exhausted.
  Before resorting to garbage collection, systematically use resource handles: Let each resource have an owner in some scope and by default be released at the end of its owners scope. In C++, this is known as **RAII** (*Resource Acquisition Is Initialization*) and is integrated with error handling in the form of exceptions.

### 4.6.5 Suppressing Operations

  Using the default copy or move for a class in a hierarchy is typically a disaster. So, the best thing to do is usually to *delete* the default copy and move operations, that is, to eliminate the default definitions of those two operations:

  ```

  class Shape {
  public:
    Shape(const Shape&)=delete;     // no copy operations
    Shape& operator=(const Shape&)=delete;

    Shape(Shape&&)=delete;      // no move operations
    Shape& operator=(Shape&&)==delete;

    virtual ~Shape();
    //....
  };

  ```
  Now an attempt to copy a **Shape** will be caught by the compiler. If you need to copy an object in a class hierarchy, write a **virtual** clone function.







