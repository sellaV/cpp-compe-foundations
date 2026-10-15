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

inline std::vector<double> blur3(const std::vector<int> & image, int width, int height) {
    if (width < 0 || height < 0 || image.size() != static_cast<std::size_t> (width) * static_cast<std::size_t> (height)) throw std::invalid_argument("image");
    std::vector<double> out(image.size());
    for (int r = 0; r < height; ++r) for (int c = 0; c < width; ++c) {
        double sum = 0;
        int count = 0;
        for (int dr = - 1; dr <= 1; ++dr) for (int dc = - 1; dc <= 1; ++dc) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < height && nc >= 0 && nc < width) {
                sum += image[nr * width + nc];
                ++count;
            }
        }
        out[r * width + c] = sum / count;
    }
    return out;
}
