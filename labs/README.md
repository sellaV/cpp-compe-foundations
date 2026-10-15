# Four practical workflow labs

Use these alongside the [roadmap](../docs/ROADMAP.md). Commands assume a WSL/Linux terminal at the repository root. Work on your own branch. There is no stopwatch or leaderboard.

## Lab 1 — Git from the first exercise

Read `git status`, then create a branch with an unused name, for example:

```bash
git switch -c learn/core-01
python3 tools/run.py 01
git diff -- problems/01_second_largest/starter.hpp
```

Implement the exercise, rerun it, and stage only files you intended to change:

```bash
git add problems/01_second_largest/starter.hpp
git diff --staged
git commit -m "Implement second-largest scan with explicit presence flags"
git log --oneline -3
```

A branch names a line of work; a commit saves a snapshot; `push` uploads commits to a remote. Push your learning branch when you want a remote backup. Do not commit build outputs. To examine an earlier file safely, use `git show COMMIT:path/to/file` with an actual commit hash from your log. This displays content without replacing your current file.

**Done:** Show one focused commit and explain its diff. Write down how a commit differs from saving a file in VS Code. The [Git video](https://www.youtube.com/watch?v=S7XpTAnSDL4) is an optional explanation companion.

## Lab 2 — Compile, link, then run

The project includes a working command-line shell and an unfinished analysis function. These commands build the learner code without solving it:

```bash
mkdir -p build/labs
g++ -std=c++17 -Wall -Wextra -Wpedantic -g -c projects/text_report/main.cpp -o build/labs/main.o
g++ -std=c++17 -Wall -Wextra -Wpedantic -g -c projects/text_report/analyzer.cpp -o build/labs/analyzer.o
g++ build/labs/main.o build/labs/analyzer.o -o build/labs/text_report
./build/labs/text_report projects/text_report/sample.txt
```

The unfinished implementation reports a TODO error; successful linking is the milestone here. A header declares what a function looks like. Each .cpp compiles to an object file. Linking joins those objects and resolves function references.

Try linking only `main.o` to a different output filename. Observe the undefined reference to `analyze`; restore the complete link command. A syntax error happens while compiling; this missing-definition error happens while linking; a TODO exception or wrong answer occurs after running.

**Done:** Explain all three failure stages and why a header alone does not supply this function's implementation.

## Lab 3 — Trace a real logic bug

Complete core 03 first and run `python3 tools/run.py 03`. On a separate Git branch, deliberately change its rotation so that it overwrites a value before saving it. Run the test and identify the first failing case.

With GDB installed in WSL (`sudo apt install gdb` if needed):

```bash
gdb build/03_rotate_references-learner
```

Use `list` to inspect source and `break path/to/file:LINE` with the actual line inside your modified function. Then use `run`, `next`, and `print a` (or the actual parameter name) to inspect the variables before and after each assignment. `backtrace` shows the calling functions; `quit` exits. VS Code's C++ debugger can perform the same actions if configured.

Fix the bug and rerun tests. Later, use `python3 tools/run.py 13 --sanitize` on your pointer implementation. Sanitizers can detect some invalid accesses and undefined behavior; they do not prove your answer is logically correct.

**Done:** Record the first assignment where actual state differs from expected state, why it differs, and a test input that exposes it.

## Lab 4 — Tests that protect behavior

After core 18, inspect its contract and tests. Add a case that checks a failed inventory update leaves both the affected item and an unrelated item unchanged. Avoid merely copying an existing assertion with another ordinary number.

1. State the behavior your test protects.
2. Confirm your correct solution passes.
3. Temporarily introduce a matching bug, such as changing stock before validating an operation.
4. Confirm the new test fails, then remove the bug and rerun.
5. Commit the test and explanation, with the intentional bug removed.

This deliberate defect is a small mutation check: it shows that your test can distinguish correct behavior from a plausible error. Do not weaken the assertion to make an implementation pass.

**Done:** Explain what regression your test would catch and what it cannot establish. Repeat this routine for one independent project feature.
