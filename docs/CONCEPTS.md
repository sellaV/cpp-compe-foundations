# Core C++ concepts for someone coming from Python

**Read Stage 1 before exercise 01. Read other stages only when you reach them.** Libraries such as optional, hash maps and smart pointers now belong to the [later guide](LIBRARIES.md).

The goal is to understand what your code does before learning convenient APIs for doing it. vector/string remain simple storage tools; you are not expected to implement a memory allocator first.

## First: reading a C++ line

Python:

```python
numbers = [4, 7, 2]
numbers.append(9)
```

C++:

```cpp
std::vector<int> numbers{4, 7, 2};
numbers.push_back(9);
```

| Piece | Meaning |
| --- | --- |
| std:: | The following name comes from the standard library |
| vector<int> | A sequence of int elements |
| numbers | The variable name |
| {4, 7, 2} | Initial values |
| push_back(9) | Add 9 at the end |
| ; | End of a statement |

A vector is not identical to a Python list. For now, treat it as a sequence of same-type elements. Its advanced memory behavior can wait until the later track.

Snippets below are usually pieces of a function. [CPP_BRIDGE.md](CPP_BRIDGE.md) explains how to run the supplied complete example. Exercise starters do not need a main: the tests provide it.

## Stage 1 — Values, state, loops and functions (01–04)

### Types and conditions

Python:

```python
count = 3
has_result = False
```

C++:

```cpp
int count = 3;
bool has_result = false;
```

int holds signed integers, double holds floating-point numbers, bool is true/false, and string holds text. A C++ variable has a fixed type. auto can ask the compiler to infer that type, but you can write the type explicitly while learning.

| Python | C++ |
| --- | --- |
| and | && |
| or | \|\| |
| not | ! |
| True / False | true / false |
| len(numbers) | numbers.size() |

Integer division differs from Python's ordinary /: C++ 5/2 is 2, while 5.0/2 is 2.5. Ordinary C++ integer types also have finite ranges; a wider long long is useful when the problem's bounds require it.

### A loop reads one value at a time

```cpp
for (int number : numbers) {
    if (number > 5) {
        ++count;
    }
}
```

Read it as “for each number in numbers.” ++count adds one. Braces group the loop and if bodies; indentation is for readability. An index loop is useful when you need positions:

```cpp
for (std::size_t i = 0; i < numbers.size(); ++i) {
    int number = numbers[i];
    // Use number here.
}
```

size_t is an unsigned size/index type: it cannot represent a negative number. In particular, do not compute size()-1 before checking that a sequence is nonempty.

### Function signatures

```cpp
bool is_positive(int number) {
    return number > 0;
}
```

The function returns bool, is named is_positive and receives an int named number. void means no return value. A function can call another ordinary helper function; no lambda or template is needed.

### Copies and references

Python names can refer to the same list:

```python
a = [1, 2]
b = a
b.append(3)
# a is also [1, 2, 3].
```

C++ vector assignment normally copies an existing vector:

```cpp
std::vector<int> a{1, 2};
std::vector<int> b = a;
b.push_back(3);
// a is still {1, 2}.
```

A reference gives an existing object another name:

```cpp
std::vector<int>& b = a;
b.push_back(3);
// a is now {1, 2, 3}.
```

Likewise, compare function parameters:

```cpp
void change_copy(int x) { x = 99; }
void change_original(int& x) { x = 99; }
```

Calling the first with an int changes only a copy. Calling the second changes the caller's int. const int& would allow reading through the reference without writing through it.

Split **const std::vector<int>& values** into three ideas: vector<int> is the type, & uses the existing object, and const makes access through this parameter read-only. It does not permanently freeze the caller's vector.

### Missing data: use a bool separately from the number

In Python you might use None. For the first exercises, represent that idea explicitly:

```cpp
int result = 0;
bool found = false;

// Later, when a value is found:
result = 0;
found = true;
```

The value 0 and “no result” are different because found records the state independently. Only use result as an answer when found is true. A negative number is also a valid value; do not use it as a missing-value marker unless the contract excludes it.

Exercise 01 uses a small struct to return both pieces:

```cpp
struct SearchResult {
    bool found;
    int value;
};

SearchResult absent{false, 0};
SearchResult zero_found{true, 0};
```

A struct groups named fields. Read zero_found.found to check whether there is a result, then zero_found.value to read it. optional is a useful later way to package the same idea, but is not required here.

### Explain your state before writing conditions

A contract is the input/output requirements. An invariant is something you keep true after each step, such as “count equals the number of matches among elements already examined.”

For exercise 01, decide what each stored number means and which bool says it exists. You do not need to use a numeric sentinel. For exercise 02, build the GCD loop from arithmetic rather than calling a library function.

**Checkpoint:** Can you explain the difference between a missing result and a result of 0? Can you tell which parameter can modify its caller? Can you trace one loop on paper?

## Stage 2 — Sequence operations with loops (05–08)

### Basic vector/string operations are enough

| Operation | Meaning |
| --- | --- |
| values.size() | Number of elements |
| values.empty() | Whether size is zero |
| values[i] | Element at a valid index |
| values.push_back(x) | Append an element |
| values.back() | Last element, only when nonempty |
| values.pop_back() | Remove the last element, only when nonempty |
| values.resize(n) | Change the number of elements |

string supports similar indexing/appending operations for characters. A const string& parameter reads an existing string without copying it into the parameter.

Use loops to scan characters, swap elements, merge sequences and match brackets. A helper can handle a smaller part of a problem. You will later compare your reversal helper with std::reverse.

### Bounds and short-circuit conditions

For a sequence of size n, valid indices are 0 through n-1. Empty sequences have no valid index. In C++, invalid [] access is not guaranteed to raise a readable exception as Python would.

In `i < values.size() && values[i] > 0`, the right side is evaluated only if the left side is true. Ordering checks this way keeps the index access safe.

### Size and capacity

One reference solution uses reserve to prepare storage. reserve does not add elements. A vector with size 0 still has no values[0], even after reserve(100). You may simply omit reserve in your own solution unless a contract requires it.

**Checkpoint:** Can you reverse a segment without calling reverse? Can you explain why an empty input is safe? Which values must you save before overwriting a slot?

## Stage 3 — Plain arrays and search logic (09–12)

A built-in fixed array looks like this:

```cpp
unsigned counts[256]{};
```

This creates 256 counters initialized to zero. Its size is fixed; it has no push_back method. Exercise 09 uses it as a byte-frequency table. char can be signed, so use static_cast<unsigned char>(c) when converting a byte to a 0–255 index.

You will implement binary search manually, try candidate pairs with nested loops, and compact a vector in place. There is no need for a hash map yet.

| Complexity | A practical interpretation |
| --- | --- |
| O(n) | A scan with bounded work per element |
| O(n²) | For example, checking every pair |
| O(log n) | For example, repeatedly halving a search interval |

A simple quadratic baseline can be correct and useful within the stated bounds. Later, compare pair search with a hash-table implementation. You need to understand what work changes, not memorize a large collection of puzzle tricks.

A half-open range [begin,end) includes begin but excludes end. An empty range has begin==end. Binary search should make this range smaller on every iteration.

**Checkpoint:** Can you find the first qualifying index with a loop before optimizing it? Can you explain when an O(n²) approach would become expensive?

## Stage 4 — Borrowed pointers, lifetime and recursion (13–16)

### Reading pointer syntax

```cpp
int value = 10;
int* pointer = &value;
*pointer = 25;
// value is now 25.
```

int* declares a pointer to int. &value obtains its address. *pointer accesses the int at that address. This use of & in an expression differs from & in a reference declaration such as int& alias=value.

nullptr means no object is pointed to. Do not dereference it. A pointer also does not store an array's length, so functions commonly take a separate length.

const int* permits reading through the pointer but not changing the int through it. Two overloads can preserve mutable versus read-only access, as exercise 14 demonstrates.

### Lifetime means how long an object exists

Returning the address of a local variable does not keep it alive. A pointer/reference that refers to a destroyed object is dangling, even if its address is not null.

In these exercises, pointers **borrow** existing objects: the caller keeps the storage alive, and your function does not allocate or delete it. This is enough to learn pointer behavior before smart pointers and allocation.

### Recursion uses ordinary functions

A recursive function calls itself with a smaller problem. It needs a base case that stops the calls. Backtracking adds a choice, recurses, then removes the choice before exploring another branch.

Use a named helper with explicit parameters in exercise 16; no std::function or lambda is necessary. Passing the working vector by reference lets recursive calls update one working sequence. Pushing that vector into vector<vector<int>> copies a snapshot, unlike Python append(current), which retains the same list object.

**Checkpoint:** Which object owns the array? When does a returned pointer become invalid? What shrinks on every recursive call? What change must be undone after a branch?

## Stage 5 — Classes before advanced library design (17–20)

Python:

```python
class Counter:
    def __init__(self, start):
        self.value = start
```

C++:

```cpp
class Counter {
    int value_;
public:
    explicit Counter(int start) : value_(start) {}
    int value() const { return value_; }
};
```

The constructor initializes the object. The part after : initializes the member. Members before public are private in a class. The const after value() means this method does not modify the object's ordinary state. Inside methods, value_ refers to the member without writing self.value.

### Preserve an invariant

A fraction keeps a positive denominator and reduced values. An inventory keeps nonnegative stock. A fixed queue keeps its count in [0,8]. Constructors and methods should preserve these rules.

In early APIs, a failed update returns false and leaves state unchanged when specified. A precondition is different: it is a promise the caller must satisfy, such as a nonzero denominator. Do not confuse these two kinds of contract.

### Copying and virtual methods

For our classes with ordinary arrays/vector/string/value members, a copy has independent value data. Copying classes with borrowed pointers would require more careful lifetime reasoning; do not assume every arbitrary class has independent owned data.

A base interface can declare a virtual method, and derived classes provide override implementations. A reference to the base can refer to a local derived object: dynamic dispatch does not require heap allocation. Exercise 19 uses local Rectangle/Square objects and Shape references, postponing smart pointers and cloning.

Exercise 20 builds a queue using int data_[8] and two indices. Learn the FIFO invariant and circular indexing before using queue/deque abstractions later.

**Checkpoint:** Can you state the class invariant? Does a failed operation leave it intact? Does copying your class change the original? Can you call a derived method through a base reference?

## After the core track

Build a small project or begin [LIBRARIES.md](LIBRARIES.md). Standard-library tools matter: the purpose of postponing them is to make their behavior easier to understand, not to avoid them in real code.
