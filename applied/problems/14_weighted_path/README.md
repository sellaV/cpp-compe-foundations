# 14. Minimum-cost route through a robot graph

**Stretch** · 4 · Robotics and scheduling algorithms

## C++ you will practice

priority_queue, greater, adjacency lists, int64_t distances.

## Problem

Graph is vector<vector<pair<int,int>>>; each pair is (destination,nonnegative cost). Return shortest int64_t distances from source; unreachable=INT64_MAX. Invalid source, destination, or negative cost throws invalid_argument, even in an unreachable component. At most 10,000 vertices, 100,000 edges; each cost<=10^6.

## Example

```text
edges 0->1 cost 5, 0->2 cost 1, 2->1 cost 1 gives {0,2,1}
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 14
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Use a min-heap of (distance,node). Skip entries whose distance no longer equals the best known value.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

Dijkstra repeatedly settles the smallest candidate distance. Nonnegative edges are essential. Relaxation updates a neighbor only on improvement; stale heap entries need not be removed eagerly.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

Dijkstra repeatedly settles the smallest candidate distance. Nonnegative edges are essential. Relaxation updates a neighbor only on improvement; stale heap entries need not be removed eagerly.

**Complexity:** O((V+E) log(E+1)) time with this lazy heap; O(V+E) space.

Check the reference independently with `python tools/run.py 14 --reference`.
Reference mode does not change your starter file.

</details>
