# 5 Templates

-----------------

## 5.1 Introduction

  A *template* is a class or a function that we parameterize with a set of types or values.

## 5.2 Parameterized Types

  A template plus a set of template arguments is called an *instantiation*.

  A template value argument must be a constant expression.

## 5.3 Function Templates

## 5.4 Concepts and Generic Programming

Templates offer:

- The ability to pass types (as well as values and templates) as arguments without loss of information.
- Delay type checking (done at instantiation time).
- The ability to pass constant values as arguments.

In other words, templates provide a powerful mechanism for compile-time computation and type manipulation that can lead to very compact and efficient code.

  The first and most common use of templates is to support *generic programming*, that is, programming focused on the design, implementation, and use of general algorithms. Here, "general" means that an algorithm can be designed to accept a wide variety of types as long as they meet the algorithm's requirements on its arguments. The template is C++'s main support for generic programming. Templates provide(compile-time) parametric polymorphism.

