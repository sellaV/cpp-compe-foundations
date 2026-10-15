#include "analyzer.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <streambuf>

void require(bool condition, const char* message) {
    if (!condition) throw std::runtime_error(message);
}

void check(const std::string& text, std::size_t lines,
           std::size_t words, std::size_t bytes) {
    std::istringstream input(text);
    const Report report = analyze(input);
    require(report.lines == lines, "incorrect line count");
    require(report.words == words, "incorrect word count");
    require(report.bytes == bytes, "incorrect byte count");
}

class BrokenBuffer : public std::streambuf {
    int_type underflow() override {
        throw std::runtime_error("simulated read failure");
    }
};

int main() {
    try {
        check("", 0, 0, 0);
        check("a", 1, 1, 1);
        check("a\n", 1, 1, 2);
        check("\n\n", 2, 0, 2);
        check("a\nb", 2, 2, 3);
        check(" \t\r\v\f", 1, 0, 5);
        check("red blue\nred\n", 2, 3, 13);
        check("a\r\nb\r\n", 2, 2, 6);
        check("one,two!", 1, 1, 8);
        check(std::string("a\0b", 3), 1, 1, 3);
        check("\xC3\xA9", 1, 1, 2); // UTF-8 bytes, not a Unicode character count.
        check(std::string(100000, 'x'), 1, 1, 100000);
        std::istringstream partial("skip rest");
        std::string skipped;
        partial >> skipped;
        const Report remaining = analyze(partial);
        require(remaining.lines == 1 && remaining.words == 1 && remaining.bytes == 5,
                "must read from the current stream position");
        const Report exhausted = analyze(partial);
        require(exhausted.lines == 0 && exhausted.words == 0 && exhausted.bytes == 0,
                "already exhausted input must be empty");
        std::istringstream failed("ignored");
        failed.setstate(std::ios::badbit);
        bool rejected = false;
        try { (void)analyze(failed); }
        catch (const std::runtime_error&) { rejected = true; }
        require(rejected, "bad input stream must be rejected");
        std::istringstream fail_only("ignored");
        fail_only.setstate(std::ios::failbit);
        rejected = false;
        try { (void)analyze(fail_only); }
        catch (const std::runtime_error&) { rejected = true; }
        require(rejected, "failure without EOF must be rejected");
        BrokenBuffer broken_buffer;
        std::istream broken_input(&broken_buffer);
        rejected = false;
        try { (void)analyze(broken_input); }
        catch (const std::runtime_error&) { rejected = true; }
        require(rejected, "failure during a read must be rejected");
        std::cout << "Project unit tests passed\n";
    } catch (const std::exception& error) {
        std::cerr << "Project test failed: " << error.what() << '\n';
        return 1;
    }
}
