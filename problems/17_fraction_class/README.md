# 17. A fraction class with manual normalization

**Core stage 5: Classes and data structure implementation**

## Learn first

private members, constructors, const methods, operators. Read the matching stage in [CONCEPTS.md](../../docs/CONCEPTS.md). No engineering knowledge is required.

## Contract

Fraction(n,d=1) stores a reduced fraction with positive denominator; zero=0/1. d!=0 is a caller precondition. Provide numerator(), denominator(), operator+ and operator== as const methods. |constructor inputs|<=10^6; tests make one addition, so long long intermediates fit. Write GCD yourself, no numeric algorithms or exceptions.

## Example

```text
Fraction(1,2)+Fraction(1,3)==Fraction(5,6)
```

## Work

Implement starter.hpp, then run `python3 tools/run.py 17` from the repository root. Write an approach, trace a small case, and add a test. Explain which data is copied, borrowed or changed.

The TODO exception is only an unfinished-placeholder mechanism, not a concept you must learn or use in your implementation. Implement the error/result behavior in the contract. Algorithms that the contract prohibits must not be used even if tests pass.

<details>
<summary>Hint: approach</summary>

Put normalization in the constructor so every constructed object satisfies the same invariant.

</details>

<details>
<summary>Reasoning and solution — after attempting</summary>

Class design preserves an invariant; operators operate on values without unexpectedly mutating either operand.

Read [solution.hpp](solution.hpp). **Complexity:** O(log M) normalization, O(1) storage.

`python3 tools/run.py 17 --reference` tests the reference without modifying your work.

</details>
