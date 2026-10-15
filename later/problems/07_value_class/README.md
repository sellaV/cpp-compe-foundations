# 07. A normalized fraction value class

**Later track: standard-library tools**

## Learn before solving

constructors, private invariants, const methods, operator overloading. Read the matching section in [CONCEPTS.md](../../../docs/LIBRARIES.md).
This is a later-track exercise; first study the related core language concept.

## Contract

Implement Fraction(n,d=1), numerator() const, denominator() const, operator+ and operator==. Store a reduced fraction with positive denominator; zero=0/1; d==0 throws invalid_argument. Inputs |n|,|d|<=10^6; tests make one addition between constructed fractions, so int64_t intermediates fit. Equality must compare values. operator+ must not mutate either operand.

## Example

```text
Fraction(1,2)+Fraction(1,3) == Fraction(5,6)
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 later/tools/run.py 07` from the repository root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Normalize in the constructor so every operation can rely on the invariant. Use int64_t fields.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

A value type owns its data and copies independently. Constructor validation makes invalid states unrepresentable through the public API. const methods permit use through const objects.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

A value type owns its data and copies independently. Constructor validation makes invalid states unrepresentable through the public API. const methods permit use through const objects.

**Complexity:** O(log M) arithmetic time for normalization, O(1) storage.

Check it with `python3 later/tools/run.py 07 --reference`. Reference mode never replaces your starter.

</details>
