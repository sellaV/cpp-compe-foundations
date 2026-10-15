# 17. Crop a flattened grayscale image

**Core** · 5 · Computer vision foundations

## C++ you will practice

row-major storage, nested loops, bounds checking.

## Problem

Image is vector<int> of exactly width*height pixels in row-major order. Return a cw*ch crop at (x,y), also row-major. Validate nonnegative dimensions/coordinates and x+cw<=width, y+ch<=height; malformed input throws invalid_argument. Zero-area crops are valid. All dimensions<=1000, pixels are 0..255.

## Example

```text
crop({0,1,2,3,4,5},3,2,1,0,2,2) -> {1,2,4,5}
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 17
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Pixel (row,col) lives at row*width+col. Crop coordinates offset the source row and column.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

Flattened arrays are common at image and tensor interfaces. The crop copies only the requested rectangle; it does not resize or interpolate. Checking metadata prevents out-of-bounds access.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

Flattened arrays are common at image and tensor interfaces. The crop copies only the requested rectangle; it does not resize or interpolate. Checking metadata prevents out-of-bounds access.

**Complexity:** O(cw*ch) time and output space.

Check the reference independently with `python tools/run.py 17 --reference`.
Reference mode does not change your starter file.

</details>
