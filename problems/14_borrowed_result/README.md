# 14. Return the address of the first maximum

**Core stage 4: Pointers, lifetime and recursion**

## Learn first

pointer returns, const overloads, borrowed lifetime. Read the matching stage in [CONCEPTS.md](../../docs/CONCEPTS.md). No engineering knowledge is required.

## Contract

Implement mutable and const max_element_ptr overloads. Return pointer into the input at the first maximum, or nullptr if data is nullptr or n==0. Non-null input otherwise points to at least n live elements. Do not allocate or copy. Caller must keep input alive while using result.

## Example

```text
{2,7,7} -> address of element 1; changing through mutable result changes input
```

## Work

Implement starter.hpp, then run `python3 tools/run.py 14` from the repository root. Write an approach, trace a small case, and add a test. Explain which data is copied, borrowed or changed.

The TODO exception is only an unfinished-placeholder mechanism, not a concept you must learn or use in your implementation. Implement the error/result behavior in the contract. Algorithms that the contract prohibits must not be used even if tests pass.

<details>
<summary>Hint: approach</summary>

Retain the address of the best element rather than the address of a local copy.

</details>

<details>
<summary>Reasoning and solution — after attempting</summary>

A borrowed result identifies an actual element without owning it. const overloads preserve the caller's read-only access.

Read [solution.hpp](solution.hpp). **Complexity:** O(n) time, O(1) space.

`python3 tools/run.py 14 --reference` tests the reference without modifying your work.

</details>
