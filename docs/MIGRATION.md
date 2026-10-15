# Updating without losing your solutions

This revision keeps the paths and interfaces of retained exercises. IDs intentionally have gaps. Removed drills are listed in the root README and remain recoverable in Git history.

Before pulling in WSL, inspect your work:

```bash
git status
git diff
```

Commit your own intended files on your working branch, or make a separate backup outside the repository. Do not blindly discard local changes or run a hard reset. If a file you solved was removed upstream, save that solution before updating.

Once your working tree is clean, on main:

```bash
git pull --ff-only origin main
```

If Git reports divergent history or a conflict, stop and inspect the branches; do not force the update. Existing clones do not need to be cloned again. The old `all` command now covers only retained exercises; `--list` shows valid IDs.

The foundation path now includes labs and a project. Progress means meeting their completion criteria, not solving every remaining exercise.
