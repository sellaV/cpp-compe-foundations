# 07. Merge motor reservation intervals

**Core** · 2 · Arrays, algorithms and bit logic

## C++ you will practice

struct, sort comparator, value parameters, back().

## Problem

Intervals have signed int start,end with start<=end. Treat them as closed intervals and merge overlaps including touching endpoints. Return sorted disjoint intervals. Invalid intervals throw invalid_argument. n<=100,000. Do not mutate caller input.

## Example

```text
merge_intervals({{5,8},{1,3},{3,6}}) -> {{1,8}}
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 07
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Sort by start, then compare each start with the end of the last output interval.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

Pass by value to sort a private copy. An overlap extends the last end to the maximum end; a gap starts a new interval. The struct documents the meaning better than anonymous pairs.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

Pass by value to sort a private copy. An overlap extends the last end to the maximum end; a gap starts a new interval. The struct documents the meaning better than anonymous pairs.

**Complexity:** O(n log n) time; O(n) storage.

Check the reference independently with `python tools/run.py 07 --reference`.
Reference mode does not change your starter file.

</details>
