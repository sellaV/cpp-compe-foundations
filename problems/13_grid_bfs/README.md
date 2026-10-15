# 13. Shortest path in an occupancy grid

**Core** · 4 · Robotics and scheduling algorithms

## C++ you will practice

queue, pair, vector of vectors, structured bindings, BFS.

## Problem

A rectangular grid has 0=free,1=blocked. Start=(0,0), goal=(rows-1,cols-1). Return shortest number of four-neighbor moves; return -1 if no path, a blocked endpoint, empty grid, or zero columns. Ragged grids throw invalid_argument. Up to 100x100; no diagonals.

## Example

```text
grid {{0,1},{0,0}} -> 2
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 13
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Mark a cell visited when it enters the queue. BFS explores distance layers.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

With equal move costs, the first discovery of a cell has minimum distance. A queue, not a stack, preserves this layer order. Signed neighbor coordinates make checking negative indices straightforward.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

With equal move costs, the first discovery of a cell has minimum distance. A queue, not a stack, preserves this layer order. Signed neighbor coordinates make checking negative indices straightforward.

**Complexity:** O(rows*cols) time and space.

Check the reference independently with `python tools/run.py 13 --reference`.
Reference mode does not change your starter file.

</details>
