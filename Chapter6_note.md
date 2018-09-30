# 6 Library Overview

------------------------

## 6.1 Introduction

  The specification of the standard library is almost two thirds of the ISO C++ standard.

## 6.2 Standard-Library Components

The main criteria for including a class in the library were that:
- it could be helpful to almost every C++ programmer(both novices and experts),
- It could be provided in a general from that did not add significant overhead compared to a simpler version of the same facility, and
- that simple uses should be easy to learn (relative to the inherent complexity of their task).

## 6.3 Standard-Library Headers and Namespace

```

#include <string>
#include <list>

std::string s{"Four legs Good; two legs Baaad!"};
std::list<std::string> slogans{"War is Peace", "Freedom is Slavery", "Ignorance is Strength"};


```
```

#include <string>    // make the standard string facilities accessible
using namespace std; // make std names available without std::prefix

string s{"C++ is a general-purpose programming language"};   // OK: string is std::string.

```

|- Selected Standard Library Headers- |
|----------------|-------------------_|
|<algorithm>     |copy(),find(),sort()|



