# Contents
- Array

# Array
## Memory Allocation
### Static Allocation
- When an array is declared with a fixed size, it is allocated on the stack.
- Memory is automatically managed and released when the scope of the array ends.
- Stack size is limited, so large arrays may lead to a stack overflow.
```cpp
int arr[10];  // Array allocated on the stack
```
### Dynamic Allocation
- When the size of the array is determined at runtime, it is allocated on the heap using dynamic memory allocation (`new` keyword).
- Heap memory must be manually deallocated using the `delete[]` keyword; otherwise, it may lead to memory leaks.
```cpp
int* arr = new int[10];  // Array allocated on the heap
delete[] arr;            // Deallocate memory
```