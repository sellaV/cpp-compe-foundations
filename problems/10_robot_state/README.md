# 10. Latched emergency-stop state machine

**Core** · 3 · Classes, lifetimes and generic C++

## C++ you will practice

enum class, class encapsulation, switch, methods.

## Problem

Implement Controller, initially State::Idle. Events: Start turns Idle->Running; Stop turns Running->Idle; Fault turns any state->Emergency; Reset turns Emergency->Idle. Every other combination leaves state unchanged. Emergency is latched: Start cannot escape it. Provide handle(Event) and state() const.

## Example

```text
Start, Fault, Start -> Emergency; Reset -> Idle
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 10
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Define scoped enums State{Idle,Running,Emergency} and Event{Start,Stop,Fault,Reset}. Handle Fault before normal transitions.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

A state machine makes allowed transitions explicit. Keep state private so callers cannot bypass the emergency latch. This is a simulation exercise, not a safety-certified controller.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

A state machine makes allowed transitions explicit. Keep state private so callers cannot bypass the emergency latch. This is a simulation exercise, not a safety-certified controller.

**Complexity:** O(1) time and space per event.

Check the reference independently with `python tools/run.py 10 --reference`.
Reference mode does not change your starter file.

</details>
