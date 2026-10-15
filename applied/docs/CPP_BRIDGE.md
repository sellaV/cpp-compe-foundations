# C++ bridge for someone who knows Python

You do not need weeks of syntax drills before problem 01. Read the first four sections, attempt 01–02, then revisit this page as later problems introduce concepts.

## Types, loops and vectors

```cpp
std::vector<int> samples{3, 7, -1};
int threshold = 5;
std::size_t count = 0;
for (int value : samples) {
    if (value > threshold) {
        ++count;
    }
}
```

`std::vector<int>` is a dynamic sequence of integers. Unlike a Python list, its element type is fixed. `.size()` reports its length; `.push_back(value)` appends. `std::size_t` is an unsigned type for sizes and indices: avoid subtracting one from zero. Use signed coordinates for grid neighbors that may temporarily be negative.

## Functions and references

```cpp
std::vector<int> keep_positive(const std::vector<int>& input) {
    std::vector<int> result;
    for (int value : input) {
        if (value > 0) result.push_back(value);
    }
    return result;
}
```

`const std::vector<int>&` borrows the caller's vector without copying it and prohibits mutation through that reference. `std::vector<int>` passed by value gives you a separate vector. Returning a new vector by value is safe; returning a reference to a local vector is not, because the local object dies when the function returns.

## Conditions and numeric operations

Use `&&` for and, `||` for or, and `!` for not. `==` compares; `=` assigns. Curly braces group statements. `5 / 2` is integer division and returns `2`; `5.0 / 2` returns `2.5`. A `double` accumulator and a floating-point divisor matter for means and probabilities.

Signed overflow is undefined behavior. Choosing a wider integer before addition/subtraction is better than hoping an overflowing int will wrap.

## Compile errors versus failed tests

- A compile error means C++ cannot produce the program: missing semicolon, wrong type, unknown name, or invalid syntax.
- A test failure means the program compiled but returned behavior that violates a checked contract.
- An exception means code rejected an input or hit an intentional unfinished `TODO`. `throw std::invalid_argument("range")` is how these exercises signal a specified invalid argument.

Read `starter.hpp`, `test.cpp`, and the problem contract together. Do not put a `main()` inside the starter; tests already supply it.

## Missing results, pairs and structs

`std::optional<int>` either owns an int or is `std::nullopt`. Check `if (result)` before reading `*result`; never dereference an empty optional. A pair holds two values; `auto [a,b] = pair;` gives names using structured bindings. A struct groups named fields such as a bounding box's coordinates.

## Maps, queues and heaps

`unordered_map` supports lookup by key. `.find(key)` returns an iterator; compare it to `.end()` before using `it->second`. `map[key]` can INSERT a default value when absent, so use `find` for a pure existence check.

`queue` is FIFO: inspect `.front()`, then `.pop()`. `priority_queue` is a max-heap by default; `std::greater<T>` makes it a min-heap. Check `.empty()` before accessing either.

## Classes and ownership

```cpp
class Counter {
    int value_ = 0;  // private by default
public:
    void increment() { ++value_; }
    int value() const { return value_; }
};
```

A constructor initializes an object. Private state helps enforce invariants. A `const` method promises not to modify the object's ordinary members. A scoped `enum class` represents a finite set of states without treating them like arbitrary integers.

`std::unique_ptr<T>` owns one object; destruction releases it. It cannot be copied. `std::move(ptr)` enables ownership transfer; the old pointer normally becomes empty after transfer. `.get()` returns a non-owning pointer. A borrowed pointer must not outlive its owner. Prefer standard containers and smart pointers over manual `new`/`delete`.

RAII means resource cleanup follows object lifetime. It applies to memory, file handles, locks and device resources, not just pointers. Problem 11 introduces ownership, but does not teach every aspect of resource management.

## Templates and lambdas

`template<class T>` lets a class or function work with multiple types. `auto` asks the compiler to infer a type; it is not Python-style dynamic typing. A lambda is an inline callable:

```cpp
auto twice = [](int x) { return 2*x; };
```

`[&]` captures surrounding variables by reference; the callable must not outlive those variables. `decltype(expression)` inspects an expression's type without executing it. You can solve early problems without templates and learn them in 09 and 12.

## What comes later

Multiple source files, linkage, inheritance and virtual dispatch, move semantics in custom resource-owning classes, iterators in depth, concurrency, atomics, and hardware I/O need additional study. This track deliberately focuses first on logic, safe data handling and the standard library patterns you can apply immediately.
