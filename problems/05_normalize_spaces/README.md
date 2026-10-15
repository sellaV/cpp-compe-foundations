# 05. Normalize whitespace between words

**Core stage 2: language and manual logic**

## Learn before solving

const string reference, ASCII predicates, string building. Read the matching stage in [CONCEPTS.md](../../docs/CONCEPTS.md).
No engineering or machine-learning knowledge is needed.

## Contract

Trim leading/trailing ASCII whitespace and replace every internal whitespace run with one ordinary space. Whitespace is exactly space, tab, newline, carriage return, form feed, vertical tab. Other bytes are unchanged. Return owning string. n<=100000.

## Example

```text
normalize_spaces("  one\ttwo  ") -> "one two"
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 tools/run.py 05` from the repo root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Delay inserting a space until another non-whitespace character actually appears.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

const string reference borrows input, while the result owns its bytes. A pending separator avoids accidentally emitting a trailing space. Explicit ASCII rules avoid locale and signed-char pitfalls.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

const string reference borrows input, while the result owns its bytes. A pending separator avoids accidentally emitting a trailing space. Explicit ASCII rules avoid locale and signed-char pitfalls.

**Complexity:** O(n) time, O(n) output.

Check it with `python3 tools/run.py 05 --reference`. Reference mode never replaces your starter.

</details>
