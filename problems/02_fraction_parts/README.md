# 02. Normalize fraction data

**Stage 1: Functions, types and references**

## Learn before solving

struct, int64_t, gcd, exceptions, return by value. Read the matching section in [CONCEPTS.md](../../docs/CONCEPTS.md).
No engineering or machine-learning knowledge is needed.

## Contract

Define FractionParts{int64_t numerator,denominator}. normalize_fraction(n,d) returns an equivalent fraction reduced to lowest terms with positive denominator; zero becomes 0/1. d==0 throws invalid_argument. |n|,|d|<=10^9.

## Example

```text
normalize_fraction(6,-8) -> {-3,4}
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 tools/run.py 02` from the repo root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Move the sign to the numerator, then divide both fields by their greatest common divisor.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

The struct gives the return values names. Validating before division distinguishes a domain error from ordinary arithmetic. The constraints make negation safe in int64_t.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

The struct gives the return values names. Validating before division distinguishes a domain error from ordinary arithmetic. The constraints make negation safe in int64_t.

**Complexity:** O(log(max(|n|,|d|))) time, O(1) space.

Check it with `python3 tools/run.py 02 --reference`. Reference mode never replaces your starter.

</details>
