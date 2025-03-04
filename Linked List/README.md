# Linked List

## Memory Allocation

In C programmaing, `malloc` function is used to allocate memory.

```c
Node* newNode = (struct Node*)malloc(sizeof(struct Node));
```

In C++ programming, `new` keyword is used to allocate memory.

```cpp
Node* newNode = new Node();
```

## Insertion
### Begin
- create new node
- the next pointer of new node should be the current head
- return new node as current head
### End
- create new node
- traverse at the end of the list
- the next pointer of last node should be new node
### At Index
- create new node
- extract insertion node(**traversing required only here**)
- the next pointer of new node should be the next pointer of current node
- the next pointer of current node should be new node