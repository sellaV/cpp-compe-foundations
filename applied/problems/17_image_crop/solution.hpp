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

inline std::vector<int> crop(const std::vector<int> & image, int width, int height, int x, int y, int cw, int ch) {
    if (width < 0 || height < 0 || x < 0 || y < 0 || cw < 0 || ch < 0 || x> width || y> height || cw> width - x || ch> height - y || image.size() != static_cast<std::size_t> (width) * static_cast<std::size_t> (height)) throw std::invalid_argument("image");
    std::vector<int> out;
    for (int r = 0; r < ch; ++r) for (int c = 0; c < cw; ++c) out.push_back(image[(y + r) * width + x + c]);
    return out;
}
