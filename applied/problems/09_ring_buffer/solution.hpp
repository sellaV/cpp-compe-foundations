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
    std::vector<std::optional<T>> slots_;
    std::size_t head_ = 0, count_ = 0;
public:
    explicit RingBuffer(std::size_t capacity) : slots_(capacity) {
        if (capacity == 0) throw std::invalid_argument("capacity");
    }
    void push(const T & value) {
        slots_[(head_ + count_) % slots_.size()] = value;
        if (count_ == slots_.size()) head_ = (head_ + 1) % slots_.size();
        else ++count_;
    }
    std::optional<T> pop() {
        if (count_ == 0) return std::nullopt;
        auto value = slots_[head_];
        slots_[head_].reset();
        head_ = (head_ + 1) % slots_.size();
        --count_;
        return value;
    }
    std::size_t size() const {
        return count_;
    }
};
