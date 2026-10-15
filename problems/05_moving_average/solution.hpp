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

inline std::vector<double> moving_average(const std::vector<double> & values, std::size_t k) {
    if (k == 0) throw std::invalid_argument("window");
    if (k> values.size()) return {
    };
    double sum = std::accumulate(values.begin(), values.begin() + static_cast<std::ptrdiff_t> (k), 0.0);
    std::vector<double> out {
        sum / static_cast<double> (k)
    };
    for (std::size_t i = k; i < values.size(); ++i) {
        sum += values[i] - values[i - k];
        out.push_back(sum / static_cast<double> (k));
    }
    return out;
}
