*This project has been created as part of the 42 curriculum by mfassad.*

# C++ Module 00

## Description

C++ Module 00 is the first project in the 42 C++ curriculum. Its goal is to introduce the fundamental differences between C and C++ while building a foundation in object-oriented programming.

The module is written according to the **C++98 standard** and introduces concepts such as:

- Namespaces
- Classes and objects
- Public and private members
- Member functions
- Constructors and destructors
- Initialization lists
- Static members
- Constant member functions
- Standard input and output streams
- Basic string formatting

The project contains three exercises of increasing difficulty.

## Exercises

### Exercise 00 — Megaphone

A command-line program that converts all arguments passed to it into uppercase text.

When no arguments are provided, it prints:

```text
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

This exercise introduces:

- Command-line arguments
- Standard output
- Character conversion
- Basic C++ program structure

### Exercise 01 — My Awesome PhoneBook

A simple command-line phonebook that stores up to eight contacts.

The program supports the following commands:

- `ADD` — adds a new contact.
- `SEARCH` — displays saved contacts and allows the user to select one.
- `EXIT` — closes the program.

Each contact contains:

- First name
- Last name
- Nickname
- Phone number
- Darkest secret

When more than eight contacts are added, the oldest contact is replaced.

This exercise introduces:

- Classes and objects
- Encapsulation
- Arrays of objects
- Getters and setters
- Input validation
- Formatted output with `<iomanip>`
- Circular replacement of stored contacts

### Exercise 02 — The Job of Your Dreams

This exercise recreates the missing implementation of an `Account` class by studying the provided header file, test file, and expected log output.

The program manages multiple bank accounts and records:

- Account creation and destruction
- Deposits
- Withdrawals
- Individual account balances
- Total number of accounts
- Total amount of money
- Total deposits and withdrawals
- Timestamped account activity

This exercise introduces:

- Static class attributes
- Static member functions
- Initialization lists
- Constructors and destructors
- Constant member functions
- Timestamp formatting
- Reconstructing an implementation from an interface and expected behavior

## Project Structure

```text
cpp_module_00/
├── README.md
├── ex00/
│   ├── Makefile
│   └── megaphone.cpp
├── ex01/
│   ├── Makefile
│   ├── Contact.cpp
│   ├── Contact.hpp
│   ├── PhoneBook.cpp
│   ├── PhoneBook.hpp
│   └── main.cpp
└── ex02/
    ├── Makefile
    ├── Account.cpp
    ├── Account.hpp
    └── tests.cpp
```

The exact filenames may vary slightly as long as they follow the subject requirements.

## Instructions

### Requirements

You need:

- A C++ compiler such as `c++` or `g++`
- GNU Make
- A Unix-like environment such as Linux or macOS

All exercises must compile with:

```bash
-Wall -Wextra -Werror -std=c++98
```

### Compilation

Compile each exercise from its own directory.

#### Exercise 00

```bash
cd ex00
make
```

#### Exercise 01

```bash
cd ex01
make
```

#### Exercise 02

```bash
cd ex02
make
```

### Execution

The executable name depends on the `NAME` variable defined in each Makefile.

Examples:

```bash
./megaphone "hello world"
```

```bash
./phonebook
```

```bash
./account
```

### Makefile Rules

Each Makefile supports the standard rules:

```bash
make
make clean
make fclean
make re
```

- `make` compiles the project.
- `make clean` removes object files.
- `make fclean` removes object files and the executable.
- `make re` performs a full recompilation.

## Usage Examples

### Megaphone

```bash
./megaphone "shhhhh... I think the students are asleep..."
```

Output:

```text
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
```

Running it without arguments:

```bash
./megaphone
```

Output:

```text
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

### PhoneBook

Start the program:

```bash
./phonebook
```

Available commands:

```text
ADD
SEARCH
EXIT
```

During `SEARCH`, contacts are displayed in four right-aligned columns:

```text
     index|first name| last name|  nickname
```

Each column is ten characters wide. Text longer than ten characters is shortened, and its final visible character is replaced with a dot.

## Technical Choices

- The project follows the C++98 standard.
- Dynamic allocation is not used in the phonebook.
- Contact attributes are private to preserve encapsulation.
- Public member functions provide controlled access to class behavior.
- The phonebook uses a fixed-size array of eight `Contact` objects.
- Static attributes in `Account` store information shared by all account instances.
- Standard C++ streams are used instead of C functions such as `printf`.
- Header guards prevent multiple inclusion of header files.

## Resources

The following references were used to understand the concepts required by the project:

- [C++ reference documentation](https://en.cppreference.com/w/)
- [CPlusPlus — Standard C++ Library Reference](https://cplusplus.com/reference/)
- [CPlusPlus — std::string](https://cplusplus.com/reference/string/string/)
- [CPlusPlus — Input/output manipulators](https://cplusplus.com/reference/iomanip/)
- [GeeksforGeeks — C++ Programming Language](https://www.geeksforgeeks.org/c-plus-plus/)
- [GeeksforGeeks — Classes and Objects in C++](https://www.geeksforgeeks.org/c-classes-and-objects/)
- [GeeksforGeeks — Static Members of a C++ Class](https://www.geeksforgeeks.org/static-data-members-functions-cpp/)
- The official **42 C++ Module 00 subject**
- Peer discussions and the 42 intranet learning material

### Use of AI

AI was used as a learning and review tool for:

- Clarifying C++ concepts such as classes, encapsulation, initialization lists, static members, constant member functions, and stream formatting.
- Explaining compiler and linker errors encountered during development.
- Reviewing the logic of selected functions and identifying possible edge cases.
- Improving the structure and wording of this README.

The project code was written, tested, and verified by the author. AI-generated suggestions were reviewed and adapted rather than copied without understanding.
README.md


*This project has been created as part of the 42 curriculum by mfassad.*

# C++ Module 00

## Description

C++ Module 00 is the first project in the 42 C++ curriculum. Its goal is to introduce the fundamental differences between C and C++ while building a foundation in object-oriented programming.

The module is written according to the **C++98 standard** and introduces concepts such as:

- Namespaces
- Classes and objects
- Public and private members
- Member functions
- Constructors and destructors
- Initialization lists
- Static members
- Constant member functions
- Standard input and output streams
- Basic string formatting

The project contains three exercises of increasing difficulty.

## Exercises

### Exercise 00 — Megaphone

A command-line program that converts all arguments passed to it into uppercase text.

When no arguments are provided, it prints:

```text
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

This exercise introduces:

- Command-line arguments
- Standard output
- Character conversion
- Basic C++ program structure

### Exercise 01 — My Awesome PhoneBook

A simple command-line phonebook that stores up to eight contacts.

The program supports the following commands:

- `ADD` — adds a new contact.
- `SEARCH` — displays saved contacts and allows the user to select one.
- `EXIT` — closes the program.

Each contact contains:

- First name
- Last name
- Nickname
- Phone number
- Darkest secret

When more than eight contacts are added, the oldest contact is replaced.

This exercise introduces:

- Classes and objects
- Encapsulation
- Arrays of objects
- Getters and setters
- Input validation
- Formatted output with `<iomanip>`
- Circular replacement of stored contacts

### Exercise 02 — The Job of Your Dreams

This exercise recreates the missing implementation of an `Account` class by studying the provided header file, test file, and expected log output.

The program manages multiple bank accounts and records:

- Account creation and destruction
- Deposits
- Withdrawals
- Individual account balances
- Total number of accounts
- Total amount of money
- Total deposits and withdrawals
- Timestamped account activity

This exercise introduces:

- Static class attributes
- Static member functions
- Initialization lists
- Constructors and destructors
- Constant member functions
- Timestamp formatting
- Reconstructing an implementation from an interface and expected behavior

## Project Structure

```text
cpp_module_00/
├── README.md
├── ex00/
│   ├── Makefile
│   └── megaphone.cpp
├── ex01/
│   ├── Makefile
│   ├── Contact.cpp
│   ├── Contact.hpp
│   ├── PhoneBook.cpp
│   ├── PhoneBook.hpp
│   └── main.cpp
└── ex02/
    ├── Makefile
    ├── Account.cpp
    ├── Account.hpp
    └── tests.cpp
```

The exact filenames may vary slightly as long as they follow the subject requirements.

## Instructions

### Requirements

You need:

- A C++ compiler such as `c++` or `g++`
- GNU Make
- A Unix-like environment such as Linux or macOS

All exercises must compile with:

```bash
-Wall -Wextra -Werror -std=c++98
```

### Compilation

Compile each exercise from its own directory.

#### Exercise 00

```bash
cd ex00
make
```

#### Exercise 01

```bash
cd ex01
make
```

#### Exercise 02

```bash
cd ex02
make
```

### Execution

The executable name depends on the `NAME` variable defined in each Makefile.

Examples:

```bash
./megaphone "hello world"
```

```bash
./phonebook
```

```bash
./account
```

### Makefile Rules

Each Makefile supports the standard rules:

```bash
make
make clean
make fclean
make re
```

- `make` compiles the project.
- `make clean` removes object files.
- `make fclean` removes object files and the executable.
- `make re` performs a full recompilation.

## Usage Examples

### Megaphone

```bash
./megaphone "shhhhh... I think the students are asleep..."
```

Output:

```text
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
```

Running it without arguments:

```bash
./megaphone
```

Output:

```text
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

### PhoneBook

Start the program:

```bash
./phonebook
```

Available commands:

```text
ADD
SEARCH
EXIT
```

During `SEARCH`, contacts are displayed in four right-aligned columns:

```text
     index|first name| last name|  nickname
```

Each column is ten characters wide. Text longer than ten characters is shortened, and its final visible character is replaced with a dot.

## Technical Choices

- The project follows the C++98 standard.
- Dynamic allocation is not used in the phonebook.
- Contact attributes are private to preserve encapsulation.
- Public member functions provide controlled access to class behavior.
- The phonebook uses a fixed-size array of eight `Contact` objects.
- Static attributes in `Account` store information shared by all account instances.
- Standard C++ streams are used instead of C functions such as `printf`.
- Header guards prevent multiple inclusion of header files.

## Resources

The following references were used to understand the concepts required by the project:

- https://www.geeksforgeeks.org/cpp/c-plus-plus/

### Use of AI

AI was used as a learning and review tool for:

- Clarifying C++ concepts such as classes, encapsulation, initialization lists, static members, constant member functions, and stream formatting.
- Explaining compiler and linker errors encountered during development.
- Reviewing the logic of selected functions and identifying possible edge cases.

The project code was written, tested, and verified by the author. AI-generated suggestions were reviewed and adapted rather than copied without understanding.