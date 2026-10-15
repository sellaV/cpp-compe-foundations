# Validation of the general curriculum

Validated on 2026-10-14 (America/Chicago), in C++17 mode on Linux.

- General track: 28/28 reference suites pass, 2880 checks total.
- All 28 unfinished general interfaces compile. Their runtime TODO failures are intentional.
- General reference suites pass AddressSanitizer and UndefinedBehaviorSanitizer checks with leak detection disabled. LeakSanitizer process inspection is restricted here; leaks are not locally verified.
- Optional applied track: 24/24 reference suites pass, 3643 checks total.
- General tests include exhaustive small-input comparisons for second distinct maximum, vector rotation and unique-substring windows, plus binary-search oracle comparisons.
- Ownership/class tests verify caller mutation, pointer identity, independent copies, dynamic clone type, moved-from state and exception cleanup.

Commands:

```bash
python3 tools/run.py all --reference
python3 tools/run.py all --compile-only
ASAN_OPTIONS=detect_leaks=0 python3 tools/run.py all --reference --sanitize
python3 applied/tools/run.py all --reference
```

GitHub Actions tests both tracks, including reference sanitizer runs. Passing tests does not prove all inputs or enforce every algorithm restriction; learners must check reasoning, complexity and language contracts themselves. Only Linux execution was locally validated.
