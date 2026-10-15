# C++ Foundations: learn the language through problems

**28 general C++ challenges**, organized around language concepts and useful problem-solving patterns. For someone who knows basic programming in another language and wants a solid start in C++ for college and later projects.

You do not need robotics, computer vision, controls, or AI knowledge. There are no print-and-arithmetic drills. The first task already involves duplicates, edge cases and optional results; later tasks teach ownership, classes, templates, streams and RAII.

The earlier 24 engineering-themed challenges now live in **[applied/](applied/)** as optional follow-up practice. Start with the general track below.

## Learn two things together

1. **Reasoning:** contracts, invariants, edge cases, data structures and complexity.
2. **C++:** types, references, lifetime, ownership, class design, standard-library interfaces and resource management.

Solving an algorithm without understanding how values are copied or borrowed is only half the task. Each exercise also asks you to explain the language choices.

## Start

Follow [SETUP.md](docs/SETUP.md) for a GCC/Clang C++17 compiler and Python 3.9+. No external C++ libraries or Python packages are needed.

1. Read the [Python-to-C++ bridge](docs/CPP_BRIDGE.md) and Stage 1 in [CONCEPTS.md](docs/CONCEPTS.md). These beginner notes are in Vietnamese, with Python/C++ comparisons; read later stages only when needed.
2. Open [01 — Second distinct largest value](problems/01_second_largest/README.md).
3. Implement its function in `starter.hpp`.
4. Run from the repository root:

```bash
python3 tools/run.py 01
```

On Windows, `python` may be the command instead of `python3`. Unfinished starters intentionally report TODO and fail when run. Each challenge supplies a complete contract, tests, expandable hints, an explained reference solution and a C++ reasoning question.

```bash
python3 tools/run.py --list
python3 tools/run.py 01                     # Your implementation
python3 tools/run.py 01 --reference         # Reference implementation
python3 tools/run.py all --reference        # General reference suite
python3 tools/run.py 14 --sanitize          # Optional memory/undefined-behavior checks
python3 applied/tools/run.py 13             # Optional engineering track
```

Reference mode never overwrites your work. General problems compile independently; you do not need to solve an earlier starter to run a later task.

## General curriculum

| Stage | Tasks | C++ focus | Representative problems |
| --- | --- | --- | --- |
| 1 | 01–04 | Types, functions, references, structs, optional | Second largest, fraction normalization, reference mutation, run encoding |
| 2 | 05–08 | Strings, vectors, views, iterators, bounds | Whitespace normalization, rotation, merge, nested brackets |
| 3 | 09–12 | Containers and algorithmic reasoning | Two sum, first unique byte, binary search, unique substring |
| 4 | 13–16 | Pointers, lifetime, ownership, recursion | Borrowed arrays, owned lists, subsets, borrowed results |
| 5 | 17–20 | Classes, operators, value semantics, polymorphism, moves | Fraction class, inventory, virtual cloning, move-only buffer |
| 6 | 21–24 | Callables, STL algorithms, templates, iterators | Generic map, anagram groups, stable ranking, frequencies |
| 7 | 25–28 | Streams, validation, exceptions, variant, RAII | Strict parsing, line statistics, typed values, formatting guard |

The [full roadmap](docs/ROADMAP.md) links every task. [CONCEPTS.md](docs/CONCEPTS.md) explains what to learn before each stage and what to demonstrate afterward.

## Practice routine

- Read concept notes; attempt a problem for 25–45 minutes before using a hint.
- Trace a small input and state the invariant.
- Add a test of your own, including a failure case where applicable.
- Explain what is owned, borrowed, copied, moved and mutated. For classes, state the invariant.
- After reading a solution, close it and rewrite it later without looking.
- Record both algorithmic complexity and a C++ lesson in [PROGRESS.md](PROGRESS.md).

These are visible tests, not a hidden online judge. Passing tests does not prove every contract or constraints such as “use recursion.” Review your reasoning and code as well.

## Beyond challenges

After the relevant stages, build one of the general [projects](docs/CAPSTONES.md): a text-analysis command-line tool, library catalog or expression evaluator. The guide introduces multiple translation units and build commands.

This is a foundation, not the entire language or a replacement for college courses. Later study includes deeper exception guarantees, CMake, testing frameworks, concurrency, networking, profiling and platform APIs. Domain-specific libraries come after the general foundation.

## Layout and automated checks

`problems/` contains the 28 general tasks. `applied/` preserves the earlier optional track with its own runner. `docs/` contains general notes and projects. `tests/check.hpp` supplies checks independent of NDEBUG.

GitHub Actions tests references and compiles learner interfaces in both tracks. Unfinished learner implementations do not have to pass runtime tests. Headers include a broad set of standard headers for convenience; remove unused includes as a cleanup exercise.

All challenges are original; no paid problem statements or solutions were copied.
