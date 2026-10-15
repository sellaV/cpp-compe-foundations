# Getting started with C++ when you know Python

**Use this page to learn how to try code. Read [Stage 1 of CONCEPTS.md](CONCEPTS.md) to understand the concepts.** You do not need all seven stages yet.

## 1. What does a complete C++ program look like?

```cpp
#include <iostream>

int main() {
    int number = 5;
    std::cout << number << '\n';
    return 0;
}
```

- include makes the relevant library declarations available; iostream provides cout.
- main is where execution starts.
- int before a variable name declares an integer.
- cout sends output to the terminal; '\n' is a newline character.
- Returning 0 from main reports successful completion.

In Python, you normally run a .py file with Python. In C++, first compile the source into an executable, then run that executable.

## 2. Try the example supplied in this repo

Open [python_bridge.cpp](examples/python_bridge.cpp). It demonstrates copies, references and a simple bool/value result struct; it is not the solution to exercise 01.

From the repository root, in your WSL terminal:

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra -Wpedantic docs/examples/python_bridge.cpp -o build/python_bridge
./build/python_bridge
```

Expected output:

```text
After copy: 5
After reference: 6
First negative: -2
Result contains: 0
```

Read it alongside Stage 1 of CONCEPTS.md, then try changing the inputs:

- Change the vector to {4, 2, 0}. Which branch runs when there is no negative number?
- Change the initial number to 10. What will the first two lines print?
- Why does a SearchResult with found=true and value=0 enter the if branch?

After editing C++ source, compile again before running so the executable includes your changes.

## 3. How are exercises different?

Each exercise has four files:

| File | What to do |
| --- | --- |
| README.md | Read the requirements, examples and hints when needed |
| starter.hpp | Implement your function or class |
| test.cpp | Read the checks and add cases of your own |
| solution.hpp | Open after attempting the problem or when you need a comparison |

The starter already supplies includes and the function signature. Fill in the function body. **Do not add main to the starter:** test.cpp already provides it. The runner compiles and runs the tests:

```bash
python3 tools/run.py 01
```

Initially, TODO deliberately throws an exception to indicate that implementation is missing. This is not a setup failure.

## 4. Read errors by category

| Situation | Meaning |
| --- | --- |
| Compiler reports an error | The source cannot be compiled: check syntax, semicolons, names and types |
| Compilation succeeds but a CHECK fails | The program ran but violated a tested requirement |
| Uncaught exception: TODO | A placeholder is still present or your code calls one |
| Running the executable shows old behavior | You may not have recompiled after editing |

If a long function signature is difficult, split it into return type → function name → individual parameters. Stage 1 demonstrates this approach.

## Next

Once you understand copies, references and a simple bool/value result struct in Stage 1, attempt exercise 01. Read string_view and iterators at Stage 2, then pointers/ownership at Stage 4. You do not need to memorize all C++ terminology before solving your first problem.
