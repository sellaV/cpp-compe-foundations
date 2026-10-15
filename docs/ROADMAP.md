# General C++ roadmap

Start with the general track even if your long-term goal is robotics, games, backend, or AI. None of these 28 tasks requires domain knowledge. Read [CONCEPTS.md](CONCEPTS.md) alongside the exercises.

Use 8–12 weeks as an initial pace, not a deadline: 2–4 problems per week with additional sessions for classes and ownership. Early tasks are logical warm-ups; later language-design tasks may take several sessions.

| ID | Challenge | Stage | C++ concepts |
| --- | --- | --- | --- |
| 01 | [Second distinct largest value](../problems/01_second_largest/README.md) | 1 · Functions, types and references | const reference, vector, optional, branching |
| 02 | [Normalize fraction data](../problems/02_fraction_parts/README.md) | 1 · Functions, types and references | struct, int64_t, gcd, exceptions, return by value |
| 03 | [Rotate three caller-owned values](../problems/03_rotate_references/README.md) | 1 · Functions, types and references | reference parameters, temporaries, aliasing |
| 04 | [Encode consecutive character runs](../problems/04_run_encoding/README.md) | 1 · Functions, types and references | string, struct, vector, size_t, range loops |
| 05 | [Normalize whitespace between words](../problems/05_normalize_spaces/README.md) | 2 · Strings, vectors and invariants | string_view, ASCII predicates, string building |
| 06 | [Rotate a vector in place](../problems/06_rotate_vector/README.md) | 2 · Strings, vectors and invariants | mutable reference, iterators, reverse, modulo |
| 07 | [Merge two sorted sequences](../problems/07_merge_sorted/README.md) | 2 · Strings, vectors and invariants | two pointers, bounds, const references |
| 08 | [Validate nested brackets](../problems/08_balanced_brackets/README.md) | 2 · Strings, vectors and invariants | stack pattern with vector, char branching |
| 09 | [Two sum with deterministic indices](../problems/09_two_sum/README.md) | 3 · General problem-solving patterns | unordered_map, optional, pair, iterators, int64_t |
| 10 | [First nonrepeating byte](../problems/10_first_unique/README.md) | 3 · General problem-solving patterns | array, unsigned char conversion, two passes |
| 11 | [Find the first qualifying index](../problems/11_binary_search/README.md) | 3 · General problem-solving patterns | half-open intervals, unsigned indices, binary search |
| 12 | [Longest substring without repeated bytes](../problems/12_unique_window/README.md) | 3 · General problem-solving patterns | sliding window, array, index invariants |
| 13 | [Reverse a borrowed array range](../problems/13_pointer_range/README.md) | 4 · Pointers, ownership and recursion | raw observing pointers, pointer arithmetic, nullptr |
| 14 | [Insert into a uniquely owned linked list](../problems/14_owned_list/README.md) | 4 · Pointers, ownership and recursion | unique_ptr, move, pointer-to-owner, make_unique |
| 15 | [Generate a power set recursively](../problems/15_subsets/README.md) | 4 · Pointers, ownership and recursion | recursion, backtracking, vector copying versus references |
| 16 | [Return a pointer to the first maximum](../problems/16_borrowed_result/README.md) | 4 · Pointers, ownership and recursion | const and mutable overloads, pointer return, lifetime |
| 17 | [A normalized fraction value class](../problems/17_value_class/README.md) | 5 · Classes, value semantics and polymorphism | constructors, private invariants, const methods, operator overloading |
| 18 | [An inventory with checked updates](../problems/18_inventory/README.md) | 5 · Classes, value semantics and polymorphism | encapsulation, map, exceptions, transactional updates |
| 19 | [Clone polymorphic objects](../problems/19_polymorphic_copy/README.md) | 5 · Classes, value semantics and polymorphism | abstract base, virtual destructor, override, unique_ptr, dynamic dispatch |
| 20 | [Implement move-only resource ownership](../problems/20_move_only_buffer/README.md) | 5 · Classes, value semantics and polymorphism | RAII, unique_ptr<T[]>, deleted copy, noexcept move, self-move |
| 21 | [Map values using any callable](../problems/21_generic_transform/README.md) | 6 · STL, callables, templates and iterators | function templates, callable parameters, lambdas, decltype, type_traits |
| 22 | [Group words by a canonical key](../problems/22_group_anagrams/README.md) | 6 · STL, callables, templates and iterators | unordered_map, sorting, map key/value separation |
| 23 | [Rank records without losing tie order](../problems/23_stable_ranking/README.md) | 6 · STL, callables, templates and iterators | struct, stable_sort, strict weak ordering, iterators |
| 24 | [Count generic values from iterators](../problems/24_generic_frequencies/README.md) | 6 · STL, callables, templates and iterators | function templates, iterator_traits, map, iterator ranges |
| 25 | [Parse whitespace-separated integers strictly](../problems/25_checked_parsing/README.md) | 7 · Parsing, streams, errors and RAII | istream, string tokens, from_chars, exception reporting |
| 26 | [Summarize text through stream interfaces](../problems/26_line_statistics/README.md) | 7 · Parsing, streams, errors and RAII | getline, istream/ostream, EOF, reusable I/O |
| 27 | [Parse a typed configuration value](../problems/27_variant_value/README.md) | 7 · Parsing, streams, errors and RAII | variant, optional, string_view, get, holds_alternative |
| 28 | [Restore stream formatting with RAII](../problems/28_scope_guard/README.md) | 7 · Parsing, streams, errors and RAII | destructor, references, deleted special members, exception unwinding |

## Milestones

- After 04: write a function with a precise contract, distinguish by-value/by-reference behavior, and represent a missing answer.
- After 08: manipulate sequences without invalid indexing; explain iterator ranges and loop invariants.
- After 12: justify hash-table, binary-search and sliding-window approaches and their complexity.
- After 16: explain owner/observer relationships, borrowed pointer lifetime, recursive base cases and backtracking.
- After 20: design class invariants, independent copies, virtual cloning and move-only ownership.
- After 24: use generic callables, sorting comparators and non-random-access iterator interfaces.
- After 28: distinguish parse errors from I/O failure and use RAII for exception-safe cleanup.

Every general exercise compiles independently. Once you can explain its code rather than reproduce it, choose a general project in [CAPSTONES.md](CAPSTONES.md). The optional engineering curriculum has its own [roadmap](../applied/docs/ROADMAP.md).
