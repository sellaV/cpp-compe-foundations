# 06. Rotate in place using manual reversals

**Core stage 2: Manual sequence operations**

## Learn first

index loops, helper functions, mutable references, modulo. Read the matching stage in [CONCEPTS.md](../../docs/CONCEPTS.md). No engineering knowledge is required.

## Contract

Rotate vector<int> right by k positions in place; k is size_t and may exceed n. Empty valid. O(1) extra space. Write the reversal loop yourself; no std::reverse, std::rotate, iterators, or temporary vector. n<=100000.

## Example

```text
{1,2,3,4,5},k=2 -> {4,5,1,2,3}
```

## Work

Implement starter.hpp, then run `python3 tools/run.py 06` from the repository root. Write an approach, trace a small case, and add a test. Explain which data is copied, borrowed or changed.

The TODO exception is only an unfinished-placeholder mechanism, not a concept you must learn or use in your implementation. Implement the error/result behavior in the contract. Algorithms that the contract prohibits must not be used even if tests pass.

<details>
<summary>Hint: approach</summary>

Write a helper reversing the half-open index interval [begin,end), then reverse the whole sequence and its two resulting parts.

</details>

<details>
<summary>Reasoning and solution — after attempting</summary>

This practices index reasoning and function decomposition before learning the equivalent standard algorithms later.

Read [solution.hpp](solution.hpp). **Complexity:** O(n) time, O(1) space.

`python3 tools/run.py 06 --reference` tests the reference without modifying your work.

</details>
