# 09. First nonrepeating byte using a plain array

**Core stage 3: Arrays and general search logic**

## Learn first

built-in arrays, two passes, result structs, casts. Read the matching stage in [CONCEPTS.md](../../docs/CONCEPTS.md). No engineering knowledge is required.

## Contract

Return IndexResult{found,index} for the first byte occurring exactly once. Absent -> {false,0}. All 256 byte values allowed; input length<=100000. Use a built-in counter array, not array/map/optional library types.

## Example

```text
first_unique("swiss") -> {true,1}
```

## Work

Implement starter.hpp, then run `python3 tools/run.py 09` from the repository root. Write an approach, trace a small case, and add a test. Explain which data is copied, borrowed or changed.

The TODO exception is only an unfinished-placeholder mechanism, not a concept you must learn or use in your implementation. Implement the error/result behavior in the contract. Algorithms that the contract prohibits must not be used even if tests pass.

<details>
<summary>Hint: approach</summary>

Use a zero-initialized unsigned counter table, then scan the original string in order.

</details>

<details>
<summary>Reasoning and solution — after attempting</summary>

A built-in array makes storage and indexing explicit. Convert each char to unsigned char before indexing, because char may be signed.

Read [solution.hpp](solution.hpp). **Complexity:** O(n+256) time, O(256) storage.

`python3 tools/run.py 09 --reference` tests the reference without modifying your work.

</details>
