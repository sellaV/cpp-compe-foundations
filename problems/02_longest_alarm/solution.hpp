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

inline std::size_t longest_alarm(const std::vector<int> & samples, int threshold) {
    std::size_t current = 0, best = 0;
    for (int x : samples) {
        current = x> threshold ? current + 1 : 0;
        best = std::max(best, current);
    }
    return best;
}
