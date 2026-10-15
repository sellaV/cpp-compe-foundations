# 20. Greedy non-maximum suppression

**Stretch** · 5 · Computer vision foundations

## C++ you will practice

sorting index vectors, tie-breaking, nested comparisons, reuse of helpers.

## Problem

Given Box vector and equally sized finite scores, return kept original indices in descending score order. Ties use lower original index. Suppress a candidate when its IoU with ANY previously kept box is strictly greater than threshold. Threshold finite in [0,1]. Box contract matches problem 19; malformed input throws invalid_argument. n<=2,000. Reuse iou from problem 19.

## Example

```text
identical boxes with scores {0.8,0.9}, threshold 0.5 -> {1}
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 20
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Sort indices instead of boxes, preserving the identity of each detection.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

NMS keeps the highest-scoring representative and discards competing overlaps. It does not average or merge boxes. Comparing only with the last kept box misses overlaps with earlier kept detections.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

NMS keeps the highest-scoring representative and discards competing overlaps. It does not average or merge boxes. Comparing only with the last kept box misses overlaps with earlier kept detections.

**Complexity:** O(n²) worst-case time; O(n) extra space.

Check the reference independently with `python tools/run.py 20 --reference`.
Reference mode does not change your starter file.

</details>
