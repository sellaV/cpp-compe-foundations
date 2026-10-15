# 01. Filter valid sensor samples

**Warm-up** · 1 · Core logic and C++ syntax

## C++ you will practice

const references, range-based loops, vector, return by value.

## Problem

Return samples in the inclusive range [lo, hi], preserving order. Input is not modified. Empty input is valid; lo > hi throws std::invalid_argument. Up to 100,000 signed int samples.

## Example

```text
filter_samples({-2, 4, 9, 4}, 0, 5) -> {4, 4}
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 01
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Build a new vector. A sample passes only when both comparisons are true.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

A const reference avoids copying the input and prevents accidental modification. Push matching samples in traversal order; returning a vector by value is safe and permits move/copy elision.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

A const reference avoids copying the input and prevents accidental modification. Push matching samples in traversal order; returning a vector by value is safe and permits move/copy elision.

**Complexity:** O(n) time; O(n) output storage.

Check the reference independently with `python tools/run.py 01 --reference`.
Reference mode does not change your starter file.

</details>
