# Setup

You need a C++17-capable GCC or Clang compiler and Python 3.9+. Python only runs the test commands; your solutions are C++.

## Windows: recommended WSL route

If Ubuntu in WSL is already installed, open its terminal. Otherwise install WSL/Ubuntu using Windows' WSL setup, then reopen Ubuntu after setup completes.

```bash
sudo apt update
sudo apt install g++ python3 git
```

Extract the ZIP into a directory you can access from WSL, or clone the published repository. VS Code with the WSL extension can open the folder in WSL. In that terminal, from the repository root:

```bash
g++ --version
python3 --version
python3 tools/run.py 01
```

You can use a native Windows GCC/Clang installation instead if its executable is on PATH. The runner supports those compilers, not MSVC `cl`. For native Windows paths, a plain `CXX=g++` is simplest; quoted paths with spaces may require platform-specific quoting. Sanitizers are easiest in Linux/WSL.

## Linux

On Debian/Ubuntu install `g++`, `python3`, and optionally `git` with the commands above. On other distributions use their package manager. Run `python3 tools/run.py 01`.

## macOS

Install Apple's command-line development tools if needed:

```bash
xcode-select --install
```

Install Python 3 if necessary. Verify `clang++ --version` and `python3 --version`, then run `python3 tools/run.py 01`.

## Without the runner

From the repo root:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -g problems/01_second_largest/test.cpp -o challenge
./challenge
```

Use `clang++` in place of `g++` if desired. On Windows the executable is normally `challenge.exe`. To compile the reference add `-DREFERENCE=1`. Delete manually built executables before committing.

