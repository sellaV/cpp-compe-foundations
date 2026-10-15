# 06. Insert into a uniquely owned linked list

**Later track: standard-library tools**

## Learn before solving

unique_ptr, move, pointer-to-owner, make_unique. Read the matching section in [CONCEPTS.md](../../../docs/LIBRARIES.md).
This is a later-track exercise; first study the related core language concept.

## Contract

Node has int value and unique_ptr<Node> next. insert_sorted(unique_ptr<Node>& head,int value) inserts AFTER any existing equal values into a nondecreasing acyclic list. Must preserve existing node identities and ownership, including caller head updates. No manual new/delete. Initial length<=1000.

## Example

```text
1 -> 3 -> 3; insert 3 gives 1 -> 3 -> 3 -> 3
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 later/tools/run.py 06` from the repository root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Walk through a pointer to the owning unique_ptr, then move the suffix into the new node.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

The link being updated is itself an owner, not just a Node*. std::move transfers that ownership; get() alone cannot reconnect the list. Moving a unique_ptr does not move the node object.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

The link being updated is itself an owner, not just a Node*. std::move transfers that ownership; get() alone cannot reconnect the list. Moving a unique_ptr does not move the node object.

**Complexity:** O(n) time, O(1) auxiliary space plus one allocated node.

Check it with `python3 later/tools/run.py 06 --reference`. Reference mode never replaces your starter.

</details>
