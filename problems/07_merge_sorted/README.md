# 07. Merge two sorted sequences

**Core stage 2: language and manual logic**

## Learn before solving

two pointers, bounds, const references. Read the matching stage in [CONCEPTS.md](../../docs/CONCEPTS.md).
No engineering or machine-learning knowledge is needed.

## Contract

Merge two nondecreasing vector<int>s into a new sorted vector, retaining duplicates. Do not sort the combined data or call std::merge. Inputs unchanged. Total length<=100000.

## Example

```text
merge_sorted({1,3,3},{2,3}) -> {1,2,3,3,3}
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 tools/run.py 07` from the repo root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Maintain one unread index for each input. Once either ends, only the other can supply values.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

Each step consumes the smallest remaining element. Bounds checks must happen before indexing; short-circuit evaluation makes the choice safe.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

Each step consumes the smallest remaining element. Bounds checks must happen before indexing; short-circuit evaluation makes the choice safe.

**Complexity:** O(n+m) time and output space.

Check it with `python3 tools/run.py 07 --reference`. Reference mode never replaces your starter.

</details>
