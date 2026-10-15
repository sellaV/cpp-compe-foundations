# 12. Remove duplicates while preserving order

**Core stage 3: Arrays and general search logic**

## Learn first

in-place compaction, nested scans, vector resizing. Read the matching stage in [CONCEPTS.md](../../docs/CONCEPTS.md). No engineering knowledge is required.

## Contract

Modify vector<int> to retain only the first occurrence of each value, preserving order. No additional container, set/map, sorting, or unique/erase algorithms. resize is allowed after compaction. n<=2000.

## Example

```text
{3,1,3,2,1} -> {3,1,2}
```

## Work

Implement starter.hpp, then run `python3 tools/run.py 12` from the repository root. Write an approach, trace a small case, and add a test. Explain which data is copied, borrowed or changed.

The TODO exception is only an unfinished-placeholder mechanism, not a concept you must learn or use in your implementation. Implement the error/result behavior in the contract. Algorithms that the contract prohibits must not be used even if tests pass.

<details>
<summary>Hint: approach</summary>

Maintain a prefix of distinct values; check each input against that prefix before copying it forward.

</details>

<details>
<summary>Reasoning and solution — after attempting</summary>

The write index never passes the read index, so overwriting earlier slots does not destroy unread input.

Read [solution.hpp](solution.hpp). **Complexity:** O(n²) time, O(1) extra space.

`python3 tools/run.py 12 --reference` tests the reference without modifying your work.

</details>
