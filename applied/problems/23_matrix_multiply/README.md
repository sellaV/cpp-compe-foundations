# 23. Multiply row-major matrices

**Stretch** · 6 · Edge AI and numerical thinking

## C++ you will practice

flat tensors, triple loops, index arithmetic, shape contracts.

## Problem

Compute C=A*B for A of shape m*k and B of shape k*n, both flattened row-major vector<double>. Return m*n row-major output. Nonnegative dimensions, exact buffer sizes required; else invalid_argument. Zero dimensions valid (k=0 produces m*n zeros). Dimensions<=100; values finite and |value|<=1000.

## Example

```text
matmul({1,2,3,4},{5,6,7,8},2,2,2) -> {19,22,43,50}
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 23
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

C[r,c] is the dot product of row r of A and column c of B.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

The shared k dimension is reduced, not copied to the output. Row-major indexing is A[r*k+t], B[t*n+c], C[r*n+c]. A non-square test catches assumptions hidden by 2x2 examples.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

The shared k dimension is reduced, not copied to the output. Row-major indexing is A[r*k+t], B[t*n+c], C[r*n+c]. A non-square test catches assumptions hidden by 2x2 examples.

**Complexity:** O(m*k*n) time; O(m*n) output storage.

Check the reference independently with `python tools/run.py 23 --reference`.
Reference mode does not change your starter file.

</details>
