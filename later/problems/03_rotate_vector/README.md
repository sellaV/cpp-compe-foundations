# 03. Rotate a vector in place

**Later track: standard-library tools**

## Learn before solving

mutable reference, iterators, reverse, modulo. Read the matching section in [CONCEPTS.md](../../../docs/LIBRARIES.md).
This is a later-track exercise; first study the related core language concept.

## Contract

Rotate vector<int> right by k positions in place. k is size_t and may exceed n. Empty vector is valid. Use O(1) auxiliary space; std::reverse is allowed but std::rotate is not. n<=100000.

## Example

```text
{1,2,3,4,5}, k=2 -> {4,5,1,2,3}
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 later/tools/run.py 03` from the repository root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Reduce k modulo n only after checking for empty input. Three reversals suffice.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

A mutable reference changes the caller. Reversing the whole sequence puts the desired suffix first but reverses its order; reverse each resulting segment to restore internal order.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

A mutable reference changes the caller. Reversing the whole sequence puts the desired suffix first but reverses its order; reverse each resulting segment to restore internal order.

**Complexity:** O(n) time, O(1) extra space.

Check it with `python3 later/tools/run.py 03 --reference`. Reference mode never replaces your starter.

</details>
