# Debugging routine

1. Copy the smallest failing test into your notes.
2. Trace each iteration: index, current state, and output so far.
3. State an invariant: what must remain true after every iteration?
4. Check inclusive versus exclusive boundaries and empty inputs.
5. Check numeric types before blaming the algorithm.
6. Add the failing case to `test.cpp` and rerun that problem.

Common traps:

| Symptom | Likely cause |
| --- | --- |
| Average is truncated | Integer division or integer accumulator |
| Loop never ends | Binary-search interval fails to shrink |
| Queue returns the wrong oldest item | Ring-buffer head/count invariant broken |
| Image looks scrambled | HWC/CHW or row/column indexing mixed |
| Pair uses the same element twice | Two-sum insertion happens before lookup |
| Huge probability or NaN | Raw exponentials overflow; nonfinite input |
| Unpredictable memory error | Index out of bounds or borrowed pointer outlives owner |

Compile with warnings enabled. Treat warnings as clues; an unused starter parameter is expected before implementation. For memory/index errors on Linux/WSL run:

```bash
python3 tools/run.py 09 --sanitize
```

In a debugger, put a breakpoint before the failing check, then step through the function. Inspect vector sizes before accessing elements and optional engagement before dereferencing.

The provided `CHECK` helper remains active regardless of `NDEBUG`, unlike `assert`. `THROWS` verifies the specified exception type, though a subtype also matches. Tests report checks and failures; the count is not a score for your coding ability.
