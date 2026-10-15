# Understanding C++ through what you already know in Python

You do not need to finish this page before exercise 01. **For now, read only Stage 1 and try its examples.** Read later stages when you reach their exercises.

Each section follows this order: a familiar Python idea → its C++ form → what the symbols mean → what you need for the exercises. The examples demonstrate concepts without giving away exercise solutions.

## First: how do you read a line of C++?

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

Break the C++ into pieces:

| Syntax | Meaning here |
| --- | --- |
| `std::` | The following name belongs to the C++ standard library |
| `vector` | A sequence that can grow and shrink, somewhat like a list |
| `<int>` | This sequence contains int elements |
| `numbers` | The variable name |
| `{4, 7, 2}` | The initial values |
| `;` | The end of a statement |
| `.push_back(9)` | Add 9 to the end |

A vector is not identical to a Python list: its elements have one type, and it has memory rules you will learn later. To start, use vector<int> as a sequence of integers.

Most short snippets below are **pieces of code inside a function**, not complete programs. See [CPP_BRIDGE.md](CPP_BRIDGE.md) for a complete program you can run. Do not add main to an exercise starter: the tests already provide it.

## Stage 1 — Enough to start exercises 01–04

### 1. Types: C++ wants to know what a variable holds

Python:

```python
count = 3
average = 2.5
```

C++:

```cpp
int count = 3;
double average = 2.5;
```

- `int`: a whole number, which can be negative.
- `double`: a floating-point number.
- `bool`: true or false.
- `std::string`: a string.

In Python, you can reassign a name to an object of a different type. In C++, a variable's type is determined when it is declared.

```cpp
auto count = 3;  // The compiler infers that count is an int.
```

`auto` saves you from spelling out the type. count is still an int; it does not become dynamically typed.

Another important difference:

```cpp
int a = 5 / 2;        // 2: both operands are integers.
double b = 5.0 / 2;   // 2.5: one operand is floating-point.
```

Use `numbers.size()` to get a vector's length. It returns `std::size_t`, an unsigned integer type used for sizes. It cannot represent a negative number. You do not need all its arithmetic rules yet; for now, do not subtract 1 from a size of 0 and use the result as an index.

### 2. Looping over a vector is similar to Python for

Python:

```python
for number in numbers:
    if number > 5:
        print(number)
```

C++:

```cpp
for (int number : numbers) {
    if (number > 5) {
        std::cout << number << '\n';
    }
}
```

`int number : numbers` takes each element in turn and puts a copy in number. Braces group the statements belonging to the loop or if, doing the grouping that indentation does in Python. You should still indent for readability.

| Python | C++ |
| --- | --- |
| `and` | `&&` |
| `or` | `||` |
| `not` | `!` |
| `True`, `False` | `true`, `false` |
| `len(numbers)` | `numbers.size()` |
| `numbers.append(x)` | `numbers.push_back(x)` |

### 3. Function signatures: the return type comes first

Python:

```python
def is_positive(number):
    return number > 0
```

C++:

```cpp
bool is_positive(int number) {
    return number > 0;
}
```

Read it left to right: the function returns bool, is named is_positive, and receives an int named number. A return type of void means the function does not return a value.

### 4. Do you pass a copy or change the caller's object?

This difference matters. Avoid reducing Python's behavior to “everything is passed by reference.” A Python parameter is bound to the supplied object: modifying a mutable object and rebinding the parameter name are different operations.

Python:

```python
a = [1, 2]
b = a
b.append(3)
# a is also [1, 2, 3]: both names refer to the same list.
```

C++ with a vector:

```cpp
std::vector<int> a{1, 2};
std::vector<int> b = a;  // Create a separate vector by copying the elements.
b.push_back(3);
// a is still {1, 2}.
```

To give the same vector another name, use a reference:

```cpp
std::vector<int>& b = a;
b.push_back(3);
// a is now {1, 2, 3}.
```

In this declaration, `&` makes b **another name for a**, rather than a new vector. Once a reference is bound to an object, it cannot be rebound to a different object.

Now look at function parameters:

```cpp
void change_copy(int x) {
    x = 99;
}

void change_original(int& x) {
    x = 99;
}

int value = 5;
change_copy(value);      // value is still 5.
change_original(value);  // value becomes 99.
```

| Parameter | How to understand it |
| --- | --- |
| `int x` | The function gets a copy of the supplied integer |
| `int& x` | x gives the function direct access to the caller's integer |
| `std::vector<int> values` | A vector passed by value; passing an existing vector variable normally copies it |
| `std::vector<int>& values` | The function can modify the caller's vector |
| `const std::vector<int>& values` | Use the existing vector without copying it into the parameter, and do not modify it through values |

Split `const std::vector<int>& values` into three ideas:

1. `std::vector<int>`: a sequence of integers.
2. `&`: use the supplied object directly.
3. `const`: read-only access through this name.

const here does not permanently freeze the caller's object. The caller can still modify a non-const vector after the function returns.

### 5. optional: roughly “an int or None”

Suppose a function searches for a number. Sometimes it finds nothing. Python can return None, but a C++ function returning int cannot use None that way.

```cpp
std::optional<int> answer;   // No value yet.
answer = 12;                 // Now contains the value 12.
answer = std::nullopt;        // Back to having no value.
```

An optional<int> has **two states**: it contains an int, or it does not. It is not an int with a special default number.

| C++ | Similar Python meaning |
| --- | --- |
| `std::optional<int> answer;` | `answer = None` |
| `answer = 0;` | `answer = 0`: a value exists, even though it is zero |
| `answer = std::nullopt;` | `answer = None` |
| `if (answer)` | Similar to `if answer is not None`, not Python's `if answer` |
| `*answer` | Retrieve the contained int after checking that it exists |

```cpp
std::optional<int> answer = 0;
if (answer) {
    std::cout << *answer << '\n';  // Prints 0: this branch still runs.
}
```

**Do not use 0 to mean “not found yet” when 0 is valid input.** Negative numbers can be valid input too. This is why exercise 01 uses optional.

Only use `*answer` when it contains a value. Here, `*` accesses the value inside an optional. In Stage 4, you will meet the same symbol used with pointers.

### 6. struct: name the parts of a result

In Python, you might use a tuple, dict or dataclass to group related data. A simple C++ struct gives fields names:

```cpp
struct Point {
    int x;
    int y;
};

Point p{2, 5};
std::cout << p.x << '\n';  // 2
```

Point is a new type, p is an object of that type, and x and y are its fields. You do not need inheritance or complicated constructors for exercises 02 and 04.

### Before attempting exercise 01

You only need to explain:

- What does a vector contain, and how do you loop over it?
- What does `const ...&` mean in a parameter?
- How is “no value yet” different from zero?
- What different jobs do `if (answer)` and `*answer` perform?

You do not need pointers, advanced templates or RAII yet. A **contract** is the exercise's input/output requirements. An **invariant** is something you keep true after each step, such as “count is the number of matching elements in the part examined so far.”

## Stage 2 — Strings and vectors (05–08)

### string owns its data; string_view looks at existing data

```cpp
std::string text = "hello";
std::string_view view = text;
```

text manages its characters. view refers to those characters without creating an independent string.

**Borrowing** means using existing data without taking responsibility for keeping it alive. **Ownership** means managing data or a resource and its cleanup. These are descriptions of behavior, not C++ keywords.

If text is destroyed or its character storage is replaced, view may no longer be valid. Return a string when you need an independent result. You do not need to force string_view into every exercise to avoid copies.

### Size and capacity are different

```cpp
std::vector<int> values;
values.reserve(10);
// values.size() is still 0: no elements exist yet.
values.push_back(7);
// Now size is 1, and values[0] is 7.
```

reserve prepares storage; it does not add elements. `values.at(i)` checks the index and throws an exception if it is outside the vector. `values[i]` requires you to ensure the index is valid; an invalid index is not guaranteed to produce a readable error.

### An iterator is a position used to traverse a container

Python usually hides this inside for. C++ lets you pass start/end positions to an algorithm:

```cpp
std::reverse(values.begin(), values.end());
```

begin is the first position; end is **just after the last element**. The algorithm processes begin up to, but not including, end. This is the range `[begin, end)`. Do not read `*values.end()`.

If push_back makes a vector allocate new storage, pointers, references and iterators into the old storage become invalid. To start, avoid keeping them across operations that may add elements.

**Check yourself:** Does reserve add elements? Is end the last element? Does a returned string remain usable after its input is destroyed?

## Stage 3 — Using containers to solve problems (09–12)

### unordered_map is similar to dict

Python:

```python
positions = {"cat": 2}
if "cat" in positions:
    index = positions["cat"]
```

C++:

```cpp
std::unordered_map<std::string, int> positions{{"cat", 2}};
auto it = positions.find("cat");
if (it != positions.end()) {
    int index = it->second;
    (void)index;
}
```

- find returns the position of the entry, or end if it is absent.
- `it->first` is the key; `it->second` is the value.
- C++ `positions["missing"]` can **insert** a new key with an int value of 0. Reading a missing key from an ordinary Python dict raises KeyError. Use find for lookup without insertion.
- `(void)index;` only suppresses an unused-variable warning in this short example.

### Understand complexity as the amount of work

| Notation | A way to picture it |
| --- | --- |
| O(n) | Visit n elements with a fixed amount of work at each step |
| O(n²) | For example, try every pair of elements |
| O(log n) | For example, discard about half the remaining search area each step |

unordered_map normally has average O(1) lookup, but this is not guaranteed for every case. Exercise 09 compares trying every pair against remembering previously seen values.

Binary search needs ordered input. A sliding window tracks a contiguous section rather than recalculating everything for every section. Read the contract and trace an example before choosing a pattern.

For exercises 10/12, char may be signed on some systems. Use `static_cast<unsigned char>(c)` when using a byte to index a 256-entry table. These exercises process bytes, not complete Unicode characters.

**Check yourself:** What does find return when absent? Why might [] modify a map? Where does each binary-search iteration shrink the search area?

## Stage 4 — Pointers, lifetime, ownership and recursion (13–16)

### A pointer holds an address; a reference is another name for an object

```cpp
int value = 10;
int* pointer = &value;
*pointer = 25;
// value is now 25.
```

Read it line by line:

1. Create an integer named value containing 10.
2. `int*` means pointer to int; `&value` obtains value's address.
3. `*pointer` accesses the object at that address; assigning 25 changes value.

The meaning of & depends on its position: `int& alias = value` declares a reference; the expression `&value` obtains an address. Likewise, `int*` names a pointer type, while `*pointer` accesses an object through a pointer.

A pointer can be nullptr, meaning it points to no object. Do not use `*pointer` when it is nullptr. A pointer does not carry an array's length, so exercise 13 takes both data and n.

`const int*` allows reading the int but not changing it **through this pointer**. Exercise 16 has two overloads: functions with the same name but different parameter types. One accepts int* for mutable access; one accepts const int* for read-only access.

### Lifetime: how long does the object exist?

```cpp
int* bad_example() {
    int local = 5;
    return &local;  // Wrong: local is destroyed when the function returns.
}
```

This is an intentionally incorrect example: do not run or copy it as a solution. Returning an address does not keep local alive. A **dangling pointer/reference/view** refers to an object or storage that is no longer valid. A non-null address can still be dangling.

### unique_ptr gives one owner responsibility for cleanup

```cpp
auto owner = std::make_unique<int>(7);
int* observer = owner.get();
auto new_owner = std::move(owner);
```

- make_unique creates an object and returns a unique_ptr managing it.
- get provides an observing pointer; observer does not manage cleanup.
- The last line transfers ownership to new_owner. For unique_ptr, the old owner becomes empty.
- The int object stays in the same place, so observer remains valid **while that object exists**.
- When the remaining owner is destroyed or reset, the object is released. Do not use observer afterward.

unique_ptr prohibits copying because ownership is exclusive. std::move enables move operations; it does not mean every type is erased or emptied after a move. The behavior depends on the type. Exercise 20 asks you to define your class's moved-from state.

### Recursion and backtracking

Recursion means a function calls itself, with a stopping condition. Backtracking often follows three steps: add a choice → explore it recursively → undo the choice before another branch.

Python `result.append(current)` keeps a reference to the same list, so you often need `current.copy()`. With a C++ vector<vector<int>>, `result.push_back(current)` copies the current vector into an independent element. This difference matters in exercise 15.

**Check yourself:** Who owns each node in exercise 14? How long must the input stay alive for exercise 16's returned pointer? Why undo a choice after a recursive branch?

## Stage 5 — Classes, copy/move and polymorphism (17–20)

### How does a simple class compare with Python?

Python:

```python
class Counter:
    def __init__(self, start):
        self.value = start

    def increment(self):
        self.value += 1
```

C++:

```cpp
class Counter {
    int value_;
public:
    explicit Counter(int start) : value_(start) {}
    void increment() { ++value_; }
    int value() const { return value_; }
};
```

- Counter(int start) is a constructor, with an initialization role similar to __init__.
- `: value_(start)` initializes the member value_ using start.
- Members before public are private by default: outside code cannot access them directly.
- Inside a member function, use value_ directly; you do not need self.value.
- const after value() says this method does not modify the object's ordinary state.
- explicit prevents some unintended implicit conversions. You do not need its full rules to read this example.

A **class invariant** is something the class must maintain, such as “stock is never negative.” The constructor establishes it; methods must preserve it after valid operations.

### Copying differs from Python assignment

For a typical class containing vector/map/string values, `auto b = a` copies those members, giving b separate data. Python `b = a` binds another name to the same instance.

Some classes intentionally forbid copying, for example when they own a resource exclusively. Exercise 20 teaches a move-only class. Distinguish these operations:

| C++ | What is happening? |
| --- | --- |
| `Thing b = a;` | Create b from a: copy construction |
| `b = a;` when b already exists | Replace b's value: copy assignment |
| `Thing b = std::move(a);` | Create b using a suitable move constructor if available |
| `b = std::move(a);` | Use a suitable move-assignment overload if available |

The **Rule of Zero** is a design guideline: when containers/smart pointers already manage resources, avoid custom destruction/copy/move operations unless needed. Exercise 20 has an extra moved-from-state requirement, so it needs additional handling.

### virtual and override

Python commonly chooses methods from the actual object at runtime. In C++, declare a method virtual when calling through a base pointer/reference should use derived behavior.

Exercise 19 supplies the Shape interface. area is virtual; Rectangle and Square use override. clone creates a new object of the same actual type. Copying a derived object into a base object by value can lose the derived part: this is **slicing**. Destroying a derived object through a base pointer requires a virtual base destructor; the supplied interface includes one.

**Check yourself:** What must always be true about Fraction? Are Inventory copies independent? What must happen to size after moving from exercise 20's buffer?

## Stage 6 — STL, lambdas, templates and iterators (21–24)

### A lambda is a small function written where you need it

Python:

```python
twice = lambda x: x * 2
```

C++:

```cpp
auto twice = [](int x) { return x * 2; };
int result = twice(5);  // 10
```

The brackets describe captures: `[offset]` keeps a copy of an outside variable; `[&offset]` refers to the outside variable itself. Reference capture does not extend that variable's lifetime.

### A template lets one implementation work with multiple types

```cpp
template<class T>
T identity(T value) {
    return value;
}
```

Call it with an int and T is inferred as int; with a string, T is string. The compiler instantiates a suitable version. Types are still checked during compilation, unlike Python's runtime typing.

Exercise 21 determines its output element type from a callable. Only when you reach it, learn these pieces:

| Syntax | How to understand it for the exercise |
| --- | --- |
| `decltype(expression)` | Ask the compiler for an expression's type without executing it |
| `std::declval<const T&>()` | Describe a const T& input in an unevaluated type query; do not call it at runtime |
| `std::decay_t<...>` | Remove references and relevant const qualifications to obtain a value type that can be stored in a vector |
| `typename std::iterator_traits<It>::value_type` | The type of element accessed by iterator It; typename identifies this as a type name |

You do not need to memorize these long names before exercise 01. When you reach them, read the pieces separately.

### Standard algorithms and comparators

```cpp
std::sort(values.begin(), values.end(), [](int a, int b) {
    return a > b;
});
```

The comparator returns true when a should come before b. Use > for descending order, not >=: equal elements must not both be considered strictly before each other. stable_sort preserves input order for elements equivalent according to the comparator.

Exercise 24 uses iterators to work with both vector and list. Do not assume every iterator supports subtraction or indexing; list iterators can advance with ++ for this exercise.

**Check yourself:** How is a template different from Python's dynamic typing? Why is >= wrong in a sorting comparator? Why does testing with list reveal interface mistakes?

## Stage 7 — Parsing, streams, exceptions and RAII (25–28)

### Streams let one algorithm read from strings or files

```cpp
std::istringstream input("12 34");
int number;
while (input >> number) {
    std::cout << number << '\n';
}
```

`input >> number` tries to read and convert data into number. The loop continues only when extraction succeeds. istringstream reads a string; ifstream reads a file. A function taking istream& can work with both.

```cpp
std::ifstream input("numbers.txt");
if (!input) {
    throw std::runtime_error("Cannot open numbers.txt");
}
```

Include <fstream> for file streams. Do not use `while (!input.eof())` to predict whether another read will succeed. Try the read and check its result.

Simple integer extraction is not enough for exercise 25: "3x" can be partially read as 3. The exercise requires checking an entire token, so use from_chars and check both its error code and stopping position.

### optional or an exception?

- optional: the API allows “no result” as an ordinary outcome.
- exception: the API reports that the operation could not be completed as requested.

Python uses raise; C++ uses throw. Python uses try/except; C++ uses try/catch. Follow the error behavior specified in each exercise rather than switching between these mechanisms yourself.

variant<int,bool,string> holds one of those three types. holds_alternative checks the active type; get retrieves the corresponding value. optional<variant<...>> adds parse failure as a separate state, different from int 0, bool false or an empty string.

### RAII: an object cleans up when it leaves scope

Python often uses `with open(...) as file:` to close a file even when an exception occurs. C++ uses objects whose destructors perform cleanup when their lifetime ends.

```cpp
{
    std::ifstream file("notes.txt");
    // Use file here.
} // file is destroyed, closing its file resource automatically.
```

A destructor is written ~ClassName(). It also runs when an exception causes execution to leave that object's scope. RAII names the practice of tying resource cleanup or state restoration to object lifetime.

Exercise 28 applies this idea to saving/restoring stream formatting. The guard borrows the stream: the stream must remain alive until the guard's destructor finishes. Cleanup destructors should not throw exceptions.

**Check yourself:** Which function can accept both file and string input? How is invalid content different from EOF? Why does a guard restore state even when an exception occurs?

## If a line is still hard to read

Do not memorize every term at once. For the line you are reading, identify the types, variable names and function calls. Then ask whether data is copied or accessed directly, and which objects must stay alive. Work through that line before moving to the next topic.
