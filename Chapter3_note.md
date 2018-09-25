# Chapter 3 Modularity

-----------------------------

## 3.1 Introduction

-----------------------------

## 3.2 Separate Compilation

-----------------------------

## 3.3 Namespaces

  C++ offers *namespaces* as a mechanism for expressing that some declarations belong together and that their names shouldn't clash with other names.

----------------------------

## 3.4 Error Handling
  
  Instead of painstakingly building up our applications from the built-in types (e.g., **char, int,** and **double**) and statements (e.g., **if, while,** and *for**), we build more types that are appropriate for our applications (e.g., **string, map,** and **regex**) and algorithms (e.g., **sort(), find_if(),** and **draw_all()**).

### 3.4.1 Exceptions

(```)
    void f(Vector& v)
    {
        //...
        try {  // exceptions here are handled by the handler defined below
            v[v.size()] = 7; // try to access beyond the end of v
        }
        catch (out_of_range) { // oops: out_of_range error
            // ... handle range error ...
        }
        // ...
    }
(```)

 We put code for which we are interested in handling exceptions into a **try**-block. That attempted assignment to **v[v.size()]** will fail. Therefore, the **catch**-clause providing a handler for **out_of_range** will be entered.

  A function that should never throw an exception can be declared **noexcept**.

### 3.4.2 Invariants

### 3.4.3 Static Assertions

---------------------------
