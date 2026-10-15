# Practical C++ foundations

**Learn to write, debug, test, and build understandable C++ programs. This curriculum is not competitive-programming preparation.**

For learners coming from Python. All teaching material is in English. Start with general programming; choose engineering applications later. Basic vector/string storage is allowed early, while other library features are introduced after the ideas they express.

## Start here

1. Follow [setup](docs/SETUP.md), then read the [Python-to-C++ bridge](docs/CPP_BRIDGE.md).
2. Read Stage 1 of [Concepts](docs/CONCEPTS.md).
3. Try [second distinct largest](problems/01_second_largest/README.md): implement `starter.hpp`, then run `python3 tools/run.py 01`.
4. Follow the [practical roadmap](docs/ROADMAP.md). It interleaves exercises with Git, debugging, tests, and a project.

```bash
python3 tools/run.py --list
python3 tools/run.py 01
python3 tools/run.py 01 --reference
```

Python launches tests; your implementation is C++. Starters intentionally fail until completed. Reference mode never edits your implementation.

## What is required?

| Component | Purpose | Priority |
| --- | --- | --- |
| Core exercises | State, functions, references, bounds, lifetime, class invariants | Ten foundation tasks; eight selectable extensions |
| [Workflow labs](labs/README.md) | Git, compiler/linker, debugger, meaningful tests | All four labs |
| [Later track](later/README.md) | Streams, standard algorithms, containers, ownership, RAII | Follow the practical sequence; comparison/advanced tasks are selective |
| [Text-report project](projects/text_report/README.md) | A real command-line program with multiple files and tests | Required integration milestone |
| [Applied exercises](applied/README.md) | Optional engineering applications | Choose by project need |

There are 18 core, 13 later, and 22 applied exercises available. These counts are an inventory, **not a completion quota**. IDs have gaps to preserve existing file paths and learner work.

## How this differs from contest training

There are no speed targets, rankings, daily puzzle quotas, or requirements to memorize tricks. Success means you can explain your code, handle bad input, diagnose a failure, write a useful test, and extend a working program.

Learn scans, binary search, a stack/queue, and basic time/space reasoning. Learn graph algorithms when a project needs them. Subset enumeration, pair-sum drills, longest-unique-substring puzzles, anagram grouping, and advanced generic-transform/frequency exercises have been removed. Historical versions remain in Git history.

Manual implementations are temporary teaching exercises. Once you understand an operation, use appropriate standard-library facilities in projects. STL knowledge alone does not replace language semantics, ownership, debugging, or design.

## External resources with a specific job

Use [CS50x](https://cs50.harvard.edu/x/) for explanations of computing, C, memory, and data structures. Use this repo to practice C++ separately: C and C++ have different rules and idioms. Use [CS50P](https://pll.harvard.edu/course/cs50s-introduction-programming-python) selectively for Python gaps. Learn Git alongside your first exercises.

After the integration project, choose one appropriately scoped tutorial from [Build Your Own X](https://github.com/codecrafters-io/build-your-own-x). See [Resources](docs/RESOURCES.md) for prerequisites and how to use all six resources you supplied. Distributed-system interview preparation and Claude API courses are optional topics outside this foundation.

## Practice and checks

For each selected exercise, trace one example, write your own solution, inspect failures, add a useful case, and explain what is copied or borrowed. Use [PROGRESS.md](PROGRESS.md) to record evidence of learning. Hints and references are learning tools, not penalties.

GitHub Actions checks reference behavior, starter compilation, sanitizers, and the integration project. Passing tests is evidence, not a guarantee of correctness or career readiness. This repo is a workbook and project scaffold, not a complete degree or C++ textbook.

## Updating an existing clone

Read [migration notes](docs/MIGRATION.md) before pulling if you have local solutions. Existing retained exercise interfaces are unchanged by this revision.
