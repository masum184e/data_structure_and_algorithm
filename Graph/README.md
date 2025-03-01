# Contents

- [Introduction](#introduction)
  - [Representation](#representation)
- [Traversing](#traversing)
  - [DFS](#dfs)
  - [BFS](#bfs)
  - [When BFS vs DFS?](#-when-to-use-bfs-vs-dfs)

# Introduction

Graph is a non-linear data structures made up of a specific number of nodes and edges that connect them.

## Representation

**1. Adjacency Matrix:**

- Rows and columns represent vertices.
- `1` indicates an edge; `0` means no edge.
- Stores all possible connections → **Good for dense graphs**

```js
  A B C D E
A 0 1 0 1 0
B 1 0 1 0 1
C 0 1 0 0 0
D 1 0 0 0 1
E 0 1 0 1 0
```

**2. Adjacency List**

- Each index contains it's neighbors information
- Stores only connected neighbors → **Space-efficient for sparse graphs**

```js
A → [B, D]
B → [A, C, E]
C → [B]
D → [A, E]
E → [B, D]
```

**3. Edges**

# Traversing

## DFS

- **Recursive/Iterative:** Required 3 parameter(adj list, visited nodes, current node)
- **Itertive:** In **stack** which element insert first, pop out at last, which **reverse** the order. So iterate the list from last and insert into stack, whish will pop out at last as well, this way the order of traversing maintain properly.

**Characterstics:**

- It is useful for tasks like **cycle detection**, **topological sorting**, and **maze solving**.
- Find path without shortest path requirement

## BFS

- **Iterative:** Just replace stack with queue in dfs, rest is same.

**Characterstics:**

- Explores neighbors before children(layer by layer)
- Finds **shortest path** in an **unweighted** graph

## 🆚 When to Use BFS vs DFS?

| **Aspect**                | **BFS**                     | **DFS**                    |
| ------------------------- | --------------------------- | -------------------------- |
| **Shortest Path?**        | ✅ Yes (unweighted graphs)  | ❌ No                      |
| **Memory Usage**          | 🟠 High (stores full layer) | 🟢 Lower (stores one path) |
| **Graph Type?**           | 🟢 Wide, shallow graphs     | 🟢 Deep, narrow graphs     |
| **Cycle Detection?**      | 🟢 Yes                      | 🟢 Yes                     |
| **Connected Components?** | 🟢 Yes                      | 🟢 Yes                     |

## Complexity
- V: Number of vertices (nodes)
- E: Number of edges (connections)

**Time Complexity:** O(V + E)

**Space Complexity:** O(V)
