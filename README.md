# Philosophers 🍝
## Description

Philosophers is a C project based on the classic Dining Philosophers Problem.

Several philosophers sit around a table and share forks. Each philosopher needs two forks to eat, but each fork can only be used by one philosopher at a time.

The goal is to make all philosophers eat, sleep and think without causing deadlocks or race conditions.

Each philosopher runs in its own thread, and mutexes are used to safely share the forks and other resources.

## Solutions

The project implements three different ways to avoid deadlocks:

Fork Ordering: philosophers always pick up the forks in a fixed order.

Asymmetric Solution: even and odd philosophers pick up their forks in a different order.

Waiter Thread: a dedicated thread controls when philosophers can access the forks.

## Usage

Compile the project with:

make


Run it with:

./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]


Example:

./philo 5 800 200 200


Where:

5 → number of philosophers

800 → time before a philosopher dies without eating

200 → time spent eating

200 → time spent sleeping

The last argument is optional and defines how many times each philosopher must eat.

## Concepts

This project focuses on:

Threads and pthread

Mutexes

Synchronization

Race conditions

Deadlocks

Concurrent programming

## Author

bvarea-k

42 Student
