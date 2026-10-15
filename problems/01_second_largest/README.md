# 01. Second distinct largest using state flags

**Core stage 1: State, loops, functions and references**

## Learn first

int, bool, conditions, loops, a simple result struct. Read the matching stage in [CONCEPTS.md](../../docs/CONCEPTS.md). No engineering knowledge is required.

## Contract

Return NumberResult{found,value}. found is true only when a second DISTINCT largest int exists; otherwise found=false and value=0. Zero is a valid answer when found=true. Do not sort or use optional, algorithms, sets or maps. Input unchanged; n<=100000; full int range supported.

## Example

```text
{8,8,3,5} -> {true,5}; {1,0} -> {true,0}; {7,7} -> {false,0}
```

## Work

Implement starter.hpp, then run `python3 tools/run.py 01` from the repository root. Write an approach, trace a small case, and add a test. Explain which data is copied, borrowed or changed.

The TODO exception is only an unfinished-placeholder mechanism, not a concept you must learn or use in your implementation. Implement the error/result behavior in the contract. Algorithms that the contract prohibits must not be used even if tests pass.

<details>
<summary>Hint: approach</summary>

Use first/second ints plus has_first/has_second bool flags. Never read a stored value before its flag says it exists.

</details>

<details>
<summary>Reasoning and solution — after attempting</summary>

The flags represent absence independently from the data, so zero and INT_MIN remain valid values. When a new maximum appears, the old maximum becomes the second largest.

Read [solution.hpp](solution.hpp). **Complexity:** O(n) time, O(1) extra space.

`python3 tools/run.py 01 --reference` tests the reference without modifying your work.

</details>
