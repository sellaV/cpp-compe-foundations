# 03. Rotate three caller-owned values

**Stage 1: Functions, types and references**

## Learn before solving

reference parameters, temporaries, aliasing. Read the matching section in [CONCEPTS.md](../../docs/CONCEPTS.md).
No engineering or machine-learning knowledge is needed.

## Contract

rotate_values(a,b,c) changes the referenced objects so their new values are old c, old a, old b. a,b,c must refer to three DISTINCT int objects. Document why aliasing would make the contract ambiguous. No pointers or std::swap.

## Example

```text
a=1,b=2,c=3 -> a=3,b=1,c=2
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 tools/run.py 03` from the repo root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Save a value before overwriting its object. Parameters passed by value would not change the caller.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

A reference aliases the original object. A local temporary holds a snapshot, so writes do not destroy a value still needed by a later assignment.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

A reference aliases the original object. A local temporary holds a snapshot, so writes do not destroy a value still needed by a later assignment.

**Complexity:** O(1) time and space.

Check it with `python3 tools/run.py 03 --reference`. Reference mode never replaces your starter.

</details>
