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



