# 12. Transform data with a callable

**Stretch** · 3 · Classes, lifetimes and generic C++

## C++ you will practice

function templates, callable parameters, lambdas, decltype, type_traits.

## Problem

Implement map_values(vector<T> const&, F) returning vector<U>, where U is the decayed type of f(const T&). Apply f once to each element in order. T and U are copyable value types; U is not void. Input may be empty. Do not use std::transform. n<=100,000.

## Example

```text
map_values({1,2,3}, [](int x){return x*0.5;}) -> vector<double>{0.5,1,1.5}
```

## Your task

Edit `starter.hpp`. The signature and supporting type declarations are already supplied.
For classes, implement the listed public API and add private state as needed.
Use standard C++17 only. The tests reveal examples and edge cases, not the implementation.

```bash
python tools/run.py 12
```

Before coding, write an approach and predict time/space complexity. After passing,
add one test that would break an incorrect approach. Inputs satisfying the stated
constraints may be assumed unless the contract explicitly requests validation.

<details>
<summary>Hint 1: approach</summary>

Use std::decay_t<decltype(f(std::declval<const T&>()))> to derive the output type without calling f.

</details>

<details>
<summary>Hint 2: invariant and C++ reasoning</summary>

A callable can be a lambda, function pointer, or functor. decltype is unevaluated, so it does not consume an element or invoke f. decay removes reference/cv qualifiers to give a storable value type.

</details>

<details>
<summary>Solution and complexity (open after attempting)</summary>

Read [solution.hpp](solution.hpp).

A callable can be a lambda, function pointer, or functor. decltype is unevaluated, so it does not consume an element or invoke f. decay removes reference/cv qualifiers to give a storable value type.

**Complexity:** O(n) callable invocations; O(n) output storage. Runtime also depends on f.

Check the reference independently with `python tools/run.py 12 --reference`.
Reference mode does not change your starter file.

</details>
