# Sorting Algorithms

## Comparison Based
1. Bubble Sort : O(N^2)
2. Insertion Sort : O(N^2)
3. Selection Sort : O(N^2)
---
4. Heap Sort : O(N*logN)
5. Merge Sort : O(N*logN)
6. Quick Sort : O(N*logN) average, O(N^2) worst

## Index Based
1. Count Sort : O(N)
2. Bucket/Bin Sort : O(N)
3. Radix Sort : O(N) 

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

> if Θ(g(n)) exists, O(..) and Ω(..) must also exist with the exact same function g(n), but not for o(..) and ω(..).
> if O(..) and Ω(..) exist with different functions, Θ(..) cannot exist (because it is not tight)
> tight means that the upper and lower bounds are the same function (g(n)), where g(n) belong to the same asymptotic class (1 < logn < n < nlogn < n^2 < n^3 < ... < 2^n < 3^n)

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

## Q&A
> Q1 : In a depth-first traversal of a graph G with n vertices, k edges are marked as tree edges. The number of connected components in G is ?
> A1 : n-k
---
> Q2 : Let G be a directed graph whose vertex set is the set of numbers from 1 to 100. There is an edge from a vertex i to a vertex j iff either j = i + 1 or j = 3i. The minimum number of edges in a path in G from vertex 1 to  vertex 100 is ?
> A2 : 7
---
> Q3 : Let T be a depth first search tree in a undirected graph G. Vertices u and v are leaves of this tree T. The degrees of both u and v in G are at least 2. Which one of the following statements is true?
> A3 : There must exist a cycle in G containing u and all its neighbours in G
---
> Q4 : What is the largest integer m such that every simple connected graph with n vertices and n edges contains at least m different spanning trees?
> A4 : 3
---

## Algorithm Strategies
1. **Divide and Conquer (DAC)** : Divide the problem into smaller subproblems, solve each subproblem independently, and then combine the solutions to solve the original problem.
   > binary search
   > merge sort
   > strassen's matrix multiplication
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
   > Used for optimization problems (e.g., finding the minimum spanning tree, shortest path)
   > there are constraints and objectives (usually minimizing or maximizing) that need to be satisfied
   > MST (Kruskal's, Prim's)
     1) Spanning Tree : N vertices, N-1 edges, no cycle
     2) Minimum Spanning Tree : Spanning tree with the minimum total edge weight
     3) Kruskal's Algorithm : Sort edges by weight and add them one by one to the MST, skipping those that would form a cycle.
     4) Prim's Algorithm : Start from an arbitrary vertex and grow the MST by adding the smallest edge that connects a vertex in the MST to a vertex outside the MST.
   > Dijkstra's Algorithm : Find the shortest path from a source vertex to all other vertices in a graph with non-negative edge weights.
   > Huffman Coding : A lossless data compression algorithm that assigns variable-length codes to characters based on their frequencies. More frequent characters get shorter codes.
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
   
3. **Dynamic Programming** : Break the problem into overlapping subproblems, solve each subproblem just once, and store their solutions.
   > Used for optimization problems where `only` one optimal solution is needed.
   > there are constraints and objectives (usually minimizing or maximizing) that need to be satisfied
   > Consider previous decisions and their outcomes to make the current decision
   > Try all possible decisions and choose the best one based on the results of subproblems.
     1) Memoization (Top-Down) : Store the results of expensive function calls and return the cached result when the same inputs occur again.
     2) Recursion (Top-Down) : Solve the problem by breaking it into smaller subproblems recursively, solving each subproblem and combining their results.
     3) Tabulation (Bottom-Up) : Fill a table in a systematic way to solve the problem iteratively.
     -. Normally start from recursive approach, then add memoization to optimize it, and finally convert it to tabulation for further optimization.
     -. Tabulation requires additional mathematical formula to determine the order of filling the table, while memoization does not require it.
   > Zero-One Knapsack Problem : Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. (Each item can either be included or excluded)
   > Longest Common Subsequence (LCS) : Given two strings A and B, find the length of the longest subsequence that is common to both strings. A subsequence is a sequence that appears in the same relative order but not necessarily contiguous.

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
   

4. **Backtracking** : Build a solution incrementally, abandoning solutions that fail to satisfy the constraints of the problem.
   > Try all possible combinations of decisions and backtrack(go back to previous state) when there is no combination satisfying the constraints.
   > There are constraints that need to be satisfied (e.g., no two queens threaten each other in the N-Queens problem)
   > Sudoku Solver : Given a partially filled 9x9 grid, fill the empty cells so that each row, column, and 3x3 subgrid contains all digits from 1 to 9.
   > Rat in a Maze : Given a maze represented as a 2D grid, find a path from the start point to the end point, moving only in four directions (up, down, left, right) and avoiding obstacles.
   > N-Queens Problem : Place N queens on an N×N chessboard so that no two queens threaten each other.
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
> We can convert any recursive function into an iterative one using loops, and vice versa. 
> Many mathematical problems often can be solved using recursion easily, but it may takes too much stack space.
> If the stack space is a concern, we can convert the recursive function into an iterative one using loops.
> If the problem doesn't take too much stack space, we can use recursion for better readability and maintainability.


