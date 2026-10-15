# 10. Implement move-only resource ownership

**Later track: standard-library tools**

## Learn before solving

RAII, unique_ptr<T[]>, deleted copy, noexcept move, self-move. Read the matching section in [CONCEPTS.md](../../../docs/LIBRARIES.md).
This is a later-track exercise; first study the related core language concept.

## Contract

IntBuffer(size_t n) owns n zero-initialized ints. size() const and at(size_t) mutable/const overloads; out-of-range throws out_of_range. Disable copying. noexcept move construction/assignment transfer allocation without copying elements and leave source size 0; self-move assignment leaves object unchanged. n<=100000. No manual new/delete. Default destruction releases resource.

## Example

```text
IntBuffer a(2); a.at(0)=7; IntBuffer b(std::move(a)); b.at(0)==7 and a.size()==0
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 later/tools/run.py 10` from the repository root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Store unique_ptr<int[]> and a size. Defaulted move does not reset a separate size member automatically.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

Owning members already clean up via RAII, but the class must maintain its own moved-from invariant. Returning int& enables mutation; a const overload prevents modification through a const buffer.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

Owning members already clean up via RAII, but the class must maintain its own moved-from invariant. Returning int& enables mutation; a const overload prevents modification through a const buffer.

**Complexity:** O(n) construction, O(1) move and access; O(n) storage.

Check it with `python3 later/tools/run.py 10 --reference`. Reference mode never replaces your starter.

</details>
