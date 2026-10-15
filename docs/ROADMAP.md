# Core roadmap: language and manual logic first

Read only the matching stage in [CONCEPTS.md](CONCEPTS.md). Core 01–20 needs basic vector/string storage but no optional, hash maps, standard algorithms, smart pointers or templates.

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
| 11 | [Find a pair by checking candidates yourself](../problems/11_pair_search/README.md) | 3 · Arrays and general search logic | nested loops, long long arithmetic, structs, early return |
| 12 | [Remove duplicates while preserving order](../problems/12_remove_duplicates/README.md) | 3 · Arrays and general search logic | in-place compaction, nested scans, vector resizing |
| 13 | [Reverse a borrowed array range](../problems/13_pointer_range/README.md) | 4 · Pointers, lifetime and recursion | raw pointers, nullptr, explicit lengths, status returns |
| 14 | [Return the address of the first maximum](../problems/14_borrowed_result/README.md) | 4 · Pointers, lifetime and recursion | pointer returns, const overloads, borrowed lifetime |
| 15 | [Search a sorted range recursively](../problems/15_recursive_search/README.md) | 4 · Pointers, lifetime and recursion | recursive functions, base cases, signed index bounds |
| 16 | [Backtracking with an ordinary helper function](../problems/16_subsets/README.md) | 4 · Pointers, lifetime and recursion | recursion, reference parameters, snapshots, undoing changes |
| 17 | [A fraction class with manual normalization](../problems/17_fraction_class/README.md) | 5 · Classes and data structure implementation | private members, constructors, const methods, operators |
| 18 | [Inventory using a vector of records](../problems/18_inventory/README.md) | 5 · Classes and data structure implementation | classes, vector of structs, linear lookup, checked updates |
| 19 | [Virtual methods without dynamic allocation](../problems/19_polymorphic_values/README.md) | 5 · Classes and data structure implementation | abstract base, override, const references, object lifetime |
| 20 | [Build a fixed-capacity queue class](../problems/20_fixed_queue/README.md) | 5 · Classes and data structure implementation | built-in member arrays, circular indices, state invariants |

## Priorities

First become comfortable with stages 1–3. Then learn borrowed pointer lifetime and class invariants. Core 16 (subset backtracking) and 19 (virtual interfaces) can be treated as optional extensions on a first pass; they are not requirements for starting a small project.

After the core foundations, use [LIBRARIES.md](LIBRARIES.md) to study 18 later exercises. They show the tools after the underlying problems are familiar. The [applied track](../applied/) remains optional domain practice. [CAPSTONES.md](CAPSTONES.md) supplies general project briefs.
