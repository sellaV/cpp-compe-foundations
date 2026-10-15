# 01. Second distinct largest value

**Stage 1: Functions, types and references**

## Learn before solving

const reference, vector, optional, branching. Read the matching section in [CONCEPTS.md](../../docs/CONCEPTS.md).
No engineering or machine-learning knowledge is needed.

## Contract

Return the second DISTINCT largest int, or nullopt if fewer than two distinct values exist. Input is unchanged; empty input valid. Handle the entire int range. Do not sort. n<=100000.

## Example

```text
second_largest({8,8,3,5}) -> 5
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 tools/run.py 01` from the repo root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Track two optional values. A duplicate maximum must not become second largest.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

optional represents absence without reserving a sentinel like INT_MIN. The invariant is that first and second are the largest distinct values seen so far.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

optional represents absence without reserving a sentinel like INT_MIN. The invariant is that first and second are the largest distinct values seen so far.

**Complexity:** O(n) time, O(1) extra space.

Check it with `python3 tools/run.py 01 --reference`. Reference mode never replaces your starter.

</details>
