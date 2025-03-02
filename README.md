# Contents

- [Asymptotic Notations](#asymptotic-notations)
  - [Big O](#1-big-o-notation-o--upper-bound-worst-case)
  - [Omega](#2-omega-notation-ω--lower-bound-best-case)
  - [Theta](#3-theta-notation-θ--tight-bound-average-case)
- [Memory Management](#memory-management)
  - [Types](#types)
  - [Stack vs Heap](#comparison-stack-vs-heap)
  - [Allocation](#allocation)
- [Data Structure](#data-structure)

# Asymptotic Notations

Asymptotic notation is a mathematical tool used in computer science to describe the efficiency of algorithms in terms of time and space complexity. It helps us analyze how the runtime or space requirements of an algorithm grow as the input size increases.

Asymptotic notation ignores constant factors and lower-order terms, focusing only on the dominant factor that affects performance for large inputs.

## **Types of Asymptotic Notations**

### **1. Big-O Notation (O) – Upper Bound (Worst Case)**

- Represents the worst-case complexity.
- Describes the maximum amount of time an algorithm will take for any input.
- Example: If an algorithm runs in at most $ c \cdot f(n) $ time for large $ n $, we write:
  $
  T(n) = O(f(n))
  $

### **2. Omega Notation (Ω) – Lower Bound (Best Case)**

- Represents the best-case complexity.
- Guarantees that the algorithm takes at least a certain amount of time.
- Example: If an algorithm runs in at least $ c \cdot g(n) $ time for large $ n $, we write:
  $
  T(n) = \Omega(g(n))
  $

### **3. Theta Notation (Θ) – Tight Bound (Average Case)**

- Represents both upper and lower bounds.
- Used when an algorithm always runs in a specific range of time complexity.
- Example: If an algorithm runs in both $ O(f(n)) $ and $ \Omega(f(n)) $, we write:
  $
  T(n) = \Theta(f(n))
  $

<img src="./images/complexity.png" />

- Polynomial - 1, log n, n log n
- Exponential - 2<sup>n</sup>, 3<sup>n</sup>, n<sup>n</sup>

# Memory Management

A program stores in hard drive, executes in CPU.

Think of it like a book:

- **Hard Drive** = A bookshelf where the book (program) is stored when not in use.
- **RAM** = A desk where you place the book while reading it (temporary workspace).
- **CPU** = Your brain, which reads and processes the information from the book.

## Types

**Code Segment**

- Store compiled code.
- It uses stack and heap memory.

**Stack Memory**

- Store global, static variable, function call
- Automatically managed(created, removed)
- Size decided at compile time
- Store data organized way

**Heap Memory**

- Memory allocated during program execution
- Automatically created but manually removed
- when the programs terminates, OS automatically reclaims all allocated heap
- Size decided at run time
- Store data unorganized way
- Treat like resources
- Can't directly use, you have to use pointer to use it

## Comparison: Stack vs Heap

| Feature          | Stack Memory                          | Heap Memory                                            |
| ---------------- | ------------------------------------- | ------------------------------------------------------ |
| **Creation**     | Automatically created                 | Automatically available but requires manual allocation |
| **Deallocation** | Automatic (when function exits)       | Manual (using free() or delete)                        |
| **Speed**        | Faster                                | Slower                                                 |
| **Size**         | Limited                               | Large (depends on system)                              |
| **Lifetime**     | Exists only during function execution | Persists until manually freed                          |
| **Usage**        | Local variables, function calls       | Dynamically allocated memory                           |

- Array created in both heap(`int *p=new int(5)`) and stack(`int arr[]={1,2,3,4,5}`).
- Linkedlist created only in heap.

## Allocation

### Static Memory Allocation

- Memory allocated at **compile time** and doesn't change during program execution, deallocated automatically when program terminates.
- It is stored in the **stack**/data segment.
- Global variable store in data segement and local variable store in stack.

### Dynamic Memory Allocation

- Memory allocated at **runtime** using **pointers**.
- It is store in the **heap** memory.
- Explicit deallocation requires.

**Example:**

```cpp
int *p;  // store at stack as it is local variable
p=new int(5);  // store at heap
```

# Data Structure

Logical data structure uses physical data structure to implement itself.

## Physical Data Structure

- How data is actually stored in memory(RAM, disk).
- Deals with the real-world representation.
- Involves memory management, allocation, data storage.
- Impact performance and access speed.
- Examples: **Array, Linked List**.

## Logical Data Structure

- How data is conceptually organized and how operation performed on it.
- It define relationships, hierarchy.
- Examples: **Stack, Queue**.
