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

inline std::vector<float> to_chw(const std::vector<std::uint8_t> & pixels, int height, int width) {
    if (height < 0 || width < 0 || pixels.size() != static_cast<std::size_t> (height) * static_cast<std::size_t> (width) * 3) throw std::invalid_argument("shape");
    std::size_t plane = static_cast<std::size_t> (height) * static_cast<std::size_t> (width);
    std::vector<float> out(pixels.size());
    for (std::size_t p = 0; p < plane; ++p) for (std::size_t c = 0; c < 3; ++c) out[c * plane + p] = static_cast<float> (pixels[p * 3 + c]) / 255.0f;
    return out;
}
