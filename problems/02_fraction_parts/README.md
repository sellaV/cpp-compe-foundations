# 02. Normalize a fraction with your own GCD loop

**Core stage 1: State, loops, functions and references**

## Learn first

long long, modulo, while loops, structs, status results. Read the matching stage in [CONCEPTS.md](../../docs/CONCEPTS.md). No engineering knowledge is required.

## Contract

Return FractionParts{valid,numerator,denominator} reduced to lowest terms, denominator positive; zero becomes 0/1. For d==0 return {false,0,1}. Inputs |n|,|d|<=10^9. Implement Euclid GCD yourself; no gcd, abs, exceptions or optional.

## Example

```text
normalize_fraction(6,-8) -> {true,-3,4}
```

## Work

Implement starter.hpp, then run `python3 tools/run.py 02` from the repository root. Write an approach, trace a small case, and add a test. Explain which data is copied, borrowed or changed.

The TODO exception is only an unfinished-placeholder mechanism, not a concept you must learn or use in your implementation. Implement the error/result behavior in the contract. Algorithms that the contract prohibits must not be used even if tests pass.

<details>
<summary>Hint: approach</summary>

Normalize the sign, then repeatedly replace (a,b) with (b,a%b) until b is zero.

</details>

<details>
<summary>Reasoning and solution — after attempting</summary>

A separate valid flag reports failure without special library types. long long safely contains all arithmetic under these bounds.

Read [solution.hpp](solution.hpp). **Complexity:** O(log(max(|n|,|d|))) time, O(1) space.

`python3 tools/run.py 02 --reference` tests the reference without modifying your work.

</details>
