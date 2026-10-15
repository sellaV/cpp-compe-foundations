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

inline std::optional<int> parse_command(std::string_view text) {
    if (text.substr(0, 4) != "CMD:") return std::nullopt;
    auto suffix = text.substr(4);
    if (suffix.empty()) return std::nullopt;
    int value = 0;
    auto result = std::from_chars(suffix.data(), suffix.data() + suffix.size(), value);
    if (result.ec != std::errc {
    }
    || result.ptr != suffix.data() + suffix.size()) return std::nullopt;
    return value;
}
