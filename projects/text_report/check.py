#!/usr/bin/env python3
"""Build the learner/reference project and check unit plus CLI behavior."""
import argparse
import os
from pathlib import Path
import shlex
import shutil
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parent

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--reference', action='store_true')
    parser.add_argument('--compile-only', action='store_true')
    parser.add_argument('--sanitize', action='store_true')
    args = parser.parse_args()
    compiler = shlex.split(os.environ.get('CXX', ''), posix=os.name != 'nt')
    if not compiler:
        found = shutil.which('g++') or shutil.which('clang++')
        if not found:
            parser.error('GCC or Clang is required')
        compiler = [found]
    mode = 'reference' if args.reference else 'learner'
    if args.sanitize:
        mode += '-sanitized'
    build = ROOT / 'build' / mode
    build.mkdir(parents=True, exist_ok=True)
    implementation = ROOT / ('reference/analyzer.cpp' if args.reference else 'analyzer.cpp')
    flags = ['-std=c++17', '-Wall', '-Wextra', '-Wpedantic', '-g', '-O0']
    if args.sanitize:
        flags += ['-fsanitize=address,undefined', '-fno-omit-frame-pointer']
    suffix = '.exe' if os.name == 'nt' else ''
    exe = build / ('text_report' + suffix)
    test = build / ('report_tests' + suffix)
    for entry, output in [('main.cpp', exe), ('test.cpp', test)]:
        subprocess.run(compiler + flags + [str(implementation), str(ROOT / entry),
                       '-o', str(output)], check=True, timeout=60)
    if args.compile_only:
        print('Both project targets compiled')
        return
    subprocess.run([str(test)], check=True, timeout=10)
    def cli(arguments, status, stdout, stderr_fragment=''):
        result = subprocess.run([str(exe)] + arguments, capture_output=True,
                                text=True, timeout=10)
        if (result.returncode != status or result.stdout != stdout or
                (stderr_fragment not in result.stderr) or
                (not stderr_fragment and result.stderr)):
            raise RuntimeError(f'CLI check failed: args={arguments!r}, result={result!r}')
    cli([], 2, '', 'Usage:')
    cli(['one', 'two'], 2, '', 'Usage:')
    with tempfile.TemporaryDirectory() as folder:
        fixture = Path(folder) / 'sample with spaces.txt'
        fixture.write_bytes(b'red blue\nred\n')
        cli([str(fixture)], 0, 'lines=2\nwords=3\nbytes=13\n')
        fixture.write_bytes(b'')
        cli([str(fixture)], 0, 'lines=0\nwords=0\nbytes=0\n')
        fixture.write_bytes(b'a\r\nb')
        cli([str(fixture)], 0, 'lines=2\nwords=2\nbytes=4\n')
        cli([str(Path(folder) / 'missing.txt')], 1, '', 'Cannot open')
    print('Project CLI checks passed')

if __name__ == '__main__':
    main()
