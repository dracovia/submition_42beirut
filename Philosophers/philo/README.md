*This project has been created as part of the 42 curriculum by mfassad.*

# philo — Dining Philosophers

## Description
The **Philosophers** project is a classical concurrency problem designed to introduce the fundamentals of **multithreading**, **mutex synchronization**, and **shared resource management** in C.

The program simulates philosophers sitting at a round table who alternate between **thinking**, **eating**, and **sleeping**. In order to eat, a philosopher must take **two forks**, one on the left and one on the right. Forks are shared resources and must be protected to avoid race conditions.

The simulation stops when a philosopher dies from starvation or when all philosophers have eaten a required number of times if the optional argument is provided.

## Instructions

### Build
- Run `make` in the `philo` directory. This produces the executable named `philo`.

### Usage
- `./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]`

#### Example
- `./philo 5 800 200 200`
- `./philo 5 800 200 200 7`

## Output format
- Each state change is printed as a single line:
  `<timestamp_in_ms> <philosopher_id> <action>`
- Actions used by the program: `has taken a fork`, `is eating`, `is sleeping`, `is thinking`, `died`
- The program prints the first `died` line and then stops printing any further non-death messages.

## Behavior and guarantees
- Timestamps are relative to the program start time (ms precision).
- Forks are protected by mutexes to avoid concurrent access.
- Program stops when a philosopher dies or when all philosophers have eaten the required number of times (if provided).
- Special case: when `number_of_philosophers == 1` the program takes the single fork and waits until death.

## Troubleshooting
If you observe messages after the death line, the likely cause is a race between the monitor thread setting the stop flag and other threads printing. Ensure the death print is serialized so no other messages appear after `died`.

## Resources
- 42 Philosophers subject PDF
- university 
- Dining Philosophers Problem – GeeksForGeeks  
  https://www.geeksforgeeks.org/dining-philosophers-problem/

### AI Usage
I asked chatgpt to give the file structure that this project should have and to fix some errors i couldnt find.