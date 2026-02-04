# Data Structures Toolkit (C++)

A command-line application that implements core data structures
using C++ and dynamic memory management. The program provides an
interactive menu system for experimenting with stacks, queues,
and singly linked lists.

## Features
- Stack implementation (LIFO) using a singly linked list
- Queue implementation (FIFO) using a singly linked list with front and rear pointers
- Singly linked list with insertion, deletion, and traversal
- Interactive CLI menus for each data structure
- Robust input validation to prevent crashes

## Technologies
- C++
- Object-Oriented Programming
- Dynamic Memory Management
- Linked Lists
- Command-Line Interfaces

## Time Complexity (Big-O)

**Stack (Linked List)**
- Push: O(1)
- Pop: O(1)
- Peek: O(1)

**Queue (Linked List with Front & Rear Pointers)**
- Enqueue: O(1)
- Dequeue: O(1)
- Front: O(1)

**Singly Linked List**
- Insert at beginning: O(1)
- Insert at end: O(n)
- Delete by value: O(n)
- Display / traversal: O(n)

## Prerequisites
Requires a C++17-compatible compiler (e.g., g++).

## How to Build and Run
```bash
g++ src/*.cpp -Iinclude -o toolkit
./toolkit
```

## Purpose
This project was built to reinforce understanding of core data
structures, pointer manipulation, and performance tradeoffs in C++.
