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
public:
    PID(double, double, double, double) {
        throw std::logic_error("TODO constructor");
    }
    double step(double, double) {
        throw std::logic_error("TODO step");
    }
    void reset() {
        throw std::logic_error("TODO reset");
    }
};
