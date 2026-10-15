# 20. Build a fixed-capacity queue class

**Core stage 5: Classes and data structure implementation**

## Learn first

built-in member arrays, circular indices, state invariants. Read the matching stage in [CONCEPTS.md](../../docs/CONCEPTS.md). No engineering knowledge is required.

## Contract

FixedQueue has capacity exactly 8 ints, initially empty. push(int)->bool rejects a full queue without changing it. pop(int& output)->bool returns/removes oldest value; empty returns false leaving output unchanged. size() const->int. No vector/deque/queue, templates, allocation, algorithms or exceptions. Implement with a member int array and indices. Copies independent.

## Example

```text
push 1,2; pop -> 1; pop -> 2; empty pop -> false
```

## Work

Implement starter.hpp, then run `python3 tools/run.py 20` from the repository root. Write an approach, trace a small case, and add a test. Explain which data is copied, borrowed or changed.

The TODO exception is only an unfinished-placeholder mechanism, not a concept you must learn or use in your implementation. Implement the error/result behavior in the contract. Algorithms that the contract prohibits must not be used even if tests pass.

<details>
<summary>Hint: approach</summary>

Track head and count. Insertion slot is (head+count)%8; head advances when popping.

</details>

<details>
<summary>Reasoning and solution — after attempting</summary>

The array owns its elements as part of the class. A circular layout makes FIFO operations constant-time without shifting storage.

Read [solution.hpp](solution.hpp). **Complexity:** O(1) per operation; O(1) fixed storage.

`python3 tools/run.py 20 --reference` tests the reference without modifying your work.

</details>
