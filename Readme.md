# Sorting Algorithms

## Comparison Based

### 1. Bubble Sort
Repeatedly compares adjacent elements and swaps them if they are in the wrong order. After each pass, the largest (or smallest) element "bubbles" up to the end of the array. As an optimization, if no swaps occur during a pass, the array is already sorted and the algorithm can terminate early.

| Case | Time Complexity | Description |
|------|----------------|-------------|
| Best | $O(N)$ | Already sorted (terminates in 1 pass with no swaps) |
| Average | $O(N^2)$ | |
| Worst | $O(N^2)$ | Reverse sorted |

- Space: $O(1)$ (in-place)
- **Stable** sort

---

### 2. Insertion Sort
Divides the array into a sorted and an unsorted portion. Takes the first element from the unsorted portion and inserts it into its correct position within the sorted portion. This is the same approach as sorting a hand of playing cards.

| Case | Time Complexity | Description |
|------|----------------|-------------|
| Best | $O(N)$ | Already sorted (only comparisons, no shifts) |
| Average | $O(N^2)$ | |
| Worst | $O(N^2)$ | Reverse sorted |

- Space: $O(1)$ (in-place)
- **Stable** sort
- Very efficient when data is nearly sorted

---

### 3. Selection Sort
Finds the minimum (or maximum) element in the unsorted portion and swaps it with the first unsorted element. This repeats until the entire array is sorted. Always performs exactly $\frac{N(N-1)}{2}$ comparisons regardless of input.

| Case | Time Complexity | Description |
|------|----------------|-------------|
| Best | $O(N^2)$ | Always the same regardless of input |
| Average | $O(N^2)$ | |
| Worst | $O(N^2)$ | Always the same regardless of input |

- Space: $O(1)$ (in-place)
- **Unstable** sort (relative order of equal elements may change)

---

### 4. Heap Sort
Builds a Max Heap (or Min Heap) from the array, then repeatedly swaps the root (max/min value) with the last element and reduces the heap size by 1, re-heapifying each time. Building the heap takes $O(N)$, and extracting all elements with heapify takes $O(N \log N)$.

| Case | Time Complexity | Description |
|------|----------------|-------------|
| Best | $O(N \log N)$ | |
| Average | $O(N \log N)$ | |
| Worst | $O(N \log N)$ | Always the same regardless of input |

- Space: $O(1)$ (in-place)
- **Unstable** sort
- Guarantees $O(N \log N)$ even in the worst case

---

### 5. Merge Sort
Recursively divides the array in half (Divide), then merges the two sorted halves back together (Merge). Since it always splits evenly in half, the time complexity is $O(N \log N)$ regardless of input. However, it requires an additional array during the merge step.

| Case | Time Complexity | Description |
|------|----------------|-------------|
| Best | $O(N \log N)$ | |
| Average | $O(N \log N)$ | |
| Worst | $O(N \log N)$ | Always the same regardless of input |

- Space: $O(N)$ (additional array needed for merging)
- **Stable** sort
- Consistent performance compared to Quick Sort, but higher memory usage

---

### 6. Quick Sort
Selects a pivot, partitions the array so that elements smaller than the pivot go left and larger ones go right, then recursively sorts each partition. Performance depends heavily on pivot selection.

| Case | Time Complexity | Description |
|------|----------------|-------------|
| Best | $O(N \log N)$ | Pivot is always the median |
| Average | $O(N \log N)$ | |
| Worst | $O(N^2)$ | Already sorted array with first/last element as pivot |

- Space: $O(\log N)$ (recursion call stack)
- **Unstable** sort
- In-place sorting, no additional array needed — more memory-efficient than Merge Sort
- On average, the fastest comparison-based sort in practice

---

## Index Based (Non-Comparison)
> Not comparison-based, so they can surpass the $O(N \log N)$ lower bound.
> Elements must be **non-negative integers**, and memory usage depends on the maximum value $M$.

### 1. Count Sort
Records the frequency of each value in a counting array, then reconstructs the original array by iterating through the counting array. Requires an array of size $M+1$ when values range from $0$ to $M$.

| Case | Time Complexity | Description |
|------|----------------|-------------|
| Best | $O(N + M)$ | |
| Average | $O(N + M)$ | |
| Worst | $O(N + M)$ | $M$: maximum value |

- Space: $O(M)$ (counting array)
- **Stable** sort (depending on implementation)
- Wasteful in time/memory when $M$ is much larger than $N$

---

### 2. Bucket/Bin Sort
Similar to Count Sort, but uses a Linked List (bucket) at each index. Elements with the same value are stored in the same bucket as a linked list. Essentially the same principle as Count Sort.

| Case | Time Complexity | Description |
|------|----------------|-------------|
| Best | $O(N + M)$ | |
| Average | $O(N + M)$ | |
| Worst | $O(N + M)$ | $M$: maximum value (number of buckets) |

- Space: $O(N + M)$ (buckets + nodes)
- **Stable** sort
- A general Bucket Sort variant evenly divides the range and sorts each bucket individually

---

# Graph Theory (Network Flow)

## Types of Graphs
1. Directed Graph(Digraph) : (u, v) != (v, u)
2. Undirected Graph : (u, v) == (v, u)

## Other Types of Graphs (Can be Directed or Undirected)
1. Weighted Graph : Each edge has a weight (u, v, w) where w is the weight
2. Cyclic Graph : Contains at least one cycle
3. Acyclic Graph : Does not contain any cycle

## Special Graphs
1. Tree : A graph with no cycles (N vertices, N-1 edges)
   1) Rooted Tree : A tree with a designated root node
   2) In-Tree : A rooted tree where all edges point towards the root
   3) Out-Tree : A rooted tree where all edges point away from the root (Normally what we refer to as a tree)
2. Directed Acyclic Graph (DAG) : A directed graph with no cycles (e.g., Trees). It plays an important role in representing structures with dependencies. Several efficient algorithms exist to operate on DAGs, such as topological sorting and finding the longest path.
3. Bipartite Graph : A graph whose vertices can be divided into two disjoint sets such that no two graph vertices within the same set are adjacent, such that every edge connects a vertex in one set to a vertex in the other set.
4. Complete Graph : A graph in which every pair of distinct vertices is connected by a unique edge. (N vertices, N-1 edges for each vertex. => total N(N-1)/2 edges for undirected graph)

## Graph Representations
1. Adjacency Matrix : A 2D array of size VxV where V is the number of vertices in a graph. If there is an edge from vertex i to vertex j, then matrix[i][j] = 1 (or Weight), otherwise matrix[i][j] = 0.
2. Adjacency List : A collection of lists or arrays where each list corresponds to a vertex in the graph and contains the neighboring vertices that are directly connected to it.

## Traversal Algorithms (Time Complexity : O(V + E))
1. Depth-First Search (DFS) : Explores as far as possible along each branch before backtracking. 
2. Breadth-First Search (BFS) : Explores all the neighbors of a vertex before moving on to the next level of neighbors.
> BFS is useful for finding the shortest path on unweighted graphs.

### Tree vs Graph Traversal
**Key Differences:**

1. **Tree Traversal**
   - Each node has a **clearly defined position** (root, left child, right child)
   - BFS/DFS (Preorder/Inorder/Postorder) produce **deterministic output**
   - The structure is fixed and unambiguous

2. **Graph Traversal**
   - Nodes have **no inherent positional meaning**
   - Traversal order depends on **how neighbors are stored** in the adjacency list/matrix
   - The same graph can be drawn in multiple ways without changing its structure

**Example:** These three representations are the **same graph**:
```
    (A)           (A)           (A)    
  /  |  \       /  |  \       /  |  \  
(C)-(B) (D) , (B)-(C) (D) , (D) (B)-(C)
```
> Note: Saying "B is to the left of C" is not true in graph theory!

**Important:** 
- Unlike trees, graphs use a **visited set** to avoid revisiting nodes
- The **order neighbors are stored** significantly impacts the traversal sequence
- Graph traversals do **not guarantee a specific visiting order**
- The key difference is the **strategy**: 
  - **BFS**: Visit neighbors first (level-by-level)
  - **DFS**: Visit along a path to the end first (depth-first)

## Classic Graph Theory Algorithms
1. Topological Sort Algorithm : An ordering of the vertices in a directed acyclic graph (DAG) such that for every directed edge (u, v), vertex u comes before vertex v in the ordering. It is commonly used in scheduling tasks, resolving dependencies, and organizing data with precedence constraints.
   1) Topological orderings are not unique.
   2) A graph containing a cycle cannot have a topological ordering. (Only DAGs can be topologically sorted.)
   3) DAG Shortest/Longest Path Algorithm (DAG + Topological Order + Dynamic Programming, O(E+V)) : In a directed acyclic graph (DAG), the shortest path from a source vertex to all other vertices can be found in linear time using a topological sort followed by edge relaxation. the edge can be negative as well.
   
2. Dijkstra's Algorithm (O((E+V)*log(V))) : An algorithm for finding the shortest paths between nodes in a graph. It works only with non-negative edge weights.
   1) Unlike Topological Sort, it can handle Cycles.
   2) Uses Greedy Algorithm. (Once a node is processed, its shortest distance is confirmed and finalized)

3. Bellman-Ford Algorithm (O(V*E)) : An algorithm that computes shortest paths from a single source vertex to all other vertices in a weighted graph. It can handle graphs with negative edge weights and can also detect negative weight cycles.
   1) Unlike Topological Sort, it can handle Cycles.
   2) Unlike Dijkstra's algorithm, Bellman-Ford can handle graphs with negative edge weights.
   3) But it is slower than Dijkstra's algorithm for graphs with non-negative weights.


## Minimum Spanning Trees(MST) Characteristics
1. A minimum spanning tree (MST) of a connected, undirected graph is a subset of the edges that connects all the vertices together without any cycles and with the minimum possible total edge weight.
2. If all edge weights are distinct, the MST is unique.
3. If there are multiple edges with the same weight, there may be multiple valid MSTs.
4. The number of edges in an MST is always V-1, where V is the number of vertices in the graph.
 
## Minimum Spanning Trees(MST) Algorithms
1. Kruskal's Algorithm (O(E*logE)) : A greedy algorithm that finds a minimum spanning tree for a connected weighted graph by sorting all the edges in non-decreasing order of their weights and adding them one by one to the spanning tree, ensuring that no cycles are formed.
2. Prim's Algorithm (O(E + V*logV)) : A greedy algorithm that finds a minimum spanning tree for a connected weighted graph by starting from an arbitrary vertex and repeatedly adding the smallest edge that connects a vertex in the tree to a vertex outside the tree until all vertices are included.
--> Comparison: Kruskal's algorithm is generally more efficient for sparse graphs, while Prim's algorithm is more efficient for dense graphs.

## Asymptotic Notations (asymptotic class : 1 < logn < n < nlogn < n^2 < n^3 < ... < 2^n < 3^n)
1. **Big O Notation (O)**: Describes an upper bound on the time complexity. It provides a worst-case scenario. (Upper Bound)
2. **Theta Notation (Θ)**: Describes a tight bound on the time complexity. It provides both upper and lower bounds. (Tight Bound)
3. **Omega Notation (Ω)**: Describes a lower bound on the time complexity. It provides a best-case scenario. (Lower Bound)
4. **Little o Notation (o)**: Describes an upper bound that is not tight. It indicates that a function grows strictly slower than another function.
5. **Little omega Notation (ω)**: Describes a lower bound that is not tight. It indicates that a function grows strictly faster than another function.

> - If f(n) = **Θ**(g(n)), then f(n) is both O(g(n)) and Ω(g(n)). `c1*g(n) <= f(n) <= c2*g(n)` for some constants c1, c2 > 0 and sufficiently large n.
> - If f(n) = **O**(g(n)), then f(n) grows at most as fast as g(n). `f(n) <= c*g(n)` for some constant c > 0 and sufficiently large n.
> - If f(n) = **Ω**(g(n)), then f(n) grows at least as fast as g(n). `f(n) >= c*g(n)` for some constant c > 0 and sufficiently large n.
> - If f(n) = **o**(g(n)), then f(n) grows strictly slower than g(n). `f(n) < c*g(n)` for any constant c > 0 and sufficiently large n.
> - If f(n) = **ω**(g(n)), then f(n) grows strictly faster than g(n). `f(n) > c*g(n)` for any constant c > 0 and sufficiently large n.

> - if Θ(g(n)) exists, O(..) and Ω(..) must also exist with the exact same function g(n), but not for o(..) and ω(..).
> - if O(..) and Ω(..) exist with different functions, Θ(..) cannot exist (because it is not tight)
> - tight means that the upper and lower bounds are the same function (g(n)), where g(n) belong to the same asymptotic class (1 < logn < n < nlogn < n^2 < n^3 < ... < 2^n < 3^n)

1. `f(n) = 2n^2 + 3n + 5`
   - Θ(n^2), O(n^2), Ω(n^2)
2. `f(n) = 3nlogn + 5n + 2`
   - Θ(nlogn), O(nlogn), Ω(nlogn)
3. `f(n) = 2n*sqrt(n) + 3n + 5`
   - O(n^2), o(n^2), Ω(n), ω(n) (no Θ exist, because it is not tight)

> Usually we specify O(..) and Ω(..) with the tightest bound, but mathematically there can be multiple valid answers.

1. `f(n) = 2n + 3`
   - Θ(n), [O(n), O(n^2), O(n^3),...], [Ω(n), Ω(logn), Ω(1)], [o(n^2), o(n^3),...], [ω(logn), ω(1)]
   - because, [f(n) = 2n + 3 <= 5n <= 5n^2 <= ...] and [f(n) = 2n + 3 >= n >= logn >= 1]
2. `f(n) = n!`
   - 1x1x1x..1x1 (n times) <= n! <= n x n x n x ... x n (n times)
   - 1 <= f(n) <= n^n
   - ω(1), Ω(1), O(n^n), o(n^n) (no Θ exist, because it is not tight)
3. Linear Search
   - Best Case: Θ(1), O(1), Ω(1)
   - Average Case: Θ(n), O(n), Ω(n)
   - Worst Case: Θ(n), O(n), Ω(n)

## Master Theorem (for solving recurrence Division Function)

```
T(n) = aT(n/b) + f(n),  where f(n) = Θ(n^k * (logn)^p)

- aT(n/b)  ->  compare log_b(a)  vs  k  (from n^k)

if   log_b(a) > k  :  T(n) = Θ(n^log_b(a))
elif log_b(a) == k :  T(n) = Θ(f(n) * logn)
elif log_b(a) < k  :  T(n) = Θ(f(n))
```

| Recurrence | Result |
| --- | --- |
| T(n) = 2T(n/2) + n | O(nlogn) |
| T(n) = T(n/2) + 1 | O(logn) |
| T(n) = T(n/2) + nlogn | O(nlogn) |
| T(n) = 2T(n/2) + 1 | O(n) |
| T(n) = 4T(n/2) + 1 | O(n^2) |
| T(n) = 2T(n/2) + n^2 | O(n^2) |
| T(n) = 2T(n/2) + n | O(nlogn) |
| T(n) = 9T(n/3) + 1 | O(n^2) |
| T(n) = 8T(n/2) + 1 | O(n^3) |
| T(n) = 4T(n/2) + n | O(n^2) |
| T(n) = T(n/2) + n | O(n) |
| T(n) = 4T(n/2) + n^2*logn | O(n^2*logn*logn) |

## Algorithm Strategies
1. **Divide and Conquer (DAC)** : Divide the problem into smaller subproblems, solve each subproblem independently, and then combine the solutions to solve the original problem.
- binary search
- merge sort
- strassen's matrix multiplication
```
Algorithm DAC(A, n)
{
    if(n is small enough)
        return S(a,n) // solve the problem directly
    else
    {
        divide A into subproblems A1, A2, ..., Ak
        for i = 1 to k
            Si = DAC(Ai, size of Ai)
        return combine(S1, S2, ..., Sk)
    }
}
```

2. **Greedy Method** : Make the locally optimal choice at each stage with the hope of finding a global optimum.
- Used for optimization problems (e.g., finding the minimum spanning tree, shortest path)
- there are constraints and objectives (usually minimizing or maximizing) that need to be satisfied
- MST (Kruskal's, Prim's)
  1) Spanning Tree : N vertices, N-1 edges, no cycle
  2) Minimum Spanning Tree : Spanning tree with the minimum total edge weight
  3) Kruskal's Algorithm : Sort edges by weight and add them one by one to the MST, skipping those that would form a cycle.
  4) Prim's Algorithm : Start from an arbitrary vertex and grow the MST by adding the smallest edge that connects a vertex in the MST to a vertex outside the MST.
- Dijkstra's Algorithm : Find the shortest path from a source vertex to all other vertices in a graph with non-negative edge weights.
- Huffman Coding : A lossless data compression algorithm that assigns variable-length codes to characters based on their frequencies. More frequent characters get shorter codes.
```
Algorithm Greedy(A,n)
{
    solution = {}
    for i = 1 to n
    {
        x = select A[i] from A // select the best candidate (greedily) according to a specific objective
        if(x is feasible)
            solution = solution ∪ {x}
    }
    return solution
}
```

3. **Dynamic Programming** : Break the problem into overlapping subproblems, solve each subproblem just once, and store their solutions.
- Used for optimization problems where `only` one optimal solution is needed.
- there are constraints and objectives (usually minimizing or maximizing) that need to be satisfied
- Consider previous decisions and their outcomes to make the current decision
- Try all possible decisions and choose the best one based on the results of subproblems.
  1) Memoization (Top-Down) : Store the results of expensive function calls and return the cached result when the same inputs occur again.
  2) Recursion (Top-Down) : Solve the problem by breaking it into smaller subproblems recursively, solving each subproblem and combining their results.
  3) Tabulation (Bottom-Up) : Fill a table in a systematic way to solve the problem iteratively.
  - Normally start from recursive approach, then add memoization to optimize it, and finally convert it to tabulation for further optimization.
  - Tabulation requires additional mathematical formula to determine the order of filling the table, while memoization does not require it.
- Zero-One Knapsack Problem : Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. (Each item can either be included or excluded)
- Longest Common Subsequence (LCS) : Given two strings A and B, find the length of the longest subsequence that is common to both strings. A subsequence is a sequence that appears in the same relative order but not necessarily contiguous.

 
4. **Backtracking** : Build a solution incrementally, abandoning solutions that fail to satisfy the constraints of the problem.
- Try all possible combinations of decisions and backtrack(go back to previous state) when there is no combination satisfying the constraints.
- There are constraints that need to be satisfied (e.g., no two queens threaten each other in the N-Queens problem)
- Sudoku Solver : Given a partially filled 9x9 grid, fill the empty cells so that each row, column, and 3x3 subgrid contains all digits from 1 to 9.
- Rat in a Maze : Given a maze represented as a 2D grid, find a path from the start point to the end point, moving only in four directions (up, down, left, right) and avoiding obstacles.
- N-Queens Problem : Place N queens on an N×N chessboard so that no two queens threaten each other.
```
Algorithm Backtrack(A, solution)
{
    if(solution is complete)
        return solution
    for each candidate x in A
    {
        if(x is feasible) // satisfies constraints
        {
            solution = solution ∪ {x}
            result = Backtrack(A, solution)
            if(result != null)
                return result
            solution = solution \ {x} // backtrack (undo the choice)
        }
    }
    return null // no solution found
}
```

## Loops vs Recursion
- We can convert any recursive function into an iterative one using loops, and vice versa. 
- Many mathematical problems often can be solved using recursion easily, but it may takes too much stack space.
- If the stack space is a concern, we can convert the recursive function into an iterative one using loops.
- If the problem doesn't take too much stack space, we can use recursion for better readability and maintainability.


### Huffman Coding

**Problem:** Given a set of characters and their frequencies, find an optimal prefix-free binary code that minimizes the total number of bits used to encode the message.
- A **prefix-free code** means no code is a prefix of another code → unambiguous decoding.
- **Greedy choice:** Always merge the two nodes with the **smallest frequencies** first.
- Time Complexity: **O(n*logn)** (due to min-heap operations)

**Algorithm:**
1. Create a **min-heap** (priority queue) with all characters and their frequencies.
2. While the heap has more than one node:
   1) Extract the two nodes with the **minimum frequency** (`left`, `right`).
   2) Create a new internal node with frequency = `left.freq + right.freq`.
   3) Set `left` as the left child and `right` as the right child.
   4) Insert the new node back into the heap.
3. The remaining node is the **root** of the Huffman Tree.
4. Traverse the tree: left edge = `0`, right edge = `1` → each leaf's path = its code.

**Example:** `"aabbbbcccddddddee"` → frequencies: `a:2, b:4, c:3, d:6, e:2`
```
Step 1: Merge a(2) + e(2) = [ae](4)
Step 2: Merge c(3) + b(4) = [cb](7)       (or [ae](4), pick two smallest)
Step 3: Merge [ae](4) + d(6) = [aed](10)  (adjust based on actual min-heap order)
...

Final Huffman Tree (one possible result):

            (17)
           /    \
        (7)      (10)
       /   \    /    \
     c(3) b(4) [ae](4) d(6)
               /   \
             a(2)  e(2)

Codes:
  c = 00
  b = 01
  a = 100
  e = 101
  d = 11
```

**Fixed-Length vs Huffman Coding:**
| Character | Freq | Fixed (3-bit) | Huffman Code | Huffman Bits |
| --- | --- | --- | --- | --- |
| a | 2 | 000 | 100 | 2 × 3 = 6 |
| b | 4 | 001 | 01 | 4 × 2 = 8 |
| c | 3 | 010 | 00 | 3 × 2 = 6 |
| d | 6 | 011 | 11 | 6 × 2 = 12 |
| e | 2 | 100 | 101 | 2 × 3 = 6 |
| **Total** | **17** | | | **38 bits** |

> Fixed-length: 17 × 3 = **51 bits** → Huffman: **38 bits** (25.5% savings)

**Key Properties:**
- Huffman coding produces an **optimal prefix-free code** for a given set of character frequencies.
- Characters with **higher frequency** get **shorter codes**, and characters with **lower frequency** get **longer codes**.
- The Huffman tree is **not unique** — different trees can produce different codes with the **same total bit cost**.
- It is widely used in file compression formats like **ZIP, GZIP, JPEG, MP3**.
   
   
### Longest Common Subsequence (LCS)

**Problem:** Given two strings `A` and `B`, find the length of the longest subsequence common to both.
- A **subsequence** is derived by deleting zero or more characters without changing the relative order.
- Example: `A = "abcdefg"`, `B = "dbcfmg"` → LCS = `"bcfg"` (length **4**)

**Approach 1: Pure Recursion — O(2^n)**
- Compare characters at positions `i` (in A) and `j` (in B):
  - If `A[i] == B[j]`: match found → move both pointers forward → `1 + LCS(i+1, j+1)`
  - If `A[i] != B[j]`: try both options → `max(LCS(i+1, j), LCS(i, j+1))`
- Exponential time due to overlapping subproblems being recomputed.

**Approach 2: Recursion + Memoization (Top-Down) — O(n*m)**
- Same recursive logic, but store results in a table `T[i][j]` to avoid recomputation.
- Can use a `HashMap<string, int>` with key `"i#j"`, or a 2D vector `T[n][m]` initialized to `-1`.

**Approach 3: Tabulation (Bottom-Up) — O(n*m)**
- Build a 2D table `T[n+1][m+1]` iteratively (no recursion, no stack overhead).
- Fill rule:
  - If `A[i-1] == B[j-1]` → `T[i][j] = T[i-1][j-1] + 1`  (diagonal + 1)
  - Else → `T[i][j] = max(T[i-1][j], T[i][j-1])`  (max of top, left)

**Tabulation Table Example:** `A = "abcdefg"`, `B = "dbcfmg"`
```
      ""  d  b  c  f  m  g
  ""   0  0  0  0  0  0  0
   a   0  0  0  0  0  0  0
   b   0  0  1  1  1  1  1
   c   0  0  1  2  2  2  2
   d   0  1  1  2  2  2  2
   e   0  1  1  2  2  2  2
   f   0  1  1  2  3  3  3
   g   0  1  1  2  3  3  4
```
> Result: `T[7][6] = 4` → LCS length is **4**

**Summary:**
| Method | Time | Space | Notes |
| --- | --- | --- | --- |
| Pure Recursion | O(2^n) | O(n) stack | Exponential, impractical for large inputs |
| Recursion + Memoization | O(n*m) | O(n*m) + stack | Top-down, easy to implement from recursion |
| Tabulation | O(n*m) | O(n*m) | Bottom-up, no stack overhead, most efficient |


### Heap (Binary Heap)

**Definition:** A Heap is a **Complete Binary Tree** stored as an array, satisfying the heap property.
- **Complete Binary Tree**: Every level is fully filled except possibly the last, which is filled from left to right. This guarantees the tree height is always $\lfloor \log_2 N \rfloor$.
- **Max Heap**: Every parent node is **greater than or equal to** its children → Root is the **maximum**.
- **Min Heap**: Every parent node is **less than or equal to** its children → Root is the **minimum**.

**Array Representation (0-indexed):**
- Parent of node `i`: $\lfloor (i - 1) / 2 \rfloor$
- Left child of node `i`: $2i + 1$
- Right child of node `i`: $2i + 2$

```
Example Max Heap:        Array: [50, 45, 40, 30, 20, 35, 5, 10]
                         Index:   0   1   2   3   4   5   6   7
         50
       /    \            Parent of index 5 (value 35): (5-1)/2 = 2 (value 40) ✓
     45      40          Left child of index 1 (value 45): 2*1+1 = 3 (value 30) ✓
    / \     / \          Right child of index 1 (value 45): 2*1+2 = 4 (value 20) ✓
   30  20  35   5
  /
 10
```

---

**Insert — O(log N)**

Add the new element at the **end** of the array (to maintain the complete binary tree property), then **bubble up** (swap with parent) until the heap property is restored.

**Example:** Insert `45` into Max Heap `[50, 30, 40, 10, 20, 35, 5]`

```
Step 1: Add 45 at the end              Step 2: Bubble up (45 > 10 → swap)
         50                                      50
       /    \                                  /    \
     30      40                              30      40
    / \     / \                             / \     / \
   10  20  35   5                          45  20  35   5
  /                                       /
 45                                      10

Step 3: Bubble up (45 > 30 → swap)      Step 4: 45 < 50 → STOP
         50                              Result: [50, 45, 40, 30, 20, 35, 5, 10]
       /    \
     45      40
    / \     / \
   30  20  35   5
  /
 10
```

**Time Complexity:** At most $h$ swaps where $h = \lfloor \log_2 N \rfloor$ → **O(log N)**

---

**Delete (Extract Root) — O(log N)**

Replace the **root** with the **last element** in the array (to maintain the complete binary tree property), remove the last element, then **heapify down** (swap with the larger/smaller child) until the heap property is restored.

**Example:** Delete root from Max Heap `[50, 45, 40, 30, 20, 35, 5, 10]`

```
Step 1: Replace root with last (10)    Step 2: Heapify down (10 < max(45,40)=45 → swap)
         10                                      45
       /    \                                  /    \
     45      40                              10      40
    / \     / \                             / \     / \
   30  20  35   5                          30  20  35   5

Step 3: Heapify down (10 < max(30,20)=30 → swap)    Step 4: 10 has no children → STOP
         45                                           Result: [45, 30, 40, 10, 20, 35, 5]
       /    \
     30      40
    / \     / \
   10  20  35   5
```

**Time Complexity:** At most $h$ swaps where $h = \lfloor \log_2 N \rfloor$ → **O(log N)**

---

**Build Heap — O(N)**

**Naive Approach — O(N log N):** Insert elements one by one. Each insertion costs O(log N), so total = O(N log N).

**Optimized Approach (Heapify) — O(N):** Copy all elements into the array first, then call **Heapify** (sift down) starting from the **last non-leaf node** down to the root.

```
Last non-leaf node index = ⌊(N - 2) / 2⌋

for i = ⌊(N-2)/2⌋ down to 0:
    Heapify(i)    // sift down from node i
```

**Example:** Build Max Heap from `[10, 20, 5, 30, 45, 35, 50, 40]`

```
Initial (just an array as a tree):     Last non-leaf = (8-2)/2 = 3 (value 30)
         10
       /    \
     20       5
    /  \    /   \
   30   45  35   50
  /
 40

Heapify(3): 30 → compare children: 40 → swap    Heapify(2): 5 → compare children: max(35,50)=50 → swap
         10                                               10
       /    \                                           /    \
     20       5                                       20      50
    /  \    /   \                                    /  \    /   \
   40   45  35   50                                 40   45  35    5
  /                                                /
 30                                               30

Heapify(1): 20 → compare children: max(40,45)=45 → swap    Heapify(0): 10 → compare children: max(45,50)=50 → swap
         10                                                          50
       /    \                                                      /    \
     45      50                                                  45      10
    /  \    /   \                                               /  \    /   \
   40   20  35    5                                            40   20  35    5
  /                                                           /
 30                                                          30

Continue Heapify(0): 10 → compare children: max(35,5)=35 → swap
         50                          Result: [50, 45, 35, 40, 20, 10, 5, 30]
       /    \
     45      35
    /  \    /   \
   40   20  10    5
  /
 30
```

---

**Mathematical Proof: Build Heap is O(N)**

In a complete binary tree with $N$ nodes, the height is $h = \lfloor \log_2 N \rfloor$.

**Key Observation:** The number of nodes at height $k$ (measured from the bottom, where leaves are at height 0) is at most $\lceil N / 2^{k+1} \rceil$. Heapify at a node of height $k$ performs at most $k$ swaps (sifting down $k$ levels).

$$
T(N) = \sum_{k=0}^{h} \left\lceil \frac{N}{2^{k+1}} \right\rceil \cdot k
$$

Dropping the ceiling for the upper bound:

$$
T(N) \leq \sum_{k=0}^{h} \frac{N}{2^{k+1}} \cdot k = \frac{N}{2} \sum_{k=0}^{h} \frac{k}{2^k}
$$

Now evaluate the infinite series (upper bound since $h$ is finite):

$$
S = \sum_{k=0}^{\infty} \frac{k}{2^k} = \sum_{k=1}^{\infty} k \cdot x^k \bigg|_{x=\frac{1}{2}}
$$

Using the known formula $\displaystyle\sum_{k=1}^{\infty} k \cdot x^k = \frac{x}{(1-x)^2}$ for $|x| < 1$:

$$
S = \frac{\frac{1}{2}}{(1 - \frac{1}{2})^2} = \frac{\frac{1}{2}}{\frac{1}{4}} = 2
$$

Substituting back:

$$
T(N) \leq \frac{N}{2} \cdot 2 = N
$$

$$
\therefore T(N) = O(N)
$$

**Intuition:** Most nodes are near the **leaves** and require very little work (0 or 1 swaps), while only a **few nodes near the root** incur $O(\log N)$ cost. Specifically:
- $\sim N/2$ leaf nodes → 0 swaps each
- $\sim N/4$ nodes at height 1 → at most 1 swap each
- $\sim N/8$ nodes at height 2 → at most 2 swaps each
- ...
- 1 root node → at most $\log N$ swaps

The exponential decrease in node count outweighs the linear increase in work per node.

**Summary:**
| Operation | Time Complexity | Description |
| --- | --- | --- |
| Insert | O(log N) | Add at end, bubble up |
| Delete (Extract Root) | O(log N) | Replace root with last, heapify down |
| Get Min/Max (Peek) | O(1) | Root element |
| Build Heap (Naive) | O(N log N) | Insert one by one |
| Build Heap (Heapify) | O(N) | Heapify from last non-leaf to root |
| Heap Sort | O(N log N) | Build Heap O(N) + N × Delete O(log N) |


### Dijkstra's Algorithm (Priority Queue)

**Problem:** Given a weighted graph with **non-negative** edge weights, find the shortest path from a source vertex to all other vertices.

**Key Idea (Greedy):** Always process the **unvisited vertex with the smallest known distance** first. Once a vertex is processed (extracted from the priority queue and marked as visited), its shortest distance is **finalized** — it will never be updated again.

> This greedy property holds **only when all edge weights are non-negative**. For negative weights, use Bellman-Ford.

**Algorithm (Min-Heap / Priority Queue):**
1. Initialize `dist[source] = 0`, `dist[v] = ∞` for all other vertices.
2. Push `(0, source)` into a **min-heap** (priority queue ordered by distance).
3. While the min-heap is not empty:
   1) Extract the vertex `u` with the **minimum distance** from the heap.
   2) If `u` is already **visited**, skip it (stale entry).
   3) Mark `u` as **visited**.
   4) For each neighbor `v` of `u` with edge weight `w`:
      - If `dist[u] + w < dist[v]` → update `dist[v] = dist[u] + w`, push `(dist[v], v)` into the heap.

```
Algorithm Dijkstra(Graph, source):
    dist[source] = 0
    for each vertex v ≠ source:
        dist[v] = ∞

    minHeap.push( (0, source) )

    while minHeap is not empty:
        (d, u) = minHeap.extractMin()

        if u is visited: continue    // skip stale entries
        mark u as visited

        for each neighbor (v, w) of u:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                prev[v] = u
                minHeap.push( (dist[v], v) )
```

> **Note on stale entries:** Since we push new `(distance, vertex)` pairs without removing old ones, the heap may contain outdated entries. We skip them by checking if the vertex has already been visited. This is called the **"lazy deletion"** approach — simpler than implementing a decrease-key operation.

---

**Example:** Shortest paths from `A` in the following directed weighted graph.

```
             A
            / \
         3 /   \ 6
          /     \
         v   4   v
         B ----> C
        /\     / \
     11/  \4  /8  \ 11
      /    \ /     \
     v  +4  vv   2  v
     E <---  D  ---> G
      \      |5     /
       \     v     /
       9\    F    /2
         \   |   /
          \  |1 /
           \ | /
            vvv
             H
```

**Step-by-step execution:**

| Step | Extract | dist[A] | dist[B] | dist[C] | dist[D] | dist[E] | dist[F] | dist[G] | dist[H] | Action |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Init | — | **0** | ∞ | ∞ | ∞ | ∞ | ∞ | ∞ | ∞ | Push (0,A) |
| 1 | A(0) | **0** | **3** | **6** | ∞ | ∞ | ∞ | ∞ | ∞ | Relax B=3, C=6 |
| 2 | B(3) | 0 | **3** | 6 | **7** | **14** | ∞ | ∞ | ∞ | Relax D=7, E=14 (C=7>6 skip) |
| 3 | C(6) | 0 | 3 | **6** | 7 | 14 | ∞ | **17** | ∞ | Relax G=17 (D=14>7 skip) |
| 4 | D(7) | 0 | 3 | 6 | **7** | **11** | **12** | **9** | ∞ | Relax E=11, F=12, G=9 |
| 5 | G(9) | 0 | 3 | 6 | 7 | 11 | 12 | **9** | **11** | Relax H=11 |
| 6 | E(11) | 0 | 3 | 6 | 7 | **11** | 12 | 9 | 11 | H=20>11 skip |
| 7 | H(11) | 0 | 3 | 6 | 7 | 11 | 12 | 9 | **11** | No neighbors |
| 8 | F(12) | 0 | 3 | 6 | 7 | 11 | **12** | 9 | 11 | H=13>11 skip |

**Final shortest distances from A:**
```
A:0   B:3   C:6   D:7   E:11   F:12   G:9   H:11
```

**Shortest path traces (using prev[]):**
```
A → B : A → B                    (cost 3)
A → C : A → C                    (cost 6)
A → D : A → B → D                (cost 7)
A → E : A → B → D → E            (cost 11)
A → F : A → B → D → F            (cost 12)
A → G : A → B → D → G            (cost 9)
A → H : A → B → D → G → H        (cost 11)
```

---

**Time Complexity: O((V + E) · log V)**

| Operation | Count | Cost per op | Total |
| --- | --- | --- | --- |
| Extract-Min | V | O(log V) | O(V log V) |
| Push (Insert) | at most E | O(log V) | O(E log V) |
| **Total** | | | **O((V + E) log V)** |

> With a Fibonacci Heap, decrease-key runs in O(1) amortized, giving O(V log V + E). But in practice, binary heap with lazy deletion is simpler and often faster due to lower constant factors.

**Comparison with other shortest path algorithms:**
| Algorithm | Time | Negative Weights | Cycles | Notes |
| --- | --- | --- | --- | --- |
| Dijkstra (Binary Heap) | O((V+E) log V) | ✗ | ✓ | Greedy, fastest for non-negative weights |
| Bellman-Ford | O(V·E) | ✓ | ✓ (detects negative cycles) | Slower but handles negative weights |
| DAG Shortest Path | O(V+E) | ✓ | ✗ (DAG only) | Topological sort + relaxation |


---

# Self-Balancing Binary Search Trees

A BST can degenerate into a linked list when elements are inserted in sorted order, resulting in $O(N)$ operations. Self-balancing BSTs automatically maintain balance to guarantee $O(\log N)$.

---

## AVL Tree

- **Balance Factor** = Height(left) - Height(right), must be $\{-1, 0, 1\}$ for every node.
- If $|BF| \geq 2$, rebalance using **rotations**.
- Height: $h \leq 1.44 \cdot \log_2(N+2)$ (**stricter** balance than Red-Black Tree)

**4 Rotation Cases:**

| Condition | Rotation |
| --- | --- |
| BF = +2, Left child BF = +1 | **LL** (Single Right Rotation) |
| BF = -2, Right child BF = -1 | **RR** (Single Left Rotation) |
| BF = +2, Left child BF = -1 | **LR** (Double: Left → Right) |
| BF = -2, Right child BF = +1 | **RL** (Double: Right → Left) |

**Time Complexity:** Search, Insert, Delete are all $O(\log N)$
- Insertion requires at most **1 rotation** to fix
- Deletion may require up to $O(\log N)$ rotations
- Each node stores an extra **height** value

---

## Red-Black Tree

**5 Rules:**
1. The root is always **Black**
2. NIL (null) nodes are **Black**
3. Every path from a node to its descendant NIL leaves has the **same number of Black nodes** (Black Height)
4. **No consecutive Red nodes** — a Red node's children must be Black
5. Newly inserted nodes are always **Red**

**Key Properties:**
- Height: $h \leq 2 \cdot \log_2(N+1)$ (looser than AVL, but still guarantees $O(\log N)$)
- Red-Black Tree is equivalent to a **2-3-4 Tree**
- Insertion requires at most **2 rotations**, deletion at most **3 rotations**
- Each node stores an extra **color bit** (1 bit)

**Insertion Fix-up Cases:**
- Uncle is **Red** → Color Flip (flip colors of parent, uncle, and grandparent)
- Uncle is **Black** + Triangle shape → Rotate parent to form a line
- Uncle is **Black** + Line shape → Rotate grandparent + recolor

**Time Complexity:** Search, Insert, Delete are all $O(\log N)$

---

## AVL vs Red-Black Tree Comparison

| Property | AVL Tree | Red-Black Tree |
| --- | --- | --- |
| **Balance Strictness** | Strict ($h \leq 1.44 \log N$) | Loose ($h \leq 2 \log N$) |
| **Search** | Slightly faster (shorter height) | Slightly slower (taller height) |
| **Insert/Delete** | Slower (more rotations possible) | Faster (at most 2~3 rotations) |
| **Extra Storage** | height (integer) | color (1 bit) |
| **Best For** | Read-heavy workloads | Write-heavy workloads |
| **Real-World Usage** | Databases, lookup-intensive apps | C++ STL (`std::map`, `std::set`), Java `TreeMap`, Linux kernel |

>.
>.
>.
>.
>.
>.
>.
>.
>.
>.
>.
>.
>.
>위에 . 들은 github 에서 print 할때 밑에 잘리는거 방지용