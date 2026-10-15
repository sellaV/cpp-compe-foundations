# C++ Foundations: logic first, libraries later

**20 core exercises → 18 later library exercises → 24 optional applied exercises.**

Learn C++ through problems that require reasoning, without learning several unfamiliar APIs at once. The core track uses ordinary types, conditions, loops, functions, arrays, references, pointers and classes. It allows basic vector/string operations as practical storage tools, but postpones standard algorithms, associative containers, optional, smart pointers and templates.

You do not need robotics, AI or computer-vision knowledge. No print-and-arithmetic drills are assigned.

## Start here

1. Follow [SETUP.md](docs/SETUP.md) for GCC/Clang with C++17 and Python 3.9+.
2. Read [CPP_BRIDGE.md](docs/CPP_BRIDGE.md) and only Stage 1 of [CONCEPTS.md](docs/CONCEPTS.md).
3. Open [01 — Second distinct largest using state flags](problems/01_second_largest/README.md).
4. Implement starter.hpp and run:

```bash
python3 tools/run.py 01
```

Reference mode does not change your work:

```bash
python3 tools/run.py --list
python3 tools/run.py 01 --reference
python3 tools/run.py all --reference
```

On Windows, python may be the command instead of python3. The runner compiles your C++; Python is only the test launcher.

## Track 1: core language and manual logic

| Stage | Exercises | What you practice |
| --- | --- | --- |
| 1 | 01–04 | State flags, conditions, loops, functions, references, simple structs |
| 2 | 05–08 | Character scans, index-based reversal/rotation, merging, bracket matching |
| 3 | 09–12 | Built-in arrays, manual binary search, pair search, in-place compaction |
| 4 | 13–16 | Borrowed pointers, lifetime, const overloads, recursive search, backtracking |
| 5 | 17–20 | Constructors, private invariants, value semantics, virtual methods, fixed queue |

See the [linked roadmap](docs/ROADMAP.md). Every core exercise compiles independently. Core solutions include only headers they actually use.

### Library boundary in the core track

vector and string are standard-library types too. They remain here to let you focus on reasoning without first building a dynamic array or string class. Use basic operations such as size, indexing, push_back, pop_back, empty, back and resize. A few exercises use reserve only to prepare output capacity.

Core implementations do not require optional, map/unordered_map, std::array, standard search/sort/reverse algorithms, lambdas, smart pointers, type-traits or parsing libraries. Read each contract for its restrictions. The test harness and unfinished TODO mechanism use some supporting library features; understanding those internals is not a prerequisite for solving the exercise.

For missing results, early tasks use a simple struct with a bool flag and a value. Invalid operations return status where specified. Some later core contracts instead state caller preconditions: a precondition is something the caller must guarantee, not something you should silently assume in every real application.

### Migration from the previous version

Exercise 01 now returns NumberResult with fields found and value instead of optional<int>. The new starter and tests document the interface. If you already wrote a solution, keep a copy of it and adapt that function rather than discarding your work. Later exercise 01 retains the earlier optional version for comparison. The original engineering track remains in applied/.

## Track 2: learn the libraries after the ideas

The [later track](later/) has 18 exercises. Some revisit core problems to show what a library replaces and what new rules it introduces. Follow [LIBRARIES.md](docs/LIBRARIES.md) for the sequence.

```bash
python3 later/tools/run.py --list
python3 later/tools/run.py 01
python3 later/tools/run.py all --reference
```

Here you learn optional, standard algorithms, hash maps, smart pointers, moves, lambdas, templates, iterators, streams, exceptions, variant and RAII. They are useful tools to learn, rather than permanent restrictions to avoid.

## Track 3: optional engineering applications

After the foundation, [applied/](applied/) offers 24 exercises involving sensor data, planning, control, image processing and edge-AI numerics.

```bash
python3 applied/tools/run.py --list
python3 applied/tools/run.py 13
```

## Is knowing STL enough?

No. Knowing a container's API does not by itself tell you how to design a loop, preserve state, avoid a dangling pointer, validate an index, debug a class, or manage a resource.

For a practical engineering foundation, prioritize correct logic, arrays/strings, references and lifetime, class design, debugging and basic complexity. Then learn the library tools that make those tasks safer and more maintainable. You do not need to make difficult puzzle solving the center of this course. You should still be able to write and explain a linear scan, a binary search, a simple queue, and basic graph traversal when later applications require them.

This course is not a complete C++ education. After core and relevant later exercises, build a [small project](docs/CAPSTONES.md) with multiple source files, real I/O and tests. Concurrency, deployment and domain libraries need further study.

## Practice and verification

Try each problem before opening hints. Explain the invariant, trace a boundary case, add a test and record a C++ lesson in [PROGRESS.md](PROGRESS.md). Passing visible tests is evidence, not a proof or an enforcement mechanism for every algorithm restriction.

GitHub Actions checks all three tracks: reference behavior, learner interface compilation and address/undefined-behavior sanitizers. Unfinished learner tasks intentionally fail at runtime until implemented. All exercises are original.
