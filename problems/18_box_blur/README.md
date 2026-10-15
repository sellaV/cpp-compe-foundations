# 18. 3x3 box blur with explicit border behavior

**Core** · 5 · Computer vision foundations

## C++ you will practice

nested loops, accumulation, casts, numeric output.

## Problem

Return a grayscale vector<double> of the same width*height as image. Average valid pixels in the centered 3x3 neighborhood, excluding pixels outside the image; border divisor therefore varies. Require nonnegative dimensions and exactly width*height input pixels, else invalid_argument. Zero-area image returns empty. Dimensions<=1000; pixels 0..255.

## Example

```text
blur3({1,2,3,4},2,2) -> {2.5,2.5,2.5,2.5}
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 18
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

For each output, accumulate neighboring in-bounds values and count how many were included.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

The output uses doubles to preserve fractional averages. Border policy is part of the algorithm contract; this policy differs from zero padding and edge replication.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

The output uses doubles to preserve fractional averages. Border policy is part of the algorithm contract; this policy differs from zero padding and edge replication.

**Complexity:** O(width*height) time for fixed 3x3 kernel; O(width*height) output.

Check the reference independently with `python tools/run.py 18 --reference`.
Reference mode does not change your starter file.

</details>
