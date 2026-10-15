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
    // TODO: implement the contract in README.md.
    throw std::logic_error("TODO: 19_iou");
}
