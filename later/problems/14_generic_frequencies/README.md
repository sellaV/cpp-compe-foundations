# 14. Count generic values from iterators

**Later track: standard-library tools**

## Learn before solving

function templates, iterator_traits, map, iterator ranges. Read the matching section in [CONCEPTS.md](../../../docs/LIBRARIES.md).
This is a later-track exercise; first study the related core language concept.

## Contract

Implement frequencies(It first,It last) returning map<T,size_t> where T=iterator value_type. Support vector/list/string const or mutable iterators, with ordered copyable T. Range is valid and finite; empty returns empty. Traverse once; do not index, subtract iterators, or require random access. n<=100000.

## Example

```text
list<int>{3,1,3} -> map{{1,1},{3,2}}
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 later/tools/run.py 14` from the repository root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Use iterator_traits<It>::value_type and ++first until first==last.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

Iterator-based functions work across containers. list iterators support increment but not subtraction or indexing, so this task exposes hidden random-access assumptions.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

Iterator-based functions work across containers. list iterators support increment but not subtraction or indexing, so this task exposes hidden random-access assumptions.

**Complexity:** O(n log d) map comparisons, O(d) entries for d distinct values.

Check it with `python3 later/tools/run.py 14 --reference`. Reference mode never replaces your starter.

</details>
