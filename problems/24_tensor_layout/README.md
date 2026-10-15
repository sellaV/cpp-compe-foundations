# 24. Convert HWC pixels to normalized CHW tensor

**Stretch** · 6 · Edge AI and numerical thinking

## C++ you will practice

uint8_t, float, tensor indexing, explicit casts, layout conversion.

## Problem

Input is interleaved HWC RGB bytes of shape height*width*3. Return normalized CHW vector<float> of shape 3*height*width, with each byte divided by 255.0f. Do not change RGB channel order or resize. Dimensions nonnegative and <=1000; exact buffer size required, else invalid_argument. Zero-area input valid.

## Example

```text
to_chw({255,0,128,0,255,64},1,2) -> {1,0,0,1,128/255,64/255}
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 24
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Input index is (r*width+c)*3+channel; output is channel*(height*width)+r*width+c.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

Layout conversion changes where values live, not what color each channel means. Floating-point division scales pixels to [0,1]; integer division would destroy almost all values. This is the flat equivalent of transpose(2,0,1) followed by normalization.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

Layout conversion changes where values live, not what color each channel means. Floating-point division scales pixels to [0,1]; integer division would destroy almost all values. This is the flat equivalent of transpose(2,0,1) followed by normalization.

**Complexity:** O(height*width) time; O(height*width) output storage.

Check the reference independently with `python tools/run.py 24 --reference`.
Reference mode does not change your starter file.

</details>
