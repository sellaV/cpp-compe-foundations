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

inline std::string normalize_spaces(std::string_view text) {
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
