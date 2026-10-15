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

inline void rotate_right(std::vector<int>& values, std::size_t k) {
    if (values.empty()) return;
    k %= values.size();
    auto middle = values.begin()+static_cast<std::ptrdiff_t>(k);
    std::reverse(values.begin(),values.end());
    std::reverse(values.begin(),middle);
    std::reverse(middle,values.end());
}
