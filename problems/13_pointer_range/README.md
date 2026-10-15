# 13. Reverse a borrowed array range

**Stage 4: Pointers, ownership and recursion**

## Learn before solving

raw observing pointers, pointer arithmetic, nullptr. Read the matching section in [CONCEPTS.md](../../docs/CONCEPTS.md).
No engineering or machine-learning knowledge is needed.

## Contract

reverse_range(int* data,size_t n) reverses n elements in place. If n>0, data must point to a writable array of at least n elements; null with n>0 throws invalid_argument. n==0 accepts nullptr without pointer arithmetic. Do not allocate, delete, or call std::reverse. n<=100000.

## Example

```text
array {1,2,3,4} -> {4,3,2,1}
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 tools/run.py 13` from the repo root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Treat data as borrowed. Use symmetric indices while i<n/2.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

A raw pointer does not encode array length or ownership. The caller guarantees lifetime and size; the function can validate null but cannot discover whether a non-null pointer is dangling.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

A raw pointer does not encode array length or ownership. The caller guarantees lifetime and size; the function can validate null but cannot discover whether a non-null pointer is dangling.

**Complexity:** O(n) time, O(1) space.

Check it with `python3 tools/run.py 13 --reference`. Reference mode never replaces your starter.

</details>
