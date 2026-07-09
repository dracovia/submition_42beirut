# C++ Module 00

## Description

This project is the first module of the 42 C++ curriculum. Its purpose is to introduce the basic concepts of C++ and object-oriented programming while following the C++98 standard.

The module covers:

- Classes and objects
- Member functions
- Constructors and destructors
- Static members
- `const` member functions
- References
- Standard input/output streams
- Initialization lists
- Basic string formatting

## Compilation

All exercises are compiled using:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

Each exercise contains its own `Makefile`.

Available rules:

```bash
make
make clean
make fclean
make re
```

## Exercises

### ex00 — Megaphone

A simple program that converts all command-line arguments to uppercase.

Example:

```bash
./megaphone "shhhhh... I think the students are asleep..."
```

Output:

```text
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
```

If no argument is provided:

```text
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

Concepts used:

- Command-line arguments
- `std::cout`
- `std::toupper`
- Character handling

---

### ex01 — My Awesome PhoneBook

A simple phonebook program that can store up to 8 contacts.

Available commands:

```text
ADD
SEARCH
EXIT
```

Each contact contains:

- First name
- Last name
- Nickname
- Phone number
- Darkest secret

When more than 8 contacts are added, the oldest contact is replaced.

The `SEARCH` command displays contacts in four right-aligned columns of width 10:

```text
     index|first name| last name|  nickname
```

Long fields are truncated, and the last visible character is replaced with a dot.

Concepts used:

- Classes and objects
- Composition
- Private and public members
- Constructors and destructors
- References
- `const` member functions
- `std::getline`
- `std::istringstream`
- `std::setw`
- Fixed-size arrays

---

### ex02 — The Job Of Your Dreams

The goal of this exercise is to recreate the missing implementation of the `Account` class using:

- `Account.hpp`
- `tests.cpp`
- A reference log file

The program manages multiple bank accounts and tracks:

- Number of accounts
- Total amount
- Number of deposits
- Number of withdrawals
- Individual account balances and operations

The output must match the provided reference log, except for timestamps.

Concepts used:

- Static member variables
- Static member functions
- Initialization lists
- Constructors and destructors
- `const` member functions
- Timestamps using `<ctime>`
- Output formatting using `<iomanip>`

## Project Structure

```text
cpp_module_00/
├── ex00/
│   ├── Makefile
│   └── megaphone.cpp
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── Contact.hpp
│   ├── Contact.cpp
│   ├── PhoneBook.hpp
│   └── PhoneBook.cpp
└── ex02/
    ├── Makefile
    ├── Account.hpp
    ├── Account.cpp
    └── tests.cpp
```

## Resources

My main external learning resource for this project was:

- GeeksforGeeks

I used it mainly to better understand:

- C++ classes and objects
- Constructors and destructors
- Static members
- References
- `const` member functions
- Input/output streams
- `<iomanip>`
- `<ctime>`

The official 42 subject and provided files were used as the source of truth for all project requirements and expected behavior.

## Author

**mfassad**  
42 Student
