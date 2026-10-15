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
g++ -std=c++17 -Wall -Wextra -Wpedantic -g problems/01_stable_compaction/test.cpp -o challenge
./challenge
```

Use `clang++` in place of `g++` if desired. On Windows the executable is normally `challenge.exe`. To compile the reference add `-DREFERENCE=1`. Delete manually built executables before committing.

## Publishing this prepared repo

Create an empty GitHub repository named `cpp-compe-foundations` with your preferred visibility. Avoid initializing a README if uploading this entire package with Git.

If ChatGPT is uploading the files through the plugin, send the new repository URL and ensure the GitHub app can access it. The plugin available during preparation can write repository contents but cannot create the repository itself.

For manual upload, extract the package and run these commands **inside the extracted repo folder**, replacing the URL with your own:

```bash
git init -b main
git add .
git commit -m "Add C++ CompE learning curriculum"
git remote add origin https://github.com/YOUR_USERNAME/cpp-compe-foundations.git
git push -u origin main
```

GitHub authentication is handled by your usual Git setup. Do not put tokens into source files.
