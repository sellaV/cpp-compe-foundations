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
#include "../19_iou/starter.hpp"

inline std::vector<std::size_t> nms(const std::vector<Box> & boxes, const std::vector<double> & scores, double threshold) {
    // TODO: implement the contract in README.md.
    throw std::logic_error("TODO: 20_nms");
}
