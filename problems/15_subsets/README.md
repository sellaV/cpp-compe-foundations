# 15. Generate a power set recursively

**Stage 4: Pointers, ownership and recursion**

## Learn before solving

recursion, backtracking, vector copying versus references. Read the matching section in [CONCEPTS.md](../../docs/CONCEPTS.md).
No engineering or machine-learning knowledge is needed.

## Contract

Return every subset of a vector of DISTINCT ints. Preserve input order within each subset; output order is unrestricted. Empty input has one subset: empty. n<=16. Use recursion/backtracking; no bit-mask enumeration.

## Example

```text
subsets({1,2}) -> {}, {1}, {2}, {1,2} (any outer order)
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 tools/run.py 15` from the repo root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

At each position, recurse without the value, then with it. Undo your push after the second branch.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

Each recursive level makes a binary choice. The current subset is shared mutable state; output.push_back(current) copies a snapshot before backtracking mutates it.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

Each recursive level makes a binary choice. The current subset is shared mutable state; output.push_back(current) copies a snapshot before backtracking mutates it.

**Complexity:** O(n*2^n) time/output space, O(n) recursion depth and working subset.

Check it with `python3 tools/run.py 15 --reference`. Reference mode never replaces your starter.

</details>
