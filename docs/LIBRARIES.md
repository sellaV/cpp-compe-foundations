# Libraries after the core ideas

Start this guide after the 20 core exercises, or selectively when you can already explain the relevant core concept. All commands here are run from the repository root.

The distinction is about learning order, not a ban on libraries. vector/string are already library types used as practical storage. Now introduce algorithms, containers and ownership abstractions deliberately.

## 1. Replace familiar manual operations

| Later exercise | Tool | Compare with core |
| --- | --- | --- |
| 01 | optional<int> | A bool flag plus a stored int in core 01 |
| 02 | std::gcd and exceptions | Euclid loop and status result in core 02 |
| 03 | std::reverse and iterators | Manual indexed reversal in core 06 |
| 04 | unordered_map, pair and optional | Nested candidate loops in core 11 |
| 05 | std::array and sliding windows | Built-in frequency arrays and sequence scans |

optional has two states: it contains a value, or it does not. `if (answer)` checks presence, not whether the contained number is nonzero. `*answer` reads the contained value after checking presence. nullopt represents absence. This packages the state you previously maintained explicitly.

Standard algorithms usually accept a half-open iterator range [begin,end). end is just after the last element; do not dereference it. A hash map can improve average lookup complexity, but you still need to understand its key, ordering, memory and invalidation behavior.

## 2. Ownership and class design

Later 06–10 cover an owned linked list, value operators, a map-backed inventory, polymorphic cloning and a move-only buffer.

A raw pointer alone says neither who owns the object nor how long it lives. unique_ptr owns one object exclusively and releases it when destroyed. make_unique creates an owner; get provides a non-owning observing pointer. std::move enables a move operation; it does not itself promise that every moved-from type becomes empty. unique_ptr does become empty after ownership transfer; a custom class needs its own stated moved-from contract.

Copying into a base value can slice a derived object. A virtual clone can preserve the dynamic type. Compare that with core 19, which only borrows local objects through base references.

## 3. STL algorithms and generic code

Later 11–14 cover callables, lambdas, canonical-key grouping, stable sorting and iterator-based templates.

A lambda is a small callable such as `[](int x) { return x*2; }`. A template parameterizes code by type. Neither requires abandoning compile-time type checking.

In a sort comparator, true means the first value should come strictly before the second. Use > for descending order, not >=. Iterator interfaces should not assume random access unless their contract requires it: list iterators cannot be subtracted like vector iterators.

Study decltype, decay_t and iterator_traits only when their exercises require them. They describe types for reusable code, not the core logic of an early loop.

## 4. Streams, error handling and RAII

Later 15–18 cover strict token parsing, text statistics, variant and a formatting guard.

istream/ostream let the same algorithm work with stringstreams and file streams. Read by testing extraction success, not by predicting the next read from eof(). from_chars reports both a conversion status and where parsing stopped.

Exceptions and status results are API choices; follow the specified contract. variant stores one of several known types. RAII ties cleanup to object lifetime: a destructor restores state or releases a resource on both normal scope exit and exception unwinding. This is important general C++ knowledge even when your career does not center on algorithm puzzles.

## Suggested pace

Do the first four comparisons, then choose one ownership task, one container/algorithm task and one stream task. Return to generic code as your needs grow. You do not need to solve every duplicate problem immediately, but do learn lifetime, error handling and resource management before relying on complex APIs.

```bash
python3 later/tools/run.py --list
python3 later/tools/run.py 01
```
