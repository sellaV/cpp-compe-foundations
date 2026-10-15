# 02. Longest consecutive alarm

**Warm-up** · 1 · Core logic and C++ syntax

## C++ you will practice

size_t, counters, loop invariants.

## Problem

Return the longest contiguous run of samples strictly greater than threshold. Empty input returns 0. Equal-to-threshold samples break a run. Up to 100,000 int samples.

## Example

```text
longest_alarm({1,7,8,2,9}, 5) -> 2
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 02
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Keep the length of the run ending at the current sample and a separate best length.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

After each sample, current is exactly the length of the suffix above threshold. Reset it on a non-alarm, then update best. Consecutive means adjacent, so counting all alarms is wrong.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

After each sample, current is exactly the length of the suffix above threshold. Reset it on a non-alarm, then update best. Consecutive means adjacent, so counting all alarms is wrong.

**Complexity:** O(n) time; O(1) extra space.

Check the reference independently with `python tools/run.py 02 --reference`.
Reference mode does not change your starter file.

</details>
