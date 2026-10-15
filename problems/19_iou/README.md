# 19. Intersection over union of boxes

**Core** · 5 · Computer vision foundations

## C++ you will practice

struct, const reference, geometry, floating point.

## Problem

Define Box{x1,y1,x2,y2} with double coordinates and x1<=x2,y1<=y2. Boxes use continuous coordinates (no +1 pixel convention). Return intersection area / union area; if union==0 return 0. Degenerate boxes valid; malformed or nonfinite coordinates throw invalid_argument. Coordinate absolute value<=10^6.

## Example

```text
iou({0,0,2,2},{1,1,3,3}) -> 1/7
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 19
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Intersection width is max(0,min(right edges)-max(left edges)).

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

Clamping intersection dimensions handles disjoint and merely touching boxes. Union subtracts overlap once. A shared geometric convention is essential when comparing model boxes.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

Clamping intersection dimensions handles disjoint and merely touching boxes. Union subtracts overlap once. A shared geometric convention is essential when comparing model boxes.

**Complexity:** O(1) time and space.

Check the reference independently with `python tools/run.py 19 --reference`.
Reference mode does not change your starter file.

</details>
