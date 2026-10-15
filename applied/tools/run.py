#!/usr/bin/env python3
"""Dependency-free GCC/Clang challenge runner. Invoke from any directory."""
import argparse
import json
import os
from pathlib import Path
import shlex
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('problem', nargs='?', help='ID (01..24), full slug, or all')
    parser.add_argument('--list', action='store_true', help='List curriculum')
    parser.add_argument('--reference', action='store_true', help='Test solutions rather than your work')
    parser.add_argument('--sanitize', action='store_true', help='Enable AddressSanitizer + UndefinedBehaviorSanitizer')
    parser.add_argument('--compile-only', action='store_true', help='Check compilation without executing')
    args = parser.parse_args()
    tasks = json.loads((ROOT / 'curriculum.json').read_text())
    if args.list:
        for task in tasks:
            print(f"{task['slug']} | {task['level']} | {task['title']}")
        return 0
    if not args.problem:
        parser.error('Choose an ID, all, or --list. Example: python tools/run.py 01')
    selected = tasks if args.problem == 'all' else [t for t in tasks if args.problem in (t['slug'][:2],t['slug'])]
    if not selected:
        parser.error('Unknown problem. Use --list, a two-digit ID, or all.')
    # CXX may be a quoted executable path or command such as "ccache g++".
    compiler = shlex.split(os.environ.get('CXX',''), posix=os.name != 'nt')
    if not compiler:
        found = shutil.which('g++') or shutil.which('clang++')
        if not found:
            print('No GCC/Clang compiler found. See docs/SETUP.md.', file=sys.stderr)
            return 2
        compiler = [found]
    build = ROOT / 'build'
    build.mkdir(exist_ok=True)
    failed = []
    for task in selected:
        slug = task['slug']
        print(f"\n[{slug}] {'reference' if args.reference else 'your implementation'}", flush=True)
        mode = 'reference' if args.reference else 'learner'
        if args.sanitize:
            mode += '-sanitized'
        exe = build / f"{slug}-{mode}{'.exe' if os.name == 'nt' else ''}"
        command = compiler + ['-std=c++17','-Wall','-Wextra','-Wpedantic','-g','-O0']
        if args.reference:
            command += ['-DREFERENCE=1']
        if args.sanitize:
            command += ['-fsanitize=address,undefined','-fno-omit-frame-pointer']
        command += [str(ROOT / 'problems' / slug / 'test.cpp'),'-o',str(exe)]
        try:
            built = subprocess.run(command,timeout=60)
            if built.returncode != 0:
                failed.append(slug)
                continue
            if not args.compile_only and subprocess.run([str(exe)],timeout=10).returncode != 0:
                failed.append(slug)
        except subprocess.TimeoutExpired:
            print('TIMEOUT: check for infinite loops or an unsuitable algorithm.',file=sys.stderr)
            failed.append(slug)
        except OSError as error:
            print(f'Could not run compiler or executable: {error}',file=sys.stderr)
            return 2
    print(f"\n{len(selected)-len(failed)}/{len(selected)} {'compiled' if args.compile_only else 'passed'}.")
    if failed:
        print('Failed: '+', '.join(failed))
    return 1 if failed else 0

if __name__ == '__main__':
    sys.exit(main())
