# 18. Restore stream formatting with RAII

**Later track: standard-library tools**

## Learn before solving

destructor, references, deleted special members, exception unwinding. Read the matching section in [CONCEPTS.md](../../../docs/LIBRARIES.md).
This is a later-track exercise; first study the related core language concept.

## Contract

FormatGuard(ostream&) saves flags and precision; destructor restores both, including during exception unwinding. It must neither copy nor move. Stream must outlive guard; do not modify exception masks. Guard itself does not change formatting; code inside scope may do so. Nested guards restore each enclosing state. Standard streams/default exception masks.

## Example

```text
save precision 6; inner scope changes to 2; leaving scope restores 6
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 later/tools/run.py 18` from the repository root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Store a reference plus snapshots of flags and precision. Restore in the destructor, not only in normal code paths.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

RAII applies to restoring state as well as releasing memory. Stack unwinding destroys local objects after an exception; a guard prevents forgotten cleanup on early exits. It cannot extend the borrowed stream lifetime.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

RAII applies to restoring state as well as releasing memory. Stack unwinding destroys local objects after an exception; a guard prevents forgotten cleanup on early exits. It cannot extend the borrowed stream lifetime.

**Complexity:** O(1) time and space.

Check it with `python3 later/tools/run.py 18 --reference`. Reference mode never replaces your starter.

</details>
