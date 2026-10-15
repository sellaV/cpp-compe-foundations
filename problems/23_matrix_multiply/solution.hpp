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

inline std::vector<double> matmul(const std::vector<double> & a, const std::vector<double> & b, int m, int k, int n) {
    if (m < 0 || k < 0 || n < 0 || a.size() != static_cast<std::size_t> (m) * static_cast<std::size_t> (k) || b.size() != static_cast<std::size_t> (k) * static_cast<std::size_t> (n)) throw std::invalid_argument("shape");
    std::vector<double> out(static_cast<std::size_t> (m) * static_cast<std::size_t> (n), 0);
    for (int r = 0; r < m; ++r) for (int t = 0; t < k; ++t) for (int c = 0; c < n; ++c) out[r * n + c] += a[r * k + t] * b[t * n + c];
    return out;
}
