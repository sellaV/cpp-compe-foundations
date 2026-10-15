# 15. Search a sorted range recursively

**Core stage 4: Pointers, lifetime and recursion**

## Learn first

recursive functions, base cases, signed index bounds. Read the matching stage in [CONCEPTS.md](../../docs/CONCEPTS.md). No engineering knowledge is required.

## Contract

Return true if target occurs in a sorted nondecreasing vector<int>. Use a recursive helper and manually split the search interval; no loops or library search algorithms. n<=100000. Empty input returns false.

## Example

```text
contains_recursive({1,3,3,8},3) -> true
```

## Work

Implement starter.hpp, then run `python3 tools/run.py 15` from the repository root. Write an approach, trace a small case, and add a test. Explain which data is copied, borrowed or changed.

The TODO exception is only an unfinished-placeholder mechanism, not a concept you must learn or use in your implementation. Implement the error/result behavior in the contract. Algorithms that the contract prohibits must not be used even if tests pass.

<details>
<summary>Hint: approach</summary>

A half-open interval [begin,end) is empty when begin>=end. Recurse into just one smaller half.

</details>

<details>
<summary>Reasoning and solution — after attempting</summary>

Recursion is a language/control-flow tool, not a library feature. An explicit base case prevents infinite recursion.

Read [solution.hpp](solution.hpp). **Complexity:** O(log n) time and O(log n) call-stack space.

`python3 tools/run.py 15 --reference` tests the reference without modifying your work.

</details>
