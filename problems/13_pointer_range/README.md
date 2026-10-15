# 13. Reverse a borrowed array range

**Core stage 4: Pointers, lifetime and recursion**

## Learn first

raw pointers, nullptr, explicit lengths, status returns. Read the matching stage in [CONCEPTS.md](../../docs/CONCEPTS.md). No engineering knowledge is required.

## Contract

reverse_range(int* data,size_t n) returns false for nullptr with n>0 and otherwise reverses n ints and returns true. nullptr with n==0 is valid and requires no pointer arithmetic. For non-null pointers caller guarantees a live writable array of at least n elements. No allocation, deletion, exceptions or std::reverse. n<=100000.

## Example

```text
int a[]{1,2,3,4}; reverse_range(a,4) -> true; a becomes {4,3,2,1}
```

## Work

Implement starter.hpp, then run `python3 tools/run.py 13` from the repository root. Write an approach, trace a small case, and add a test. Explain which data is copied, borrowed or changed.

The TODO exception is only an unfinished-placeholder mechanism, not a concept you must learn or use in your implementation. Implement the error/result behavior in the contract. Algorithms that the contract prohibits must not be used even if tests pass.

<details>
<summary>Hint: approach</summary>

The pointer borrows an existing array; use symmetric indices while i<n/2.

</details>

<details>
<summary>Reasoning and solution — after attempting</summary>

A pointer has neither an ownership guarantee nor a stored array length. The caller supplies both lifetime and size guarantees.

Read [solution.hpp](solution.hpp). **Complexity:** O(n) time, O(1) space.

`python3 tools/run.py 13 --reference` tests the reference without modifying your work.

</details>
