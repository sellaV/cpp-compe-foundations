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

class PID {
    double kp_, ki_, kd_, limit_, integral_ = 0, previous_ = 0;
    bool first_ = true;
public:
    PID(double kp, double ki, double kd, double limit) : kp_(kp), ki_(ki), kd_(kd), limit_(limit) {
        if (!std::isfinite(kp) || !std::isfinite(ki) || !std::isfinite(kd) || !std::isfinite(limit) || limit < 0) throw std::invalid_argument("gain");
    }
    double step(double error, double dt) {
        if (!std::isfinite(error) || !std::isfinite(dt) || dt <= 0) throw std::invalid_argument("sample");
        integral_ += error * dt;
        double derivative = first_ ? 0 : (error - previous_) / dt;
        previous_ = error;
        first_ = false;
        return std::clamp(kp_ * error + ki_ * integral_ + kd_ * derivative, - limit_, limit_);
    }
    void reset() {
        integral_ = previous_ = 0;
        first_ = true;
    }
};
