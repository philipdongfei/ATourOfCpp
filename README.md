# A Tour Of Cpp
Book: A Tour of C++
Author: Bjarne Stroustrup

Write some notes and Code example.

-------------------------------

## Chapter 1 The Basic
### 1.2 Programs

The ISO C++ standard defines two kinds of entities:
* Core language features, such as built-in (eg., **char** and **int**) and loops (e.g., **for**-statements and **while**-statements)
* Standard-library components, such as containers (e.g., **vector** and **map**) and I/O operations (e.g., **<<** and **getline()**)

### 1.4 Functions

  A function declaration gives the name of the function, the type of the value returned (if any),
and the number and types of the arguments that must be supplied in a call.
  The number of errors in code correlates strongly with the amount of code and the complexity of the code. Both problems can be addressed by **using more and shorter functions**.

### 1.5 Types, Variables, and Arithmetic

  C++ offers a variefy of notations for expressing initialization, such as the = and the {}.the best choice is the {}. It saves you from conversions that lose information.

  We use **auto** where we don't have a specific reason to mention the type explicitly. "Specific reasons" include:
* The definition is in a large scope where we want to make the type clearly visible to readers of our code.
* We want to be explicit about a variable's range or precision (e.g., double rather than float).
Using **auto**, we avoid redundancy and writing long type names.

### 1.6 Scope and Lifetime

* Local scope: A name declared in a function or lambda is called a local name. Its scope extends from its point of declaration to the end of the block in which its declaration occurs. A *block* is delimited by a **{}** pair. Function argument names are considered local names.
* Class scope: A name is called a member name (or a class member name) if it is defined in a class (2.2,2.3, chapter 4), outside any function (1.4), lambda(5.5, or **enum class**(2.5). Its scope extends from the opening { of its enclosing declaration to the end of that declaration. 
* Namespace scope: A name is called a  *namespace member name* if it is defined in a namespace(3.3) outside any function, lambda(5.5), class(2.2, 2.3, chapter 4), or **enum class**(2.5). Its scope extends from the point of declaration to the end of its namespace.


### 1.7 Constants

* const: meaning roughly "I promise not to change this value."
* constexpr: meaning roughly "to be evaluated at compile time."

### 1.8 Pointers, Arrays, and References

  In a declaration, the unary suffix **&** means "reference to." A reference is similar to a pointer, except that you don't need to use a prefix * to access the value referred to by the reference.
  When we don't want to modify an argument, but still don't want the cost of copying, we use a const reference.
  using **nullptr** eliminates potential confusion between integers (such as **0** or **NULL**) and pointers(such as **nullptr**).

