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

using Graph = std::vector<std::vector<std::pair<int, int>>>;
inline std::vector<std::int64_t> shortest_costs(const Graph & graph, int source) {
    // TODO: implement the contract in README.md.
    throw std::logic_error("TODO: 14_weighted_path");
}
