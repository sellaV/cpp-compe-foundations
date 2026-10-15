# 21. Stable softmax for classifier logits

**Core** · 6 · Edge AI and numerical thinking

## C++ you will practice

exp, max_element, accumulate, floating point stability.

## Problem

Return probabilities exp(x_i)/sum(exp(x_j)). Empty logits return empty; nonfinite logits throw invalid_argument. n<=100,000, finite logits in [-10^6,10^6]. Do not directly exponentiate raw logits. Output tests use absolute tolerance 1e-8.

## Example

```text
softmax({1000,1000}) -> {0.5,0.5}
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 21
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Subtract the largest logit before exponentiating. This does not change the normalized result.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

Exponentials of large raw logits overflow. Subtracting the maximum makes every exponent nonpositive and at least one exp equal to 1. Extremely negative differences may underflow to zero, which is acceptable here.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

Exponentials of large raw logits overflow. Subtracting the maximum makes every exponent nonpositive and at least one exp equal to 1. Extremely negative differences may underflow to zero, which is acceptable here.

**Complexity:** O(n) time; O(n) output storage.

Check the reference independently with `python tools/run.py 21 --reference`.
Reference mode does not change your starter file.

</details>
