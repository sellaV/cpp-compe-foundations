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
public:
    explicit IntBuffer(std::size_t) { throw std::logic_error("TODO"); }
    IntBuffer(const IntBuffer&)=delete;
    IntBuffer& operator=(const IntBuffer&)=delete;
    IntBuffer(IntBuffer&&) noexcept=default;
    IntBuffer& operator=(IntBuffer&&) noexcept=default;
    std::size_t size() const { throw std::logic_error("TODO"); }
    int& at(std::size_t) { throw std::logic_error("TODO"); }
    const int& at(std::size_t) const { throw std::logic_error("TODO"); }
};
