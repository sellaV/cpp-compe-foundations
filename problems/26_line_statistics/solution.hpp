#pragma once
#include <algorithm>
#include <array>
#include <charconv>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <ios>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <variant>
#include <vector>

struct LineStats { std::size_t lines=0,nonempty=0,max_length=0; };
inline LineStats summarize_lines(std::istream& input) {
    LineStats stats;
    std::string line;
    while (std::getline(input,line)) {
        if (!line.empty() && line.back()=='\r') line.pop_back();
        ++stats.lines;
        if (!line.empty()) ++stats.nonempty;
        stats.max_length=std::max(stats.max_length,line.size());
    }
    if (input.bad() || (!input.eof() && input.fail())) throw std::runtime_error("stream failure");
    return stats;
    }
    inline void write_stats(std::ostream& out,const LineStats& stats) {
    auto flags=out.flags();
    out<<std::dec<<"lines="<<stats.lines<<";nonempty="<<stats.nonempty<<";max="<<stats.max_length<<'\n';
    out.flags(flags);
}
