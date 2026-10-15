# 09. Clone polymorphic objects

**Later track: standard-library tools**

## Learn before solving

abstract base, virtual destructor, override, unique_ptr, dynamic dispatch. Read the matching section in [CONCEPTS.md](../../../docs/LIBRARIES.md).
This is a later-track exercise; first study the related core language concept.

## Contract

Base Shape exposes virtual area() const->double, clone() const->unique_ptr<Shape>, virtual destructor. Implement Rectangle(width,height) and Square(side) deriving DIRECTLY from Shape; dimensions finite>=0 else invalid_argument. clone returns an independently owned object preserving dynamic type and area. Values<=1000. No slicing or raw owning pointers.

## Example

```text
unique_ptr<Shape> holding Rectangle(2,3): area()==6, clone area()==6
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 later/tools/run.py 09` from the repository root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Use override and make_unique<Derived>(*this) for each clone. A base pointer needs a virtual destructor.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

Virtual calls select behavior through the dynamic type. Copying into a base value slices derived state; cloning through a virtual method preserves it. unique_ptr controls destruction of heterogeneous objects.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

Virtual calls select behavior through the dynamic type. Copying into a base value slices derived state; cloning through a virtual method preserves it. unique_ptr controls destruction of heterogeneous objects.

**Complexity:** O(1) per operation, O(1) allocation for a clone.

Check it with `python3 later/tools/run.py 09 --reference`. Reference mode never replaces your starter.

</details>
