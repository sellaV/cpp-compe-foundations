#pragma once
#include <algorithm>
#include <array>
#include <charconv>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <ios>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <variant>
#include <vector>

class IntBuffer {
    std::unique_ptr<int[]> data_;
    std::size_t size_;
    public:
        explicit IntBuffer(std::size_t n):data_(std::make_unique<int[]>(n)),size_(n) {}
        IntBuffer(const IntBuffer&)=delete;
        IntBuffer& operator=(const IntBuffer&)=delete;
        IntBuffer(IntBuffer&& other) noexcept : data_(std::move(other.data_)),size_(std::exchange(other.size_,0)) {}
        IntBuffer& operator=(IntBuffer&& other) noexcept {
            if (this!=&other) { data_=std::move(other.data_);size_=std::exchange(other.size_,0); }
            return *this;
        }
        std::size_t size() const { return size_; }
        int& at(std::size_t i) { if (i>=size_) throw std::out_of_range("index");return data_[i]; }
        const int& at(std::size_t i) const { if (i>=size_) throw std::out_of_range("index");return data_[i]; }
};
