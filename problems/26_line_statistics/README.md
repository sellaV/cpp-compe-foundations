# 26. Summarize text through stream interfaces

**Stage 7: Parsing, streams, errors and RAII**

## Learn before solving

getline, istream/ostream, EOF, reusable I/O. Read the matching section in [CONCEPTS.md](../../docs/CONCEPTS.md).
No engineering or machine-learning knowledge is needed.

## Contract

LineStats{size_t lines,nonempty,max_length}. summarize_lines(istream&) counts lines returned by getline; strip one trailing carriage return from each line (CRLF support). Count nonempty after stripping; spaces make a nonempty line. No extra line after final newline. Bad/non-EOF failed stream throws runtime_error. write_stats(ostream&,LineStats const&) writes exactly lines=X;nonempty=Y;max=Z followed by newline, using decimal integers regardless of existing numeric base, and preserves stream flags. Standard streams with default exception masks; total input<=10^6 bytes.

## Example

```text
"a\n\nbb\n" -> lines=3, nonempty=2, max_length=2
```

## Work

1. Explain the input, output, and edge cases in your own words.
2. Sketch an approach and predict its time and space cost.
3. Implement `starter.hpp`; keep the provided public interface. Add private helpers/state where needed.
4. Run `python3 tools/run.py 26` from the repo root.
5. Add a test that would reject a plausible incorrect implementation.
6. Explain the C++ concept: what is copied, borrowed, owned, or mutated?

Some requirements (such as using recursion or not sorting) require reading your own code; passing tests alone cannot prove them.
Inputs satisfy listed bounds and preconditions unless explicit validation is requested.

<details>
<summary>Hint 1 — approach</summary>

Use getline rather than testing eof before reading. Save and restore output flags when selecting decimal.

</details>

<details>
<summary>Hint 2 — C++ reasoning</summary>

An ifstream can be passed to the input function without embedding filenames into the algorithm. A final unterminated line still counts. Stream state and file lifetime are separate concerns.

</details>

<details>
<summary>Solution explanation — after attempting</summary>

Read [solution.hpp](solution.hpp).

An ifstream can be passed to the input function without embedding filenames into the algorithm. A final unterminated line still counts. Stream state and file lifetime are separate concerns.

**Complexity:** O(total bytes) time, O(longest line) temporary storage.

Check it with `python3 tools/run.py 26 --reference`. Reference mode never replaces your starter.

</details>
