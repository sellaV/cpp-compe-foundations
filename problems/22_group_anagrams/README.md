# 22. Group words by a canonical key

**Stage 6: STL, callables, templates and iterators**

## Learn before solving

unordered_map, sorting, map key/value separation. Read the matching section in [CONCEPTS.md](../../docs/CONCEPTS.md).
No engineering or machine-learning knowledge is needed.

## Contract

Given lowercase ASCII words (empty allowed), group anagrams. Preserve input order within groups and order groups by first appearance in input. Duplicate words retained. Up to 10000 words, each length<=100.

## Example

```text
{"eat","tea","tan","ate"} -> {{"eat","tea","ate"},{"tan"}}
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 tools/run.py 22` from the repo root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Sorted letters make a canonical key. Map that key to a position in a separate output vector.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

unordered_map iteration order is unspecified, so returning groups directly from its iteration would violate the required order. Keep ordering explicit in a vector.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

unordered_map iteration order is unspecified, so returning groups directly from its iteration would violate the required order. Keep ordering explicit in a vector.

**Complexity:** O(sum L_i log(L_i+1)) key sorting plus expected hash work; O(total characters) storage.

Check it with `python3 tools/run.py 22 --reference`. Reference mode never replaces your starter.

</details>
