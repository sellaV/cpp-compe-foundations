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

struct Run { char value; std::size_t count; };
inline std::vector<Run> encode_runs(const std::string& text) {
    std::vector<Run> out;
    for (char c : text) {
        if (!out.empty() && out.back().value == c) ++out.back().count;
        else out.push_back({c,1});
    }
    return out;
}
