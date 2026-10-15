# 12. Longest substring without repeated bytes

**Stage 3: General problem-solving patterns**

## Learn before solving

sliding window, array, index invariants. Read the matching section in [CONCEPTS.md](../../docs/CONCEPTS.md).
No engineering or machine-learning knowledge is needed.

## Contract

Return the length of the longest contiguous substring with all distinct bytes. Empty returns 0. All byte values allowed; n<=100000.

## Example

```text
longest_unique("abcabcbb") -> 3
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 tools/run.py 12` from the repo root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Keep the current window start and the position after the last occurrence of each byte.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

The start must never move backward. Using max(start,last_after[c]) preserves distinctness without rescanning every possible substring.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

The start must never move backward. Using max(start,last_after[c]) preserves distinctness without rescanning every possible substring.

**Complexity:** O(n+256) time, O(256) space.

Check it with `python3 tools/run.py 12 --reference`. Reference mode never replaces your starter.

</details>
