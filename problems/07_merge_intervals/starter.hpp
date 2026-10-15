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

struct Interval {
    int start;
    int end;
};
inline std::vector<Interval> merge_intervals(std::vector<Interval> intervals) {
    // TODO: implement the contract in README.md.
    throw std::logic_error("TODO: 07_merge_intervals");
}
