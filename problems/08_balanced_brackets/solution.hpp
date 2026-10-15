#pragma once
#include <vector>
#include <string>


inline bool balanced_brackets(const std::string& text) {
    std::vector<char> open;
    for (char c : text) {
        if (c=='(' || c=='[' || c=='{') open.push_back(c);
        else {
            if (open.empty()) return false;
            char expected = c==')' ? '(' : (c==']' ? '[' : '{');
            if (open.back()!=expected) return false;
            open.pop_back();
        }
    }
    return open.empty();
}
