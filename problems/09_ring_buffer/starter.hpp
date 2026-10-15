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

template<class T> class RingBuffer {
public:
    explicit RingBuffer(std::size_t) {
        throw std::logic_error("TODO constructor");
    }
    void push(const T &) {
        throw std::logic_error("TODO push");
    }
    std::optional<T> pop() {
        throw std::logic_error("TODO pop");
    }
    std::size_t size() const {
        throw std::logic_error("TODO size");
    }
};
