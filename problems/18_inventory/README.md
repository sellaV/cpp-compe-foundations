# 18. Inventory using a vector of records

**Core stage 5: Classes and data structure implementation**

## Learn first

classes, vector of structs, linear lookup, checked updates. Read the matching stage in [CONCEPTS.md](../../docs/CONCEPTS.md). No engineering knowledge is required.

## Contract

Inventory initially empty. add(name,quantity)->bool; remove(name,quantity)->bool; count(name) const->int. Empty name, quantity<=0, or adding beyond 1000000 total units for an item returns false without mutation. Insufficient/absent remove returns false without mutation. Successful updates return true. Copies independent. At most 1000 names. No map/unordered_map, exceptions, or library search.

## Example

```text
add("book",3) -> true; remove("book",4) -> false; count("book") remains 3
```

## Work

Implement starter.hpp, then run `python3 tools/run.py 18` from the repository root. Write an approach, trace a small case, and add a test. Explain which data is copied, borrowed or changed.

The TODO exception is only an unfinished-placeholder mechanism, not a concept you must learn or use in your implementation. Implement the error/result behavior in the contract. Algorithms that the contract prohibits must not be used even if tests pass.

<details>
<summary>Hint: approach</summary>

Store records in a vector and scan for a matching name. Check the requested operation before changing stock.

</details>

<details>
<summary>Reasoning and solution — after attempting</summary>

You can learn encapsulation and error handling without learning associative containers at the same time. The later version swaps linear lookup for a map.

Read [solution.hpp](solution.hpp). **Complexity:** O(n) lookup/update; O(n) stored records.

`python3 tools/run.py 18 --reference` tests the reference without modifying your work.

</details>
