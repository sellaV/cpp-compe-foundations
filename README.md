# C++ CompE Foundations

**24 original, LeetCode-style challenges for a Computer Engineering student interested in automation, robotics, computer vision and edge AI.**

Start with filtering noisy measurements and parsing commands. Work toward robot path planning, stateful controllers, image processing and tensor operations. You will learn C++ syntax through useful logic problems instead of print-and-arithmetic drills.

This is a foundation track, not a complete replacement for college courses or production robotics training. It uses standard **C++17**, with no OpenCV, ROS, GPU, or external C++ libraries required.

## Start here

You should recognize variables, `if`, loops, and functions in at least one language. A short [C++ bridge from Python](docs/CPP_BRIDGE.md) supplies the syntax you need for the first challenge.

1. Follow [setup instructions](docs/SETUP.md) for Windows, Linux or macOS.
2. Read [problem 01](problems/01_stable_compaction/README.md).
3. Implement its function in `problems/01_stable_compaction/starter.hpp`.
4. Run the tests from the repo root:

```bash
python tools/run.py 01
```

On Linux/macOS use `python3` if `python` is unavailable. No Python packages are required.

The first run intentionally fails with a `TODO` message until you implement the function. Every starter compiles. Each problem provides its contract, example, hints, tests, and a separate explained reference solution. A failed assertion reports the expression and line. Unexpected exceptions are reported rather than silently ignored.

```bash
python tools/run.py --list                 # List challenges
python tools/run.py 05                     # Test YOUR moving average
python tools/run.py 05 --reference         # Compare with the reference (doesn't edit your work)
python tools/run.py all --reference        # Check the reference suite
python tools/run.py 05 --sanitize          # Optional memory/undefined-behavior check
```

## Curriculum

| Stage | Problems | What you learn | Engineering connection |
| --- | --- | --- | --- |
| 1. Core logic | 01–04 | Loops, const references, vectors, hash maps, optional, string parsing | Sensor filtering and telemetry |
| 2. Algorithms and bits | 05–08 | Sliding windows, binary search, sorting, structs, bit masks | Signal windows, reservations, registers |
| 3. C++ design | 09–12 | Classes, templates, encapsulation, unique ownership, callables | Buffers, controller state and resource lifetimes |
| 4. Robot algorithms | 13–16 | BFS, Dijkstra, dependencies, persistent numerical state | Route planning, task execution, PID |
| 5. Vision | 17–20 | Row-major images, borders, geometry, greedy suppression | Cropping, blur, IoU and NMS |
| 6. Edge AI | 21–24 | Numerical stability, narrowing, matrix shapes, tensor layout | Softmax, int8 quantization and preprocessing |

See the [full roadmap](docs/ROADMAP.md) for links, prerequisites and pacing. Warm-ups still require real logic; Core tasks build reusable patterns; Stretch tasks need more design or algorithmic reasoning. Difficulty labels are local to this track, not official LeetCode ratings.

**Dependency:** problem 20's starter includes problem 19's starter. Finish IoU before NMS. Reference mode uses only reference files, so you can verify the package even before solving anything.

## How to practice

- Spend 25–45 minutes on a serious attempt before opening Hint 1.
- Write a tiny input by hand and trace your variables. Explain your invariant.
- Read compiler errors from the first error downward. Fix one cause at a time.
- Try Hint 2 before the solution. After reading a solution, close it and rewrite it yourself later.
- Add a test for an empty input, a boundary, and a case your first approach mishandled.
- Record your time/space complexity and what C++ concept you learned in [PROGRESS.md](PROGRESS.md).

Passing provided tests is a useful check, not a proof. Check the full contract and complexity; tests cannot distinguish every inefficient or hard-coded implementation.

## Layout

```text
problems/01_stable_compaction/
    README.md       problem + expandable hints + solution explanation
    starter.hpp     your implementation
    test.cpp        runnable checks you can extend
    solution.hpp    reference implementation
tests/check.hpp     tiny test helpers (no dependencies)
tools/run.py        selects, compiles and runs challenges
docs/               setup, C++ bridge, roadmap, debugging, capstones
PROGRESS.md         learning log
```

The headers include a shared set of standard headers for convenience. After solving, remove unnecessary includes as a cleanup exercise. Prefer specific headers in real projects. Starter placeholders can produce unused-parameter warnings; these disappear when you implement the parameters' logic.

## After the challenges

Build one of the [three capstone projects](docs/CAPSTONES.md). These require integrating modules and making design choices, so they complement algorithm drills. Then extend your learning toward concurrency, build systems, numerical methods, controls, ROS, OpenCV and hardware integration as your courses and projects require.

## GitHub checks

The included GitHub Actions workflow tests all references, compiles learner interfaces, and runs references with sanitizers. It does **not** require every unfinished learner task to pass. Run a specific learner test locally while solving it. Sanitizer support depends on compiler/platform; Linux GCC/Clang is the intended environment.

All exercises and implementations in this repository are original. No paid problem statements or solutions were copied.
