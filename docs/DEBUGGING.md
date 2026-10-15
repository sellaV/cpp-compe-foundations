# Debugging routine

1. Start with the smallest failing case.
2. Trace each loop/call and state what should remain true.
3. Check bounds, empty states and object lifetimes before indexing or dereferencing.
4. Check types: integer division, unsigned underflow, signed overflow and byte indexing.
5. For classes, inspect the invariant before and after a failed operation.
6. Add the case to test.cpp and rerun that task.

A compile error means the language cannot form a program; a failed check means the program ran but violated tested behavior. Read the first compiler error before later cascading errors. Starter unused-parameter warnings are expected while unfinished.

| Symptom | Check |
| --- | --- |
| Caller value unchanged | Was the parameter passed by value instead of reference? |
| Invalid access after push_back | Was a pointer/iterator kept across reallocation? |
| Dangling return | Did a pointer/reference/view refer to a local object? |
| Wrong tied ranking | Is the comparator strict, and is stability required? |
| Moved-from object inconsistent | Was a separate size field reset? |
| Extra final line | Was eof tested before trying extraction? |
| State not restored on exception | Does cleanup happen in a destructor? |

On supported GCC/Clang platforms run `python3 tools/run.py 14 --sanitize` for address and undefined-behavior checks. The active CHECK macro does not disappear under NDEBUG. Passing tests is useful evidence, not a proof for all inputs or the required algorithm.
