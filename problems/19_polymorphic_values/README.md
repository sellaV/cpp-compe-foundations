# 19. Virtual methods without dynamic allocation

**Core stage 5: Classes and data structure implementation**

## Learn first

abstract base, override, const references, object lifetime. Read the matching stage in [CONCEPTS.md](../../docs/CONCEPTS.md). No engineering knowledge is required.

## Contract

Implement Shape with virtual double area() const=0 and virtual destructor. Rectangle(w,h) and Square(side) derive directly from Shape; dimensions are caller-guaranteed finite in [0,1000]. total_area(const Shape&,const Shape&) sums areas through the base interface. No new/delete, smart pointers, cloning or heap allocation. Objects can live as local variables.

## Example

```text
Rectangle(2,3),Square(4) -> total_area=22
```

## Work

Implement starter.hpp, then run `python3 tools/run.py 19` from the repository root. Write an approach, trace a small case, and add a test. Explain which data is copied, borrowed or changed.

The TODO exception is only an unfinished-placeholder mechanism, not a concept you must learn or use in your implementation. Implement the error/result behavior in the contract. Algorithms that the contract prohibits must not be used even if tests pass.

<details>
<summary>Hint: approach</summary>

A reference to base can refer to a local derived object. virtual selects the derived implementation.

</details>

<details>
<summary>Reasoning and solution — after attempting</summary>

Dynamic dispatch does not require dynamic allocation. This separates inheritance from learning smart-pointer APIs.

Read [solution.hpp](solution.hpp). **Complexity:** O(1) time and space.

`python3 tools/run.py 19 --reference` tests the reference without modifying your work.

</details>
