# 25. Parse whitespace-separated integers strictly

**Stage 7: Parsing, streams, errors and RAII**

## Learn before solving

istream, string tokens, from_chars, exception reporting. Read the matching section in [CONCEPTS.md](../../docs/CONCEPTS.md).
No engineering or machine-learning knowledge is needed.

## Contract

read_integers(istream&) reads whitespace-separated tokens until EOF, each exactly a signed decimal int with optional leading - (no +). Invalid, partially parsed, or out-of-range token throws invalid_argument. Empty/whitespace-only stream yields empty. A bad/non-EOF failed stream throws runtime_error. Parsing consumes the stream; no rollback promised. n<=100000 tokens.

## Example

```text
"12 -3 004" -> {12,-3,4}; "12 3x" -> exception
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 tools/run.py 25` from the repo root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Read tokens as strings, then require from_chars to consume the complete token. An extraction loop alone would silently accept partial numbers.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

Streams abstract the source: the same function accepts files and stringstreams. Token parsing separates malformed content from I/O failure. from_chars reports errors without its own exceptions.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

Streams abstract the source: the same function accepts files and stringstreams. Token parsing separates malformed content from I/O failure. from_chars reports errors without its own exceptions.

**Complexity:** O(total bytes) time, O(n) output plus O(longest token) temporary storage.

Check it with `python3 tools/run.py 25 --reference`. Reference mode never replaces your starter.

</details>
