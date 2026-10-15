# 03. Pair of complementary measurements

**Core** · 1 · Core logic and C++ syntax

## C++ you will practice

unordered_map, optional, pair, iterators, int64_t.

## Problem

Return indices (i,j), i<j, whose int values sum to target (int64_t). Return nullopt if absent. Scan j left-to-right and return the first possible j, choosing the earliest i for it. Up to 100,000 values. target is in [-10^12,10^12].

## Example

```text
two_sum({4,2,4}, 8) -> (0,2)
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 03
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Look for the complement before inserting the current value. Preserve the earliest index for duplicates.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

The map contains only earlier samples. emplace does not overwrite an existing key, enforcing the earliest-i rule. Compute the complement in 64 bits to avoid signed int overflow.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

The map contains only earlier samples. emplace does not overwrite an existing key, enforcing the earliest-i rule. Compute the complement in 64 bits to avoid signed int overflow.

**Complexity:** Expected O(n) time; O(n) space. Hash tables have O(n²) worst-case total time.

Check the reference independently with `python tools/run.py 03 --reference`.
Reference mode does not change your starter file.

</details>
