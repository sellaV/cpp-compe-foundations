# 16. Return a pointer to the first maximum

**Stage 4: Pointers, ownership and recursion**

## Learn before solving

const and mutable overloads, pointer return, lifetime. Read the matching section in [CONCEPTS.md](../../docs/CONCEPTS.md).
No engineering or machine-learning knowledge is needed.

## Contract

Implement BOTH overloads max_element_ptr(int*,size_t)->int* and max_element_ptr(const int*,size_t)->const int*. Return pointer to first maximum, or nullptr for n==0. Null with n>0 throws invalid_argument. Caller supplies a live array; result must point into it and must not outlive it. Do not allocate or copy input.

## Example

```text
{2,7,7} -> pointer to index 1; writing through mutable result changes input
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 tools/run.py 16` from the repo root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Use an overloaded helper template internally, or implement two straightforward scans. Pointer constness follows the input.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

A returned pointer can identify and mutate the actual caller element. It owns nothing. Returning the address of a local maximum value would dangle, even if that value is numerically correct.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

A returned pointer can identify and mutate the actual caller element. It owns nothing. Returning the address of a local maximum value would dangle, even if that value is numerically correct.

**Complexity:** O(n) time, O(1) space.

Check it with `python3 tools/run.py 16 --reference`. Reference mode never replaces your starter.

</details>
