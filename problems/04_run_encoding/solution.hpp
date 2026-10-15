#pragma once
#include <string>
#include <vector>
#include <cstddef>


struct Run { char value; std::size_t count; };
inline std::vector<Run> encode_runs(const std::string& text) {
    std::vector<Run> out;
    for (char c : text) {
        if (!out.empty() && out.back().value == c) ++out.back().count;
        else out.push_back({c,1});
    }
    return out;
}
