# 18. An inventory with checked updates

**Stage 5: Classes, value semantics and polymorphism**

## Learn before solving

encapsulation, map, exceptions, transactional updates. Read the matching section in [CONCEPTS.md](../../docs/CONCEPTS.md).
No engineering or machine-learning knowledge is needed.

## Contract

Inventory: add(string name,int quantity), remove(string const&,int quantity)->bool, count(string const&) const->int. Initially empty. Empty name or quantity<=0 throws invalid_argument. add increases count; overflow beyond INT_MAX throws overflow_error without mutation. remove returns false without mutation for absent/insufficient stock, otherwise subtracts. Zero stock reads as 0. Copies must be independent.

## Example

```text
add("book",3); remove("book",4) -> false, count remains 3
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 tools/run.py 18` from the repo root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Validate arguments and check arithmetic before changing the map. A const lookup must not insert missing keys.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

Encapsulation centralizes the nonnegative-stock invariant. Test state after failures, not just the exception. A std::map member naturally provides independent value semantics (Rule of Zero).

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

Encapsulation centralizes the nonnegative-stock invariant. Test state after failures, not just the exception. A std::map member naturally provides independent value semantics (Rule of Zero).

**Complexity:** O(log n) map operations excluding string comparison costs; O(n) stored entries.

Check it with `python3 tools/run.py 18 --reference`. Reference mode never replaces your starter.

</details>
