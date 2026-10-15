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

class FormatGuard {
public:
    explicit FormatGuard(std::ostream&) { throw std::logic_error("TODO"); }
    ~FormatGuard()=default;
    FormatGuard(const FormatGuard&)=delete;
    FormatGuard& operator=(const FormatGuard&)=delete;
    FormatGuard(FormatGuard&&)=delete;
    FormatGuard& operator=(FormatGuard&&)=delete;
};
