# 16. A bounded discrete PID controller

**Stretch** · 4 · Robotics and scheduling algorithms

## C++ you will practice

stateful classes, floating point, constructor validation, clamp.

## Problem

Implement PID(kp,ki,kd,limit), step(error,dt), reset(). integral += error*dt; derivative=(error-previous)/dt except first step derivative=0. Clamp output to [-limit,limit]. Integral still accumulates when output saturates (no anti-windup). reset clears history. Finite gains/limit; limit>=0. step requires finite error and finite dt>0; invalid arguments throw invalid_argument before changing state. Inputs/intermediate results remain finite.

## Example

```text
PID(1,1,0,10); step(2,1) -> 4; next step(1,1) -> 4
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 16
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Store integral, previous error and whether a previous sample exists. Validate dt before dividing.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

A class preserves controller history between calls. The first derivative is zero because no earlier measurement exists. Saturation protects the output range but does not by itself solve integral windup; discuss that extension after solving.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

A class preserves controller history between calls. The first derivative is zero because no earlier measurement exists. Saturation protects the output range but does not by itself solve integral windup; discuss that extension after solving.

**Complexity:** O(1) time and space per step.

Check the reference independently with `python tools/run.py 16 --reference`.
Reference mode does not change your starter file.

</details>
