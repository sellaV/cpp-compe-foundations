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

struct FractionParts { std::int64_t numerator, denominator; };
inline FractionParts normalize_fraction(std::int64_t n, std::int64_t d) {
    if (d == 0) throw std::invalid_argument("zero denominator");
    if (d < 0) { n = -n; d = -d; }
    auto g = std::gcd(n,d);
    return {n/g,d/g};
}
