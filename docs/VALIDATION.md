# Package validation

Validated on 2026-10-14 with GCC 13.3.0 on Ubuntu, C++17.

- All 24 reference solutions passed: 3643 checks in total, including deterministic comparisons with standard lower_bound, a FIFO buffer model, and Floyd-Warshall shortest distances.
- All 24 learner interfaces compiled before implementation.
- Unfinished problem 01 reported its TODO exception and a nonzero exit status as intended.
- All 24 reference suites passed AddressSanitizer and UndefinedBehaviorSanitizer checks with leak detection disabled. LeakSanitizer's process inspection is blocked in the preparation environment, so leak checking is not verified here.
- No compiler warnings in the reference suite. Unused-parameter warnings in unfinished starters are expected.

Commands used:

```bash
python3 tools/run.py all --reference
python3 tools/run.py all --compile-only
ASAN_OPTIONS=detect_leaks=0 python3 tools/run.py all --reference --sanitize
```

The GitHub Actions workflow is supplied but has not been run on GitHub. Windows/macOS setup instructions are included, but execution was only validated on Linux. Provided checks verify selected examples, edge cases and algorithm comparisons; they are not a formal proof for every possible input.
