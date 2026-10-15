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

inline std::optional<int> second_largest(const std::vector<int>& values) {
    std::optional<int> first, second;
    for (int value : values) {
        if (!first || value > *first) {
            second = first;
            first = value;
        } else if (value < *first && (!second || value > *second)) {
            second = value;
        }
    }
    return second;
}
