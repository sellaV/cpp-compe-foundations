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

struct Box {
    double x1, y1, x2, y2;
};
inline double iou(const Box & a, const Box & b) {
    auto valid = [] (const Box & x) {
        return std::isfinite(x.x1) && std::isfinite(x.y1) && std::isfinite(x.x2) && std::isfinite(x.y2) && x.x1 <= x.x2 && x.y1 <= x.y2;
    };
    if (!valid(a) || !valid(b)) throw std::invalid_argument("box");
    double intersection = std::max(0.0, std::min(a.x2, b.x2) - std::max(a.x1, b.x1)) * std::max(0.0, std::min(a.y2, b.y2) - std::max(a.y1, b.y1));
    double area = (a.x2 - a.x1) * (a.y2 - a.y1) + (b.x2 - b.x1) * (b.y2 - b.y1) - intersection;
    return area == 0 ? 0 : intersection / area;
}
