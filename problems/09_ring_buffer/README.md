# 09. Fixed-capacity telemetry buffer

**Stretch** · 3 · Classes, lifetimes and generic C++

## C++ you will practice

class, constructor, private state, template, optional, circular indexing.

## Problem

Implement RingBuffer<T> with positive runtime capacity, push(const T&), pop()->optional<T>, and size() const. On full push overwrite the oldest item. Pop is FIFO; empty pop returns nullopt. Capacity 0 throws invalid_argument. T is copyable; operations need not be exception-safe for a T whose copy throws. Capacity<=100,000.

## Example

```text
capacity 2; push 1,2,3; pop -> 2; pop -> 3; pop -> nullopt
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 09
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Track the next oldest slot and a count. Store optional<T> slots so T need not have a default constructor.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

The logical queue wraps around a fixed vector. When full, writing at head replaces the oldest and advances head. Otherwise write at (head+count)%capacity. optional owns a value only when engaged.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

The logical queue wraps around a fixed vector. When full, writing at head replaces the oldest and advances head. Otherwise write at (head+count)%capacity. optional owns a value only when engaged.

**Complexity:** O(1) per push/pop for fixed-cost T copies; O(capacity) storage.

Check the reference independently with `python tools/run.py 09 --reference`.
Reference mode does not change your starter file.

</details>
