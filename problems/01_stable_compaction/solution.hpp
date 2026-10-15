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

inline std::vector<int> filter_samples(const std::vector<int> & samples, int lo, int hi) {
    if (lo> hi) throw std::invalid_argument("range");
    std::vector<int> out;
    for (int x : samples) if (lo <= x && x <= hi) out.push_back(x);
    return out;
}
