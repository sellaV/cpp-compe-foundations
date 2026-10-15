# 08. Modify a hardware status register

**Core** · 2 · Arrays, algorithms and bit logic

## C++ you will practice

uint32_t, bitwise OR/AND/NOT, shifts, unsigned literals.

## Problem

Return a uint32_t register with bit index set or cleared according to enabled. Other bits must remain unchanged. Valid index is 0..31; index>=32 throws out_of_range. Do not use arithmetic addition to set a bit.

## Example

```text
write_bit(0b1010,0,true) -> 0b1011
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 08
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Build a mask with an unsigned 1. Clearing requires AND with the inverted mask.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

OR is idempotent: setting an already-set bit does not carry into neighboring bits. Validate the shift count before shifting. uint32_t expresses register width explicitly.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

OR is idempotent: setting an already-set bit does not carry into neighboring bits. Validate the shift count before shifting. uint32_t expresses register width explicitly.

**Complexity:** O(1) time and space.

Check the reference independently with `python tools/run.py 08 --reference`.
Reference mode does not change your starter file.

</details>
