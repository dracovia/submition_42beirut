*This project has been created as part of the 42 curriculum by mfassad.*

# C++ Module 03 — Inheritance

## Description

C++ Module 03 is an introduction to inheritance and class hierarchies in C++.

The project is built around a robot class named `ClapTrap`. Each exercise extends the previous one by introducing derived classes, specialized behavior, multiple inheritance, and virtual inheritance.

The main goals of this project are to understand:

- Base and derived classes
- Public inheritance
- Constructor and destructor chaining
- Function overriding
- Reusing inherited member functions
- Multiple inheritance
- The diamond inheritance problem
- Virtual inheritance
- Orthodox Canonical Form
- Encapsulation using getters and setters

The project is written in C++98 and compiled using:

```bash
-Wall -Wextra -Werror -std=c++98
```

## Exercises

### Exercise 00 — ClapTrap

Implements the base `ClapTrap` class.

Each `ClapTrap` has:

- A name
- 10 hit points
- 10 energy points
- 0 attack damage

The class provides the following actions:

```cpp
void attack(const std::string& target);
void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);
```

Attacking and repairing each consume one energy point. A `ClapTrap` cannot attack or repair itself when it has no hit points or no energy points.

### Exercise 01 — ScavTrap

Introduces `ScavTrap`, which publicly inherits from `ClapTrap`.

A `ScavTrap` starts with:

- 100 hit points
- 50 energy points
- 20 attack damage

It provides its own version of `attack()` and introduces:

```cpp
void guardGate();
```

This exercise demonstrates constructor and destructor chaining between a base class and a derived class.

### Exercise 02 — FragTrap

Introduces `FragTrap`, another class derived from `ClapTrap`.

A `FragTrap` starts with:

- 100 hit points
- 100 energy points
- 30 attack damage

It introduces:

```cpp
void highFivesGuys();
```

`FragTrap` uses the inherited `ClapTrap::attack()` implementation.

### Exercise 03 — DiamondTrap

Introduces `DiamondTrap`, which inherits from both `ScavTrap` and `FragTrap`.

The inheritance structure creates a diamond:

```text
             ClapTrap
             /      \
        ScavTrap   FragTrap
             \      /
            DiamondTrap
```

Virtual inheritance is used so that a `DiamondTrap` contains only one shared `ClapTrap` base object.

A `DiamondTrap` uses:

- Hit points from `FragTrap`: 100
- Energy points from `ScavTrap`: 50
- Attack damage from `FragTrap`: 30
- The `attack()` implementation from `ScavTrap`

It stores two names:

- Its own `DiamondTrap` name
- A `ClapTrap` name ending with `_clap_name`

The function:

```cpp
void whoAmI();
```

prints both names.

## Project Structure

```text
.
├── README.md
├── ex00
│   ├── Makefile
│   ├── main.cpp
│   ├── ClapTrap.hpp
│   └── ClapTrap.cpp
├── ex01
│   ├── Makefile
│   ├── main.cpp
│   ├── ClapTrap.hpp
│   ├── ClapTrap.cpp
│   ├── ScavTrap.hpp
│   └── ScavTrap.cpp
├── ex02
│   ├── Makefile
│   ├── main.cpp
│   ├── ClapTrap.hpp
│   ├── ClapTrap.cpp
│   ├── ScavTrap.hpp
│   ├── ScavTrap.cpp
│   ├── FragTrap.hpp
│   └── FragTrap.cpp
└── ex03
    ├── Makefile
    ├── main.cpp
    ├── ClapTrap.hpp
    ├── ClapTrap.cpp
    ├── ScavTrap.hpp
    ├── ScavTrap.cpp
    ├── FragTrap.hpp
    ├── FragTrap.cpp
    ├── DiamondTrap.hpp
    └── DiamondTrap.cpp
```

## Instructions

### Requirements

You need:

- A C++ compiler
- GNU Make
- A Unix-like environment such as Linux or macOS

The project must compile using the C++98 standard.

### Compilation

Enter the directory of the exercise you want to compile.

Example:

```bash
cd ex00
make
```

The available Makefile rules are:

```bash
make
make all
make clean
make fclean
make re
```

- `make` or `make all` compiles the program.
- `make clean` removes object files.
- `make fclean` removes object files and the executable.
- `make re` recompiles the entire exercise.

### Execution

#### Exercise 00

```bash
cd ex00
make
./claptrap
```

#### Exercise 01

```bash
cd ex01
make
./scavtrap
```

#### Exercise 02

```bash
cd ex02
make
./fragtrap
```

#### Exercise 03

```bash
cd ex03
make
./diamondtrap
```

## Usage Example

```cpp
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamond("Shiny");

    diamond.whoAmI();
    diamond.attack("enemy");
    diamond.guardGate();
    diamond.highFivesGuys();

    return 0;
}
```

## Technical Choices

### Private Attributes

The attributes of `ClapTrap` remain private to preserve encapsulation.

Derived classes access and modify these values using getters and setters.

```cpp
setHitPoints(100);
setEnergyPoints(50);
setAttackDamage(20);
```

### Virtual Inheritance

Both `ScavTrap` and `FragTrap` virtually inherit from `ClapTrap`:

```cpp
class ScavTrap : virtual public ClapTrap
```

```cpp
class FragTrap : virtual public ClapTrap
```

This prevents `DiamondTrap` from containing two separate `ClapTrap` objects and avoids ambiguity when accessing inherited members.

### Constructor and Destructor Chaining

Base classes are constructed before derived classes.

For a `DiamondTrap`, the construction order is:

```text
ClapTrap
ScavTrap
FragTrap
DiamondTrap
```

Destruction occurs in reverse:

```text
DiamondTrap
FragTrap
ScavTrap
ClapTrap
```

### Orthodox Canonical Form

Each class implements:

- A default constructor
- A copy constructor
- A copy assignment operator
- A destructor

## Resources

### References

- geeks for geeks 
### Use of AI

AI was used as a learning and support tool during this project.

It was used to:

- Clarify inheritance and constructor chaining
- Explain normal and virtual inheritance
- Explain the diamond inheritance problem
- Suggest test cases
- Review program output
- Help identify compilation and linker errors
- Explain copy constructors and assignment operators
