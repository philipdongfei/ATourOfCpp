# 9 Containers


## 9.1 Introduction

  A class with the main purpose of holding objects is commonly called a *container*.

## 9.2 Vector

  A **vector** is a sequence of elements of a given type. The elements are stored contiguously in memeory.

### 9.2.1 Elements

  When you insert a new element, its value is copied into the container.
  If you have a class hierachy(4.5) that relies on **virtual** functions to get polymorphic behavior, do not store objects directly in a container. Instead store a pointer.

  `vector<Shape> vs;`      // No, don't-there is no room for a Circle or a Smiley
  `vector<Shape*> vps;`    // better, but see 4.5.4
  `vector<unique_ptr<Shape>> vups;`    // OK

### 9.2.2 Range Checking 
  
  The standard-library **vector** does not guarantee range checking.

## 9.3 list

```

int get_number(const string& s)
{
    for(auto p = phone_book.begin();p!=phone_book.end();++p)
        if (p->name==s)
            namereturn->number;
    return 0;  // use 0 to represent "number not found"
}

```
In fact, this is roughly the way the terse and less error-prone range-**for** loop is implemented by the compiler. Given an iterator **p**, **\*p** is the element to which it referes, **\+\+p** advances **p** to refer to the next element, and when **p** refers to a class with a member **m**, then **p->m** is equivalent to **\(\*p\)\.m**.

## 9.4 map

  The standard library to offers a search tree (a red-black tree) called **map**.
  If a **key** isn't found, it is entered into the **map** with a default value for its **value**. The default value for an integer type is **0**.

## 9.5 unordered_map


## 9.6 Container Overview

  The unordered containers are optimized for looking with a key (often a string); in other words, they are implemented using hash tables.
  Basic operations apply to every kind of container for which they make sense and can be efficiently implemented. For example:
  - **begin()** and **end()** give iterators to the first and one-beyond-the-last elements, respectively.
  - **push_back()** can be used (efficiently) to add elements to the end of a **vector**, **list**, and other containers.
  - **size()** returns the number of elements.

  This notational and semantic uniformity enables programmers to provide new container types that can be used in a very similar manner to the standard ones.
  I recommend the standard-library **vector** as the default type for sequences of elements: you need a reason to choose another.


