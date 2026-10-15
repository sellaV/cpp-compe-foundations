# 10. First nonrepeating byte

**Stage 3: General problem-solving patterns**

## Learn before solving

array, unsigned char conversion, two passes. Read the matching section in [CONCEPTS.md](../../docs/CONCEPTS.md).
No engineering or machine-learning knowledge is needed.

## Contract

Return index of first byte occurring exactly once, or nullopt. Treat string as bytes, not Unicode characters. All 256 byte values allowed; n<=100000.

## Example

```text
first_unique("swiss") -> 1
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 tools/run.py 10` from the repo root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Count byte frequencies, then scan original order. Cast char to unsigned char before using it as an index.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

char may be signed. A negative array index is invalid; explicit unsigned conversion preserves the underlying byte value. A frequency table loses ordering, so scan the input again.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

char may be signed. A negative array index is invalid; explicit unsigned conversion preserves the underlying byte value. A frequency table loses ordering, so scan the input again.

**Complexity:** O(n+256) time, O(256) space.

Check it with `python3 tools/run.py 10 --reference`. Reference mode never replaces your starter.

</details>
