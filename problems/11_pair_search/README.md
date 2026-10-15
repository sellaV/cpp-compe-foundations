# 11. Find a pair by checking candidates yourself

**Core stage 3: Arrays and general search logic**

## Learn first

nested loops, long long arithmetic, structs, early return. Read the matching stage in [CONCEPTS.md](../../docs/CONCEPTS.md). No engineering knowledge is required.

## Contract

Return PairResult{found,first,second}; indices i<j satisfy values[i]+values[j]==target. Choose smallest possible j, then smallest i. Absent -> {false,0,0}. Input ints, target within +/-10^12; n<=2000. No map, pair, optional or search algorithms. Expected manual O(n²).

## Example

```text
{4,2,4},target=8 -> {true,0,2}
```

## Work

Implement starter.hpp, then run `python3 tools/run.py 11` from the repository root. Write an approach, trace a small case, and add a test. Explain which data is copied, borrowed or changed.

The TODO exception is only an unfinished-placeholder mechanism, not a concept you must learn or use in your implementation. Implement the error/result behavior in the contract. Algorithms that the contract prohibits must not be used even if tests pass.

<details>
<summary>Hint: approach</summary>

Loop over the second index first to preserve the requested order. Widen operands before adding.

</details>

<details>
<summary>Reasoning and solution — after attempting</summary>

This is a reasonable baseline for learning loops and specifying result states. The later hash-table exercise introduces a faster approach after the core logic is familiar.

Read [solution.hpp](solution.hpp). **Complexity:** O(n²) time, O(1) space.

`python3 tools/run.py 11 --reference` tests the reference without modifying your work.

</details>
