# A practical learning path

The goal is independent C++ programming, not competitive programming. Work at your own pace. Begin projects before completing every exercise.

## Milestones

| Step | Study and practice | Evidence you are ready to move on |
| --- | --- | --- |
| 1. Values and state | Core 01–05; matching Concept sections; CS50x C/arrays material as needed; Lab 1 Git | Explain a result flag, a loop, and copy versus reference; make a focused commit |
| 2. Bounds and failure diagnosis | Core 10, 13, 14; Labs 2 and 3; CS50x algorithms/memory material | Explain a search interval and borrowed lifetime; distinguish compile, link, and runtime failures; find a bug with the debugger |
| 3. Small abstractions | Core 18 and 20; Lab 4 tests | Preserve class state on failure; explain FIFO; write a test that detects a real defect |
| 4. Real input/output | Later 16, then 15; project milestones A–C | Read a real file, report invalid usage, separate logic from I/O, and pass project tests |
| 5. Practical libraries and ownership | Later 03, 08, 13, 10, 18; [library guide](LIBRARIES.md) | Explain iterator ranges, container choice, move ownership, and destructor cleanup |
| 6. Independent extension | Project milestone D; select a second project | Specify behavior before coding, add tests, and document a design decision |

[Workflow labs](../labs/README.md) provide exact commands and completion criteria. [Project instructions](../projects/text_report/README.md) include a starter, a working CLI shell, unit tests, and a separate reference.

Foundation core IDs: **01, 02, 03, 04, 05, 10, 13, 14, 18, 20**. The remaining eight tasks are extensions. Choose 08 for a stack, 15 for recursion, 17 for operators, or 19 for virtual interfaces when useful. You do not need to solve all extensions before starting a project.

## Core exercise directory

IDs are stable, not a required uninterrupted sequence. Use `python3 tools/run.py --list` to see foundation/extension labels.

| ID | Exercise | Stage | Main concepts |
| --- | --- | --- | --- |
| 01 | [Second distinct largest using state flags](../problems/01_second_largest/README.md) | 1 · State, loops, functions and references | int, bool, conditions, loops, a simple result struct |
| 02 | [Normalize a fraction with your own GCD loop](../problems/02_fraction_parts/README.md) | 1 · State, loops, functions and references | long long, modulo, while loops, structs, status results |
| 03 | [Rotate three caller-owned values](../problems/03_rotate_references/README.md) | 1 · State, loops, functions and references | reference parameters, snapshots, caller mutation |
| 04 | [Encode consecutive character runs](../problems/04_run_encoding/README.md) | 1 · State, loops, functions and references | string, vector, struct, loops |
| 05 | [Normalize whitespace between words](../problems/05_normalize_spaces/README.md) | 2 · Manual sequence operations | const string reference, manual character checks |
| 06 | [Rotate in place using manual reversals](../problems/06_rotate_vector/README.md) | 2 · Manual sequence operations | index loops, helper functions, mutable references, modulo |
| 07 | [Merge two sorted sequences](../problems/07_merge_sorted/README.md) | 2 · Manual sequence operations | two indices, short-circuit conditions, loop invariants |
| 08 | [Validate nested brackets](../problems/08_balanced_brackets/README.md) | 2 · Manual sequence operations | manual stack using a vector, char conditions |
| 09 | [First nonrepeating byte using a plain array](../problems/09_first_unique/README.md) | 3 · Arrays and general search logic | built-in arrays, two passes, result structs, casts |
| 10 | [Find the first qualifying index](../problems/10_binary_search/README.md) | 3 · Arrays and general search logic | manual binary search, half-open index intervals |
| 12 | [Remove duplicates while preserving order](../problems/12_remove_duplicates/README.md) | 3 · Arrays and general search logic | in-place compaction, nested scans, vector resizing |
| 13 | [Reverse a borrowed array range](../problems/13_pointer_range/README.md) | 4 · Pointers, lifetime and recursion | raw pointers, nullptr, explicit lengths, status returns |
| 14 | [Return the address of the first maximum](../problems/14_borrowed_result/README.md) | 4 · Pointers, lifetime and recursion | pointer returns, const overloads, borrowed lifetime |
| 15 | [Search a sorted range recursively](../problems/15_recursive_search/README.md) | 4 · Pointers, lifetime and recursion | recursive functions, base cases, signed index bounds |
| 17 | [A fraction class with manual normalization](../problems/17_fraction_class/README.md) | 5 · Classes and data structure implementation | private members, constructors, const methods, operators |
| 18 | [Inventory using a vector of records](../problems/18_inventory/README.md) | 5 · Classes and data structure implementation | classes, vector of structs, linear lookup, checked updates |
| 19 | [Virtual methods without dynamic allocation](../problems/19_polymorphic_values/README.md) | 5 · Classes and data structure implementation | abstract base, override, const references, object lifetime |
| 20 | [Build a fixed-capacity queue class](../problems/20_fixed_queue/README.md) | 5 · Classes and data structure implementation | built-in member arrays, circular indices, state invariants |


## What to avoid turning into prerequisites

Do not delay a project until you finish an entire CS50 course, all optional exercises, every STL container, or every project in Build Your Own X. CS50's C exercises stay in C; use our exercises to learn C++ separately. If pursuing a CS50 certificate, follow its official complete requirements.

For this workbook, assess readable code, correct behavior, debugging, ownership, tests, and basic complexity. Advanced dynamic programming, competitive-programming tricks, and system-design interview drills are outside the required path.

## Beyond the foundation

Continue computer architecture, digital logic, operating systems, mathematics, and engineering coursework. Choose applied exercises to support actual projects. This repository introduces skills; it does not certify mastery or guarantee an internship.
