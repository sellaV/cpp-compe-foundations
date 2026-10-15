# 27. Parse a typed configuration value

**Stage 7: Parsing, streams, errors and RAII**

## Learn before solving

variant, optional, string_view, get, holds_alternative. Read the matching section in [CONCEPTS.md](../../docs/CONCEPTS.md).
No engineering or machine-learning knowledge is needed.

## Contract

using Value=variant<int,bool,string>. parse_value(string_view) returns optional<Value>. Accepted exact forms: int:<decimal int with optional - but no +>, bool:true, bool:false, text:<any suffix including empty>. No trimming; invalid prefix/payload/overflow returns nullopt. Returned strings must own their data. n<=100000 bytes.

## Example

```text
"int:42" -> int 42; "text:42" -> string "42"
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 tools/run.py 27` from the repo root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Choose the alternative from the prefix, not whether the payload happens to look numeric. Build explicit string for the text branch.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

variant stores one of a fixed set of types; optional adds a separate parse-failure state. Returning string_view as text would risk borrowing a destroyed input. Explicit alternatives avoid surprising bool conversions.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

variant stores one of a fixed set of types; optional adds a separate parse-failure state. Returning string_view as text would risk borrowing a destroyed input. Explicit alternatives avoid surprising bool conversions.

**Complexity:** O(n) time, O(n) space for text or O(1) for int/bool.

Check it with `python3 tools/run.py 27 --reference`. Reference mode never replaces your starter.

</details>
