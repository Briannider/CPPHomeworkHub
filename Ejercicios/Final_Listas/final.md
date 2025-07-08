# 🧠 Final Practice Exam – Algorithms and Data Structures (C++ / Pointer-style)

Engineering in Information Systems – C++ Manual Memory Style

---

## 📌 Instructions
Implement the following exercises using C++ and **manual memory management** (`new`, `delete`). Avoid using STL containers unless explicitly allowed. You may separate your code into `.cpp` and `.hpp` files following best practices.

---

## 🧪 Exercise 1: Stack (LIFO)
Implement an integer stack using dynamic memory and pointers.

### Requirements:
- `void push(int)`
- `void pop()`
- `int top()`
- `bool isEmpty()`

### Tasks:
1. Implement the stack.
2. Write a function to reverse the contents of a stack using an auxiliary stack.
3. Demonstrate usage with at least 5 values.

---

## 🧪 Exercise 2: Queue (FIFO)
Implement an integer queue using a linked list and pointers.

### Requirements:
- `void enqueue(int)`
- `void dequeue()`
- `int front()`
- `bool isEmpty()`

### Tasks:
1. Implement the queue.
2. Write a function to transfer all elements from a queue to a stack while preserving the original order.
3. Explain the difference between memory management in stacks and queues.

---

## 🧪 Exercise 3: Singly Linked List
Implement a singly linked list with the following operations:

### Requirements:
- `void insertAtBeginning(int)`
- `void insertAtEnd(int)`
- `void remove(int)`
- `void printList()`

### Tasks:
1. Implement the structure and functions.
2. Add a function that returns `true` if the list is sorted in ascending order.
3. Explain the consequences of forgetting to `delete` memory in the `remove()` function.

---

## 🧪 Exercise 4: Doubly Linked List
Implement a doubly linked list with the following operations:

### Requirements:
- `void insertSorted(int)`
- `void remove(int)`
- `void printFromStart()`
- `void printFromEnd()`

### Tasks:
1. Implement the doubly linked list.
2. Modify the insertion function to **reject duplicate values**.
3. Draw a diagram showing the memory structure after inserting: `3, 1, 7, 5` (in sorted order).

---

## 🧪 Exercise 5: Call Stack Simulation
Simulate the behavior of a call stack using a stack of custom `Frame` structs.

### Struct Example:
```cpp
struct Frame {
    char functionName[30];
    int lineNumber;
};
