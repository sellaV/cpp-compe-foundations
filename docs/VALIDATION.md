# Validation: logic-first curriculum

Validated in C++17 mode on Linux.

- Core: 20/20 reference suites pass (3870 checks); all 20 learner interfaces compile.
- Core reference suites pass AddressSanitizer and UndefinedBehaviorSanitizer with local leak detection disabled.
- Later: 18 reference suites pass; all 18 learner interfaces compile; all 18 reference suites pass the same sanitizer checks.
- The optional applied source/tests are unchanged from the previously successful GitHub run.
- The updated Python-bridge example compiles with warnings enabled and prints the documented output.
- Core starter/solution audit: no optional, map/unordered_map, standard algorithm calls, std::array, smart pointers, lambda-based implementations or type-trait dependencies are required.

LeakSanitizer cannot inspect processes in the preparation environment, so leaks are not locally verified. GitHub Actions runs reference behavior, starter compilation and sanitizer checks for all three tracks. Provided tests do not prove all inputs or enforce every algorithm restriction.
