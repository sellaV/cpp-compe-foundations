# Validation: practical curriculum revision

Checked locally with GCC in C++17 mode on Linux:

- All retained reference suites pass: 18 core, 13 later, 22 applied.
- All 18 core learner interfaces compile; retained exercise implementations and interfaces are unchanged by this revision.
- The text-report learner project compiles; its unfinished implementation intentionally fails runtime tests.
- The reference project passes unit tests and actual CLI checks, including empty input, missing paths, CRLF, spaces in filenames, invalid argument counts, and stream failures.
- The reference project passes AddressSanitizer and UndefinedBehaviorSanitizer with local leak detection disabled.
- Local Markdown links resolve, and each curriculum manifest matches its exercise directories.

CMake is not installed in the preparation environment. The GitHub Actions project job verifies both reference and learner CMake builds, runs reference CTest checks, and checks project sanitizers. The existing track jobs check references, starter compilation, and sanitizers for each retained track.

LeakSanitizer process inspection is unavailable locally, so local checks do not establish leak freedom. Tests do not prove correctness for every possible input, enforce every teaching restriction, or certify learner mastery.
