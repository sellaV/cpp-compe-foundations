# C++ concepts before challenges

Read one stage, solve its tasks, then explain the checkpoint without looking. This is a short companion, not an exhaustive language reference.

## Stage 1 — Types, functions and references (01–04)

C++ variables have static types. auto infers a type at compile time, not dynamic typing. int is signed; size_t is unsigned and used for sizes. Subtracting from unsigned zero wraps; signed overflow is undefined behavior. Choose types deliberately.

```cpp
void append_marker(std::string& text) { text.push_back('!'); }
std::size_t length(const std::string& text) { return text.size(); }
```

A T parameter is a separate parameter object; T& aliases the caller; const T& borrows without mutation through that reference. T copy = value copies; T& alias = value does not. Reference parameters may alias each other, so some contracts require distinct objects.

optional<T> represents either a value or absence. Check engagement before dereferencing. A sentinel is unsuitable when it is also a valid result. A struct groups named results. Returning a container by value is safe; returning a reference to a local container is not.

**Checkpoint:** explain duplicate maximums in 01, why 03 needs references, and which results own storage.

## Stage 2 — Strings, vectors and invariants (05–08)

vector owns a dynamically sized sequence. push_back may reallocate, invalidating pointers, references and iterators into old storage. reserve changes capacity, not size: indexing an empty reserved vector is still invalid. at checks bounds; [] assumes valid indices.

string owns bytes. string_view borrows bytes and does not extend their lifetime or guarantee null termination. A view into a temporary string can dangle. Exercises use ASCII/bytes rather than Unicode character processing.

An iterator marks a position. Algorithms usually accept half-open [begin,end) ranges; end must not be dereferenced. Reversing elements does not invalidate vector iterators, while reallocating does.

**Checkpoint:** state merge's invariant, explain why bracket counts are insufficient, and compare a string result with a borrowed view.

## Stage 3 — General algorithms (09–12)

Learn patterns: earlier-value lookup for two sum, frequency tables, shrinking binary-search intervals and moving window boundaries. unordered_map has average constant-time lookup, not guaranteed constant time. find does not insert; operator[] may insert a default value.

char may be signed. Convert bytes to unsigned char before using them as indices in a 256-entry table. Binary search requires sorted input and a strictly shrinking search interval.

**Checkpoint:** compare O(n²), expected O(n) and O(log n). Explain why a window start must not move backward.

## Stage 4 — Pointers, lifetime and recursion (13–16)

T* holds an address, not an ownership or array-length guarantee. Dereference only a valid live pointer. Arithmetic must stay in its array or one-past; one-past cannot be dereferenced. Do not perform arithmetic on nullptr for an empty range.

const T* cannot modify T through the pointer. T* const is a pointer variable that cannot be rebound. A mutable/const overload can preserve the caller's access rights.

```cpp
auto owner = std::make_unique<std::string>("hello");
const std::string* observer = owner.get();
auto new_owner = std::move(owner);
// observer still points to the same string, now owned by new_owner.
```

std::move is a cast enabling move operations, not an instruction to move arbitrary bytes. unique_ptr transfers ownership and releases the object on destruction. get observes without transferring ownership. A borrowed pointer becomes invalid when its owner destroys the object; functions cannot generally detect dangling non-null pointers.

Recursion needs a base case and progress toward it. Backtracking makes a choice, recurses and undoes it. Copy output snapshots instead of saving references to one mutable working vector.

**Checkpoint:** draw ownership for 14, explain when 16's result becomes invalid, and trace recursive push/pop in 15.

## Stage 5 — Classes and semantics (17–20)

Constructors establish invariants; private data helps prevent bypasses. const methods run on const objects. Operators should respect meaning: adding value objects should not unexpectedly mutate them.

Prefer the Rule of Zero: standard containers and smart pointers handle resources. A map-backed inventory copies independently without a custom destructor. Custom move behavior is needed when the contract has additional state to maintain, such as a zero size in a moved-from buffer.

Copy construction creates an object; copy assignment replaces an existing value. Move construction and assignment are distinct operations too. Deleting copy operations does not automatically provide usable move operations. Choose and test self-assignment/self-move behavior.

A virtual method dispatches through the dynamic type. Use override and a virtual destructor when destroying via base pointers. Copying a derived object into a base value can slice derived state; virtual cloning preserves dynamic type. Use value types/composition when runtime polymorphism is unnecessary.

**Checkpoint:** state every class invariant, explain independent copies, and explain why a defaulted move would not reset a separate size field in 20.

## Stage 6 — STL, templates and iterators (21–24)

Templates generate typed implementations. A callable template accepts lambdas, functors and function pointers. Capturing by reference does not extend the referenced object's lifetime.

decltype observes an expression's type without executing it. decay_t removes reference/cv qualifiers for stored values. typename marks dependent type names, e.g. typename iterator_traits<It>::value_type.

Iterator interfaces work beyond vectors. list iterators increment but do not support indexing or subtraction. Sort comparators must define strict weak ordering: comp(x,x) must be false. Use > for descending order, not >=. Hash-table iteration cannot supply stable group order unless you maintain it separately.

**Checkpoint:** run generic functions with multiple types and containers; explain why list tests expose random-access assumptions.

## Stage 7 — Streams, errors and RAII (25–28)

optional represents ordinary absence/parse failure when specified; exceptions signal errors when the API requires them. Validate before mutation if failure must leave state unchanged. Tests should check the remaining state after failure.

istream/ostream separate the algorithm from the source/destination. Stringstreams make tests easy; real programs can pass file streams instead:

```cpp
#include <fstream>
std::ifstream input("notes.txt");
if (!input) throw std::runtime_error("cannot open notes.txt");
auto stats = summarize_lines(input);
// The file closes automatically when input leaves scope.
```

Loop on successful extraction/getline, not while(!eof()). EOF, malformed data and I/O failure are distinct. from_chars reports an error code and where parsing stopped: check both for strict validation.

variant owns one of a fixed set of types. holds_alternative checks which one; get of the wrong type throws. optional<variant<...>> adds a distinct failure state.

RAII binds cleanup to object lifetime. A destructor runs during normal exit and exception unwinding and should not throw. A formatting guard borrows a stream and restores its flags/precision; the stream must outlive it. Nested guards restore nested snapshots. The same idea applies to locks and files.

**Checkpoint:** distinguish parse and stream failures, demonstrate a real file-backed caller, and explain why cleanup still happens after an exception.

## Later study

Learn build systems, deeper exception guarantees, profiling, concurrency/atomics, networking and platform APIs separately. Build a general project before moving to the optional engineering track.
