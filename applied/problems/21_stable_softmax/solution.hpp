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

inline std::vector<double> softmax(const std::vector<double> & logits) {
    if (logits.empty()) return {
    };
    for (double x : logits) if (!std::isfinite(x)) throw std::invalid_argument("logit");
    double maximum = * std::max_element(logits.begin(), logits.end());
    std::vector<double> out;
    double sum = 0;
    for (double x : logits) {
        out.push_back(std::exp(x - maximum));
        sum += out.back();
    }
    for (double & x : out) x /= sum;
    return out;
}
