# 11 Utilities

## 11.1 Introduction

## 11.2 Resource Management

  The standard library components are designed not to leak resources. To do this, they rely on the basic language support for resource management using constructor/destructor pairs to ensure that a resource doesn't outlive an object responsible for it.

###  11.2.1 unique_ptr and shared_ptr

  A **unique_ptr** is a handle to an individual object (or an array) in much the same way that a **vector** is a handle to a sequence of objects. Both control the lifetime of other objects(using RAII) and both rely on move semantics to make **return** simple and efficient.
  The **shared_ptr** is similar to **unique_ptr** except that **shared_ptr**s are copied rather than moved.The **shared_ptr**s for an object share ownership of an object and that object is destroyed when the last of its **share_ptr**s is destroys.
  Use **shared_ptr** only if you actually need shared ownership.
  Given **unique_ptr** and **shared_ptr**, we can implement a complete "no nake **new**" policy (4.2.2) for many programs.

## 11.3 Specialized Containers

  The number of elements in the initializer must be equal to or less than the number of elements specified for the **array**.
  If you need the element count to be a variable, use **vector**.
  Why would we use an **array** when **vector** is so much more flexible? Because an **array** is less flexible, it is simpler. Occasionally, there is a significant performance advantage to be had by directly accessing elements allocated on the stack rather than allocating elements on the free store, accessing them indirectly through the **vector** (a handle), and then deallocating them. On the other hand, the stack is a limited resource(especially on some embedded systems), and
  stack overflow is nasty.
  my main reason to prefer **array** is that it saves me from surprising nasty conversions to pointers.

### 11.3.2 bitset

### 11.3.3 pair and tuple

  A **pair** is common in interfaces because often we want to return more than one value.
  so **tuple**s are more often found in the implementations of generic algorithms.

## 11.4 Time

## 11.5 Function Adaptors

### 11.5.1 bind()

### 11.5.2 mem_fn()

  **mem_fn()** can be seen as a mapping from the object-oriented calling style to the functional one.

### 11.5.3 function

## 11.6 Type Functions

### 11.6.1 iterator_traits

### 11.6.2 Type Predicates


