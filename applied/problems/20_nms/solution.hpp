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
#include "../19_iou/solution.hpp"

inline std::vector<std::size_t> nms(const std::vector<Box> & boxes, const std::vector<double> & scores, double threshold) {
    if (boxes.size() != scores.size() || !std::isfinite(threshold) || threshold < 0 || threshold > 1) throw std::invalid_argument("input");
    for (std::size_t i = 0; i < boxes.size(); ++i) {
        if (!std::isfinite(scores[i])) throw std::invalid_argument("score");
        (void) iou(boxes[i], boxes[i]);
    }
    std::vector<std::size_t> order(boxes.size());
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(), [&] (auto a, auto b) {
        return scores[a] == scores[b] ? a < b : scores[a]> scores[b];
    });
    std::vector<std::size_t> kept;
    for (auto i : order) {
        bool discard = false;
        for (auto j : kept) if (iou(boxes[i], boxes[j])> threshold) {
            discard = true;
            break;
        }
        if (!discard) kept.push_back(i);
    }
    return kept;
}
