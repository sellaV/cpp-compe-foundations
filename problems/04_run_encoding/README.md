# 04. Encode consecutive character runs

**Core stage 1: language and manual logic**

## Learn before solving

string, struct, vector, size_t, range loops. Read the matching stage in [CONCEPTS.md](../../docs/CONCEPTS.md).
No engineering or machine-learning knowledge is needed.

## Contract

Define Run{char value; size_t count;}. encode_runs(string const&) returns one Run per maximal consecutive block of equal bytes. Case-sensitive, includes spaces, empty input gives empty. n<=100000.

## Example

```text
encode_runs("aaabbA") -> {{a,3},{b,2},{A,1}}
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 tools/run.py 04` from the repo root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Extend the last run when the byte matches; otherwise start a new run.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

This is grouping adjacent elements, not counting every occurrence across the string. The vector owns the output, so it remains valid after input destruction.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

This is grouping adjacent elements, not counting every occurrence across the string. The vector owns the output, so it remains valid after input destruction.

**Complexity:** O(n) time, O(n) output.

Check it with `python3 tools/run.py 04 --reference`. Reference mode never replaces your starter.

</details>
