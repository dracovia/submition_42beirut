# C++ Module 01

**Author:** mfassad  
**School:** 42 Beirut  
**Project:** C++ Module 01 — Memory Allocation, Pointers to Members, References, and Switch Statements

---

## About the Project

This module introduces several fundamental C++ concepts, especially dynamic memory allocation, references, pointers, file streams, pointers to member functions, and switch statements.

All exercises are written in **C++98** and compiled with:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

---

## Exercises

### ex00 — BraiiiiiiinnnzzzZ

Introduces stack and heap allocation through a `Zombie` class.

Main concepts:
- Creating objects on the stack and heap
- Using `new` and `delete`
- Object lifetime
- Constructors and destructors

Functions implemented:

```cpp
Zombie* newZombie(std::string name);
void randomChump(std::string name);
```

`newZombie()` creates a zombie on the heap and returns a pointer to it, while `randomChump()` creates a zombie on the stack that is automatically destroyed when the function ends.

---

### ex01 — Moar brainz!

Creates a dynamically allocated array of zombies in a single allocation.

Main concepts:
- Dynamic arrays
- `new[]`
- `delete[]`
- Default constructors
- Initializing multiple objects

Main function:

```cpp
Zombie* zombieHorde(int N, std::string name);
```

The returned pointer points to the first zombie in the allocated array.

---

### ex02 — HI THIS IS BRAIN

Introduces pointers and references using a `std::string`.

Main concepts:
- Variable addresses
- Pointers
- References
- Dereferencing
- References as aliases

The program prints:
- The address of the original string
- The address stored by the pointer
- The address represented by the reference
- The values accessed through each form

---

### ex03 — Unnecessary Violence

Introduces references and pointers as class attributes through `Weapon`, `HumanA`, and `HumanB`.

Main concepts:
- References as class members
- Pointers as class members
- Initialization lists
- Object relationships
- `const` references

`HumanA` always has a weapon, so it stores a reference:

```cpp
Weapon& _weapon;
```

`HumanB` may exist without a weapon, so it stores a pointer:

```cpp
Weapon* _weapon;
```

---

### ex04 — Sed is for losers

Creates a program that reads a file and replaces every occurrence of one string with another without using `std::string::replace()`.

Main concepts:
- `std::ifstream`
- `std::ofstream`
- `std::string::find()`
- `std::string::substr()`
- File input and output
- Error handling

Usage:

```bash
./sed <filename> <s1> <s2>
```

The program creates:

```text
<filename>.replace
```

---

### ex05 — Harl 2.0

Introduces pointers to member functions.

Main concepts:
- Member-function pointers
- Arrays of member-function pointers
- Dynamic function dispatch without a long `if / else if` chain

Example declaration:

```cpp
void (Harl::*functions[4])(void);
```

Example call:

```cpp
(this->*functions[i])();
```

Available complaint levels:
- `DEBUG`
- `INFO`
- `WARNING`
- `ERROR`

---

### ex06 — Harl Filter

Filters Harl's complaint messages by severity level.

Main concepts:
- `switch`
- Intentional fall-through
- Command-line arguments

Example:

```bash
./harlFilter WARNING
```

Output includes:

```text
WARNING
ERROR
```

because the `switch` statement intentionally falls through from the selected level to all more severe levels.

---

## Key Concepts Learned

### Stack vs Heap

```cpp
Zombie zombie("Bob");
```

Creates an object on the stack. It is automatically destroyed when its scope ends.

```cpp
Zombie* zombie = new Zombie("Bob");
```

Creates an object on the heap. It must be manually destroyed:

```cpp
delete zombie;
```

For arrays:

```cpp
Zombie* horde = new Zombie[N];
delete[] horde;
```

---

### Pointer vs Reference

Pointer:

```cpp
std::string* ptr = &str;
```

Access value:

```cpp
*ptr
```

Reference:

```cpp
std::string& ref = str;
```

A reference acts as another name for the original object.

---

### `.` vs `->`

For an object:

```cpp
zombie.announce();
```

For a pointer:

```cpp
zombiePtr->announce();
```

---

### `const` Reference

Example:

```cpp
const std::string& getType(void) const;
```

The first `const` prevents modification of the returned string through the reference.

The second `const` means the member function does not modify the object.

---

## Compilation

Each exercise contains its own `Makefile`.

Compile with:

```bash
make
```

Remove object files:

```bash
make clean
```

Remove object files and executable:

```bash
make fclean
```

Recompile everything:

```bash
make re
```

---

## General Rules Followed

- C++98 standard
- Compilation with `-Wall -Wextra -Werror`
- No `printf()`
- No `malloc()`, `calloc()`, `realloc()`, or `free()`
- No `using namespace std`
- No STL containers or algorithms
- Include guards in every header
- Proper use of `new`, `delete`, `new[]`, and `delete[]`
- No memory leaks

---

## Main Learning Outcome

The most important lesson from this module is understanding how object lifetime and ownership work in C++.

By the end of C++ Module 01, I gained practical experience with:
- choosing between stack and heap allocation,
- deciding when to use a pointer or a reference,
- managing dynamically allocated memory safely,
- using C++ file streams,
- calling member functions through pointers,
- and using switch fall-through intentionally.

