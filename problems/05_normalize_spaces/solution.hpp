#pragma once
#include <string>


inline std::string normalize_spaces(const std::string& text) {
    std::string out;
    bool pending = false;
    for (char c : text) {
        bool whitespace = c==' ' || c=='\t' || c=='\n' || c=='\r' || c=='\f' || c=='\v';
        if (whitespace) pending = !out.empty();
        else {
            if (pending) out.push_back(' ');
            out.push_back(c);
            pending = false;
        }
    }
    return out;
}
