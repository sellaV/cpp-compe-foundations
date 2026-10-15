#include "../analyzer.hpp"
#include <stdexcept>

namespace {
bool is_space(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' ||
           ch == '\r' || ch == '\v' || ch == '\f';
}
}

Report analyze(std::istream& input) {
    if (input.bad() || (input.fail() && !input.eof())) {
        throw std::runtime_error("input stream is not readable");
    }
    Report result;
    bool in_word = false;
    bool last_was_newline = true;
    char ch;
    while (input.get(ch)) {
        ++result.bytes;
        if (ch == '\n') ++result.lines;
        last_was_newline = ch == '\n';
        if (is_space(ch)) {
            in_word = false;
        } else if (!in_word) {
            ++result.words;
            in_word = true;
        }
    }
    if (input.bad() || (input.fail() && !input.eof())) {
        throw std::runtime_error("failed while reading input");
    }
    if (result.bytes != 0 && !last_was_newline) ++result.lines;
    return result;
}
