# 11. Traverse an owned command chain

**Core** · 3 · Classes, lifetimes and generic C++

## C++ you will practice

unique_ptr, raw observing pointers, nullptr, make_unique, ownership.

## Problem

Define Node with int value and unique_ptr<Node> next. Implement chain_values(const Node*) returning values in order without changing ownership. A null head returns empty. The supplied chain is acyclic and has at most 1,000 nodes. Do not copy unique_ptr or release ownership.

## Example

```text
7 -> 2 -> 9 -> null gives {7,2,9}
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 11
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

The argument is a non-owning pointer. Move forward using node->next.get().

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

unique_ptr expresses one owner and destroys the node it owns automatically. get() observes without transferring ownership. The const Node* prevents mutation through the traversal pointer. Iterative traversal avoids recursive call overhead; destruction of this simple linked ownership chain is still recursive.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

unique_ptr expresses one owner and destroys the node it owns automatically. get() observes without transferring ownership. The const Node* prevents mutation through the traversal pointer. Iterative traversal avoids recursive call overhead; destruction of this simple linked ownership chain is still recursive.

**Complexity:** O(n) time; O(n) output and O(1) auxiliary space.

Check the reference independently with `python tools/run.py 11 --reference`.
Reference mode does not change your starter file.

</details>
