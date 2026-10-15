# 16. Backtracking with an ordinary helper function

**Core stage 4: Pointers, lifetime and recursion**

## Learn first

recursion, reference parameters, snapshots, undoing changes. Read the matching stage in [CONCEPTS.md](../../docs/CONCEPTS.md). No engineering knowledge is required.

## Contract

Return all subsets of DISTINCT int values, preserving input order inside each subset; outer order arbitrary. Empty input has one empty subset. n<=16. Use a named recursive helper, not std::function, lambdas, bit masks or library enumeration.

## Example

```text
{1,2} -> {},{1},{2},{1,2} in any outer order
```

## Work

Implement starter.hpp, then run `python3 tools/run.py 16` from the repository root. Write an approach, trace a small case, and add a test. Explain which data is copied, borrowed or changed.

The TODO exception is only an unfinished-placeholder mechanism, not a concept you must learn or use in your implementation. Implement the error/result behavior in the contract. Algorithms that the contract prohibits must not be used even if tests pass.

<details>
<summary>Hint: approach</summary>

Pass current and output by reference to a helper. Explore without and with each element; undo push_back after the second branch.

</details>

<details>
<summary>Reasoning and solution — after attempting</summary>

An ordinary function is sufficient for backtracking. Copying current into the output saves a snapshot while the working vector changes.

Read [solution.hpp](solution.hpp). **Complexity:** O(n*2^n) time/output, O(n) working stack.

`python3 tools/run.py 16 --reference` tests the reference without modifying your work.

</details>
