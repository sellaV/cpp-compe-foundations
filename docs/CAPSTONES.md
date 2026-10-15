# Build and maintain a small program

Start with the [text-report project](../projects/text_report/README.md). It includes a multi-file starter, a CLI shell, tests, a reference implementation, and optional CMake configuration. This is the required integration milestone; completing all optional exercises first is unnecessary.

## Then choose one independent extension

- Extend the report with word frequencies. Specify punctuation/case rules and deterministic tie ordering before choosing a map and sorting algorithm.
- Build a library catalog with add, search, borrow, and return. Keep state changes valid on failure; document a simple persistence format and test malformed records.
- Choose one appropriately scoped [Build Your Own X](https://github.com/codecrafters-io/build-your-own-x) tutorial, then add and test a feature independently. Use the [resource guide](RESOURCES.md) to check prerequisites.

## Completion evidence

- A fresh build works using documented commands.
- Public functions have clear input/output and failure contracts.
- Logic is separated from command-line/file handling.
- Empty, malformed, and boundary inputs have meaningful tests.
- A regression test catches a bug you found.
- Git history explains changes in small steps.
- The README records one tradeoff and one limitation.

Do not measure progress by puzzle difficulty or code length. A small program you understand, can debug, and can change is a useful milestone.
