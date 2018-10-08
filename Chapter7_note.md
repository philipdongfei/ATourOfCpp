# 7 Strings and Regular Expressions


## 7.1 Introduction

## 7.2 Strings

### 7.2.1 string Implementation

  **string** is usually implemented using the *short-string optimization*.
  To handle multiple character sets, **string** is really an alias for a general template **basic_string** with the character type **char**:

  ```

    template<typename Char>
    class basic_string {
        // ...string of Char...
    };

  ```
  `using string = basic_string<char>`
  `using Jstring = basic_string<Jchar>`


## 7.3 Regular Expressions

`regex pat{R"(\w{2}\s*\d{5}(-\d{4})?)"};`

  To express the pattern, I use a *raw string literal* starting with **R"(** and teminated by **)"**.

### 7.3.1 Searching

### 7.3.2 Regular Expression Notation

**Regular Expression Special Characters**

- **.**    Any single character(a "wildcard")
- **[**    Begin character class
- **]**    End character class
- **{**    Begin count
- **}**    End count
- **(**    Begin grouping
- **)**    End grouping
- **\**    Next character has a special meaning
- ** * **    Zero or more (suffix operation)
- **+**    One or more (suffix operation)
- **?**    Optional(zero or one) (suffix operation)
- **|**    Alternative(or)
- **^**    Start of line; negation
- **$**    End of line

**Repetition**

- **{n}**    Exactly **n** times
- **{n,}**   n or more times
- **{n,m}**  At least n and at most m times
- ** \* **      Zero or more, that is, {0,}
- **+**      One or more, that is, {1,}
- **?**      Optional (zero or one), that is {0,1}

**Character Classes**

- **alnum**    Any alphanumeric character
- **alpha**    Any alphabetic character
- **blank**    Any whitespace character that is not a line separator
- **cntrl**    Any control character
- **d**        Any decimal digit
- **digit**    Any decimal digit
- **graph**    Any graphical character
- **lower**    Any lowercase character
- **print**    Any printable character
- **punct**    Any punctuation character
- **s**        Any whitespace character
- **space**    Any whitespace character
- **upper**    Any uppercase character
- **w**        Any word character (alphanumeric characters plus the underscore)
- **xdigit**   Any hexadecimal digit character


**Character Class Abbreviations**

- **\d**    A decimal digit         **[[:digit:]]**
- **\s**    A space (space,tab,etc.)    **[[:space:]]**
- **\w**    A letter (a-z) or digit (0-9) or underscore(_)   **[_[:alnum:]]**
-----------------
- **\D**    Not \d                  **[^[:digit:]]**
- **\S**    Not \s                  **[^[:space:]]
- **\W**    Not \w                  **[^_[:alnum:]]**


**Nonstandard (but Common) Character Class Abbreviations**

- **\l**    A lowercase character      **[[:lower:]]
- **\u**    An uppercase character     **[[:upper:]]
- **\L**    Not \l                     **[^[:lower:]]**
- **\U**    Not \u                     **[^[:upper:]]

**Regular Expression Grouping Examples**

- ** \d*\s\w+ **      No groups (subpatterns)
- ** (\d*)\s(\w+) **    Two groups
- ** (\d*)(\s(\w+))+ **  Two groups (groups do not nest)
- ** (\s*\w*)+ **        One group; one or more subpatterns;
                       only the last subpattern is saved as a sub_match
- **<(.*?)>(.*?)</\1>**  Three groups; the \1 means "same as group 1"

A *greedy match* for the first subpattern would match the first < with the last >.






