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

inline std::optional<std::size_t> first_unique(const std::string& text) {
    std::array<std::size_t,256> counts{};
    for (unsigned char c : text) ++counts[c];
    for (std::size_t i=0;i<text.size();++i)
        if (counts[static_cast<unsigned char>(text[i])]==1) return i;
    return std::nullopt;
}
