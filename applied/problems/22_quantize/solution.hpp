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

inline std::vector<std::int8_t> quantize(const std::vector<double> & samples, double scale, int zero_point) {
    if (!std::isfinite(scale) || scale <= 0 || zero_point < - 128 || zero_point > 127) throw std::invalid_argument("parameters");
    std::vector<std::int8_t> out;
    for (double x : samples) {
        if (!std::isfinite(x)) throw std::invalid_argument("sample");
        double q = std::clamp(std::round(x / scale) + zero_point, - 128.0, 127.0);
        out.push_back(static_cast<std::int8_t> (q));
    }
    return out;
}
