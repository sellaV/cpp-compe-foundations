# 04. Parse a telemetry command

**Core** · 1 · Core logic and C++ syntax

## C++ you will practice

string_view, from_chars, optional, error codes.

## Problem

Parse exactly CMD:<signed decimal integer> into optional<int>. No spaces, trailing characters, leading +, or missing digits. Optional leading - and leading zeros are allowed. Out-of-int-range input returns nullopt. Prefix is case-sensitive. Input length <= 100.

## Example

```text
parse_command("CMD:-42") -> -42; parse_command("CMD:4x") -> nullopt
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 04
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Check the prefix, then require both successful conversion and consumption of the entire suffix.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

from_chars does not skip whitespace and reports overflow without exceptions. Checking ptr==end rejects partial parses. string_view borrows the input; it does not allocate or extend its lifetime.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

from_chars does not skip whitespace and reports overflow without exceptions. Checking ptr==end rejects partial parses. string_view borrows the input; it does not allocate or extend its lifetime.

**Complexity:** O(n) time; O(1) space.

Check the reference independently with `python tools/run.py 04 --reference`.
Reference mode does not change your starter file.

</details>
