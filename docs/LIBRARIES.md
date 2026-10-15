# Libraries that support practical programs

Learn one facility when you have a concrete use for it. Basic vector/string storage already appears in the core. Manual implementation restrictions apply to designated exercises, not every project.

## 1. Streams and validation: later 16, then 15

`std::istream` is a source of characters. `std::ostream` is a destination. A function receiving these interfaces can operate on files or in-memory strings, making the same logic easy to test.

`std::ifstream` opens a file for reading. Check that opening succeeded. Read by checking the read operation, not by predicting the next read with `eof()`. Later 16 practices text processing; later 15 adds strict integer parsing, including trailing junk and out-of-range values.

The [project](../projects/text_report/README.md) supplies the CLI and file-opening code. You implement the analysis. Its README explains every unfamiliar stream operation before asking you to use it.

## 2. Algorithms and containers: later 03, 08, 13

An iterator identifies a position. Standard algorithms commonly use `[begin,end)`, where end is after the last item and cannot be dereferenced. Compare later 03 with core 06 if you want a manual-versus-library reversal comparison.

Later 08 stores inventory records in `std::map`. A map associates a key with a value, somewhat like a Python dictionary; `std::map` also maintains key order. `std::unordered_map` uses hashing and does not promise sorted iteration. Learn to explain ordering needs, average lookup cost, and storage overhead before switching containers. A separate hash-map puzzle is not required.

Later 13 sorts records with a lambda comparator. `[](const Record& a, const Record& b) { return a.score > b.score; }` is an example of a small unnamed function, assuming Record has a score member. A comparator must be strict: use `>` rather than `>=`. Stable sorting preserves the input order of ties.

For real projects, use `std::vector` rather than writing a resizable array from scratch. Study iterator/pointer invalidation whenever you keep an address into a container across modifications.

## 3. Lifetime and resource management: later 10, 18

A borrowed pointer does not keep its target alive. An owning object is responsible for cleanup. `std::unique_ptr` owns an allocation and releases it automatically; `std::make_unique` creates such an owner.

`std::move` permits a move operation; it is not itself a copy loop or a guarantee that every moved-from object becomes empty. Follow the type's contract. Later 10 makes ownership transfer explicit in a small class.

RAII means tying resource cleanup to an object's lifetime. A destructor runs when its object leaves scope, including during exception unwinding. Later 18 restores formatting state this way. File streams already close their files through their destructors.

A custom move-only wrapper is a learning exercise. Ordinary application classes can often rely on vector/string/owning members and compiler-generated special member functions instead of writing custom copy/move code.

## Selective comparisons and extensions

| IDs | Topic | When useful |
| --- | --- | --- |
| 01 | optional | Compare with core 01's bool/value result; presence is different from a nonzero value |
| 02 | gcd and exceptions | Compare with core 02; understand error-reporting choices |
| 06 | Owned linked nodes | When reading linked ownership structures; not required for everyday storage |
| 07 | Value operators | If making a meaningful value type |
| 09 | Virtual cloning | When copies must preserve derived types |
| 17 | variant | When a configuration value has a small set of possible types |

Templates let code work with different types. Recognizing `vector<int>` and reading a simple function template is useful. Writing type-trait-heavy generic libraries is not a foundation milestone here.

**Completion check:** Explain which objects own resources, handle invalid input, choose a suitable container, use a standard algorithm correctly, and test the behavior. Memorizing every STL API is unnecessary.
