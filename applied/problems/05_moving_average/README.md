# 05. Moving average without repeated sums

**Core** · 2 · Arrays, algorithms and bit logic

## C++ you will practice

indexing, vector<double>, explicit casts, exceptions.

## Problem

Return the mean of each complete consecutive window of width k. k==0 throws invalid_argument; k>n returns empty. Input contains finite doubles with |value|<=10^6 and n<=100,000. Use tolerance 1e-8 for tests.

## Example

```text
moving_average({1,3,5,7},2) -> {2,4,6}
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 05
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Sum the first window; every shift removes one sample and adds one sample.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

The rolling sum tracks exactly the k samples in the current window. Divide in floating point. Do not return averages for incomplete windows.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

The rolling sum tracks exactly the k samples in the current window. Divide in floating point. Do not return averages for incomplete windows.

**Complexity:** O(n) time; O(n-k+1) output space and O(1) auxiliary space.

Check the reference independently with `python tools/run.py 05 --reference`.
Reference mode does not change your starter file.

</details>
