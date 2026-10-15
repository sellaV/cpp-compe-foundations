# 08. Validate nested brackets

**Stage 2: Strings, vectors and invariants**

## Learn before solving

stack pattern with vector, char branching. Read the matching section in [CONCEPTS.md](../../docs/CONCEPTS.md).
No engineering or machine-learning knowledge is needed.

## Contract

A string contains only ()[]{}. Return true if brackets are correctly nested and matched; empty is valid. Do not assume equal counts imply valid nesting. n<=100000.

## Example

```text
"{[()]}" -> true; "([)]" -> false
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 tools/run.py 08` from the repo root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

The most recent unmatched opening bracket must match the next closing bracket.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

A LIFO stack models nesting. Check emptiness before back() or pop_back(); accessing an empty vector is undefined behavior.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

A LIFO stack models nesting. Check emptiness before back() or pop_back(); accessing an empty vector is undefined behavior.

**Complexity:** O(n) time, O(n) space.

Check it with `python3 tools/run.py 08 --reference`. Reference mode never replaces your starter.

</details>
