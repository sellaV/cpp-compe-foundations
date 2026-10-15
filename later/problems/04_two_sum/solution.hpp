#pragma once
#include <algorithm>
#include <charconv>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <limits>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

inline std::optional<std::pair<std::size_t, std::size_t>> two_sum(const std::vector<int> & values, std::int64_t target) {
    std::unordered_map<std::int64_t, std::size_t> seen;
    for (std::size_t j = 0; j < values.size(); ++j) {
        auto it = seen.find(target - static_cast<std::int64_t> (values[j]));
        if (it != seen.end()) return std::make_pair(it->second, j);
        seen.emplace(values[j], j);
    }
    return std::nullopt;
}
