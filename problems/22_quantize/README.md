# 22. Quantize floating-point samples to int8

**Core** · 6 · Edge AI and numerical thinking

## C++ you will practice

round, clamp, int8_t, numeric limits, narrowing conversions.

## Problem

Return q=clamp(round(x/scale)+zero_point,-128,127) for each sample. round means halfway away from zero. scale finite>0; zero_point in [-128,127]; samples finite and |x/scale|<=10^9. Invalid scale, zero_point or nonfinite samples throw invalid_argument. Return vector<int8_t>; empty valid.

## Example

```text
quantize({-1.0,0.0,1.0},0.5,0) -> {-2,0,2}
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 22
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Round and clamp in double before casting to int8_t.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

Quantization trades resolution and range for compact representation. Narrowing first can lose the intended saturated result. When printing int8_t, cast to int because it is often a character type.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

Quantization trades resolution and range for compact representation. Narrowing first can lose the intended saturated result. When printing int8_t, cast to int because it is often a character type.

**Complexity:** O(n) time; O(n) output storage.

Check the reference independently with `python tools/run.py 22 --reference`.
Reference mode does not change your starter file.

</details>
