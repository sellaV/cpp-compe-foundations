# 15. Dependency order for automation tasks

**Stretch** · 4 · Robotics and scheduling algorithms

## C++ you will practice

indegree counts, topological sorting, optional, min-heap.

## Problem

Given n tasks labeled 0..n-1 and directed edges (a,b) meaning a must run before b, return the lexicographically smallest topological ordering. Return nullopt for a cycle. Duplicate edges are allowed. Invalid endpoints throw invalid_argument. n=0 returns engaged empty vector. n<=10,000, edges<=100,000.

## Example

```text
task_order(3,{{0,2},{1,2}}) -> {0,1,2}
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 15
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Tasks with indegree zero are ready. Use a min-heap to choose the smallest ready ID.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

Kahn's algorithm removes ready vertices and their outgoing edges. If fewer than n vertices are removed, a cycle remains. Counting and later decrementing duplicate edges consistently preserves correctness.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

Kahn's algorithm removes ready vertices and their outgoing edges. If fewer than n vertices are removed, a cycle remains. Counting and later decrementing duplicate edges consistently preserves correctness.

**Complexity:** O(E+V log V) time; O(V+E) space.

Check the reference independently with `python tools/run.py 15 --reference`.
Reference mode does not change your starter file.

</details>
