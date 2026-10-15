# Project: a text-report command-line tool

Build a small program you can explain and extend. No contest tricks, regex, hash maps, or external C++ libraries are required. Prerequisites: loops, bool state, structs, references, and the stream introduction in [Libraries](../../docs/LIBRARIES.md). Later exercise 16 is a useful preparation.

## What is supplied and what you write

- `analyzer.hpp`: the public Report type and function declaration.
- `analyzer.cpp`: **your unfinished implementation**.
- `main.cpp`: working argument checking, file opening, error reporting, and output.
- `test.cpp`: unit tests using in-memory input.
- `check.py`: builds and checks both unit and actual CLI behavior.
- `reference/analyzer.cpp`: a separate solution; read after a serious attempt.
- `CMakeLists.txt`: an optional build configuration after the direct build makes sense.

You are allowed to use the standard library here. The learning goal is assembling and maintaining a program, not rebuilding file I/O.

## Contract

`Report analyze(std::istream& input)` consumes bytes from the current stream position until EOF. Assume default stream exception settings and counters large enough for the input.

| Field | Meaning |
| --- | --- |
| bytes | Every byte read, including whitespace, line endings, and embedded zero bytes |
| words | Maximal runs of bytes separated by ASCII space, tab, newline, carriage return, vertical tab, or form feed |
| lines | Number of newline (`\n`) bytes, plus one if nonempty input ends with any other byte |

Empty input has zero in every field. Punctuation stays in a word: `one,two!` is one word. UTF-8 is counted as bytes, not Unicode characters. CRLF occupies two bytes but only its newline ends a line. A stream already at ordinary EOF gives an empty report. A failed stream without ordinary EOF, or a read error, throws `std::runtime_error`; do not silently return a partial report.

The CLI accepts exactly one file path. It returns 0 on success, 2 on invalid argument count, and 1 on file-open or analysis failure. Reports go to stdout; errors go to stderr. Quote file paths that contain spaces.

For the included sample:

```text
lines=2
words=3
bytes=13
```

## Stream syntax explained

```cpp
char ch;
while (input.get(ch)) {
    // ch now contains the next byte. Update your state here.
}
```

`get(ch)` tries to read one character, including whitespace, into `ch`. In the condition, the stream indicates whether that read succeeded. No read succeeds after ordinary EOF. Do not use `while (!input.eof())`, which can process a stale character after a failed read.

`input.bad()` reports a serious stream error. `input.fail()` includes failed reads; reaching EOF during this loop normally sets failure too, so distinguish ordinary EOF with `input.eof()`. Check stream state before and after scanning. `throw std::runtime_error("message")` reports a failure to the caller; main catches it and prints an error.

`std::istringstream` in tests supplies characters from a string; `std::ifstream` in main supplies them from a file. Both implement the same `std::istream` interface. The function borrows the stream through `&`; it neither copies nor owns it.

## Milestone A — Write examples before code

Predict the report for empty input, `a`, `a\n`, `\n\n`, and `a\r\nb`. Explain why the last case has four bytes. Identify what state you need to recognize the start of a word.

## Milestone B — Implement and test the analysis

Implement analyzer.cpp. First get bytes and lines right. Then add word state. Finally handle stream errors. Use helper functions if they improve clarity.

From the repository root:

```bash
python3 projects/text_report/check.py
```

The starter compiles but intentionally fails until implemented. To compare with the supplied reference without changing your work:

```bash
python3 projects/text_report/check.py --reference
```

## Milestone C — Run the real program

From the repository root:

```bash
mkdir -p build/text_report
g++ -std=c++17 -Wall -Wextra -Wpedantic -g projects/text_report/analyzer.cpp projects/text_report/main.cpp -o build/text_report/text_report
./build/text_report/text_report projects/text_report/sample.txt
```

Try a missing file and a path with spaces. Explain argc (argument count), argv (argument strings), and why the program checks argc before reading argv[1]. Do not link main.cpp and test.cpp together: they each define main.

The check script builds both targets and verifies empty files, CRLF, missing paths, argument counts, and a filename with spaces. Add another meaningful case of your own. On Linux/WSL, `--sanitize` enables address/undefined-behavior checks.

## Milestone D — Make one independent change

Choose one: longest-line byte length, a `--help` option, or word frequencies. Write the new behavior first, including empty input and error behavior. Add a test that fails before the feature exists, implement it, and update the README. Keep stdout suitable for a user or another program to consume.

Commit the feature with an explanation of one design choice. Being able to make and verify this change is the project completion milestone; merely copying the reference is not.

## Optional: express the build using CMake

Install CMake if you want to use this alternative. It is not required by check.py.

```bash
cmake -S projects/text_report -B build/text_report-cmake
cmake --build build/text_report-cmake
ctest --test-dir build/text_report-cmake --output-on-failure
```

Default builds use your implementation. For a separate reference build, configure a different directory with `-DUSE_REFERENCE=ON`. CTest runs unit tests; the Python script also checks CLI behavior.

## Design questions

Why does the analysis accept a stream instead of a filename? Who closes the file? Why is word-count state a bool? Why distinguish EOF from a read failure? What are the limitations of ASCII whitespace and byte-based counting?
