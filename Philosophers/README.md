*This project has been created as part of the 42 curriculum by mfassad.*

# philo — Dining Philosophers

Description

This project implements the "Dining Philosophers" problem for the 42 curriculum. The goal is to create a concurrent program that simulates philosophers alternately eating, thinking, and sleeping while sharing forks (mutexes). The program must avoid data races and respect timing constraints; it prints philosopher actions with timestamps.

Instructions

Compilation
- Run `make` in the `philo` directory to build the executable named `philo`.

Usage
- `./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]`
- Examples: `./philo 5 800 200 200` or `./philo 5 800 200 200 7`

Output format
- Each state change is printed as a single line:
  `<timestamp_in_ms> <philosopher_id> <action>`
- Actions used by the program: `has taken a fork`, `is eating`, `is sleeping`, `is thinking`, `died`

Resources

Classic references
- POSIX Threads Programming (pthreads) tutorials
- Introduction to Parallel Computing
- The project PDF in `philo/42-philosophers-tester/philo.pdf`

AI usage
- I used AI (GitHub Copilot / ChatGPT) to review concurrency logic and suggest minimal fixes for race conditions in printing and monitor synchronization. AI suggestions were used to propose edits and create test/readme files; all final code edits were applied manually and verified.

License
- None
