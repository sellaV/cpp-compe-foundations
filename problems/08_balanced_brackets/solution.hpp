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

inline bool balanced_brackets(std::string_view text) {
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
