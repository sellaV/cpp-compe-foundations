# 23. Rank records without losing tie order

**Stage 6: STL, callables, templates and iterators**

## Learn before solving

struct, stable_sort, strict weak ordering, iterators. Read the matching section in [CONCEPTS.md](../../docs/CONCEPTS.md).
No engineering or machine-learning knowledge is needed.

## Contract

Record has string name and int score. ranked(vector<Record> records) returns records sorted descending by score, preserving original order for equal scores. Caller input unchanged. Use std::stable_sort with a strict comparator. n<=100000.

## Example

```text
{A:10,B:20,C:10} -> {B:20,A:10,C:10}
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 tools/run.py 23` from the repo root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

For equal scores, comparator must return false, not true. Let stable_sort preserve their input order.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

A comparator describes strict ordering, not whether an element is less-than-or-equal. Using >= violates the standard algorithm precondition. A by-value parameter allows sorting without modifying caller data.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

A comparator describes strict ordering, not whether an element is less-than-or-equal. Using >= violates the standard algorithm precondition. A by-value parameter allows sorting without modifying caller data.

**Complexity:** O(n log n) comparisons with available extra memory; O(n log² n) fallback; O(n) copy/output storage.

Check it with `python3 tools/run.py 23 --reference`. Reference mode never replaces your starter.

</details>
