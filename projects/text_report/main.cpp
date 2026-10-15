#include "analyzer.hpp"
#include <exception>
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: text_report FILE\n";
        return 2;
    }
    // Binary mode makes byte counts consistent even with CRLF files.
    std::ifstream input(argv[1], std::ios::binary);
    if (!input) {
        std::cerr << "Cannot open input file\n";
        return 1;
    }
    try {
        const Report report = analyze(input);
        std::cout << "lines=" << report.lines << '\n'
                  << "words=" << report.words << '\n'
                  << "bytes=" << report.bytes << '\n';
        if (!std::cout) return 1;
    } catch (const std::exception& error) {
        std::cerr << "Analysis failed: " << error.what() << '\n';
        return 1;
    }
    return 0;
}
