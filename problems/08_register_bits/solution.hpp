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

inline std::uint32_t write_bit(std::uint32_t reg, unsigned index, bool enabled) {
    if (index >= 32) throw std::out_of_range("bit");
    const std::uint32_t mask = std::uint32_t {
        1
    }
    << index;
    return enabled ? reg | mask : reg & ~ mask;
}
