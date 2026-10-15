# General C++ integration projects

These are briefs, not prebuilt solutions. No engineering background or external library is required.

## 1. Text-analysis command-line tool

Read a real file; report line/word counts and ten most frequent words; optionally save a report. Define ASCII case and punctuation rules. First implement analysis using loops, vectors and strings. Add file streams from the later track afterward. Separate file opening, tokenization, analysis and formatting. Test missing/empty files, whitespace-only text and frequency ties. Use stringstreams for algorithm tests, ifstream/ofstream in the executable, and validate successful opens.

## 2. Library catalog

Implement Book and Catalog types supporting add, remove, search, borrow and return. Define identifiers and duplicate behavior. Persist a documented text format; reject malformed records. Demonstrate const queries, independent copying, class invariants and failure without partial mutation where promised. Add a command parser and at least eight useful behavior tests.

## 3. Expression evaluator

Parse integers, parentheses, unary minus and +,-,*,/ with normal precedence. Use recursive descent. Separate tokenization, parsing and evaluation. Define overflow and integer division policies. Test malformed expressions, missing operands, nested parentheses and division by zero. Optional extension: uniquely owned polymorphic expression nodes.

## First multi-file build

Challenges use headers for convenience. A project should separate declarations and definitions:

```text
project/
  catalog.hpp       public declarations
  catalog.cpp       non-inline definitions
  main.cpp          application entry point
  test.cpp          separate test entry point
```

From that directory:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic catalog.cpp main.cpp -o catalog
g++ -std=c++17 -Wall -Wextra -Wpedantic catalog.cpp test.cpp -o catalog_test
```

Do not link main.cpp and test.cpp together: each defines main. Each .cpp is a translation unit; compilation produces object code and linking resolves references. Include declarations from headers, not .cpp files. Non-inline function definitions generally belong in one .cpp; template definitions usually need visibility in headers.

After this works, learn CMake to express targets/dependencies. Include build/run instructions, tests and a documented design tradeoff. Then try the optional [engineering track](../applied/README.md).
