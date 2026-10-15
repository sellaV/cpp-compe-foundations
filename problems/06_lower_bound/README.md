# 06. First sample at or above a target

**Core** · 2 · Arrays, algorithms and bit logic

## C++ you will practice

half-open intervals, unsigned indices, binary search.

## Problem

Implement lower_bound manually. Given a nondecreasing vector<int>, return the first index with value>=target, or n if absent. Empty and duplicate values are valid. Do not use standard search algorithms. n<=100,000.

## Example

```text
first_at_least({1,3,3,8},3) -> 1
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 06
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Search [lo,hi). Compute mid as lo+(hi-lo)/2 to avoid overflow.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

Values before lo are too small; all candidates are in [lo,hi). When mid qualifies, it may be the first, so set hi=mid. Otherwise set lo=mid+1. The interval shrinks on every iteration.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

Values before lo are too small; all candidates are in [lo,hi). When mid qualifies, it may be the first, so set hi=mid. Otherwise set lo=mid+1. The interval shrinks on every iteration.

**Complexity:** O(log n) time; O(1) space.

Check the reference independently with `python tools/run.py 06 --reference`.
Reference mode does not change your starter file.

</details>
