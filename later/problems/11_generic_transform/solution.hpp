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

template<class T, class F> inline auto map_values(const std::vector<T> & values, F f) {
    using U = std::decay_t<decltype(f(std::declval < const T &> ()))>;
    std::vector<U> out;
    out.reserve(values.size());
    for (const auto & x : values) out.push_back(f(x));
    return out;
}
