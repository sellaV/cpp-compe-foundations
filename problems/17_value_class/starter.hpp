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

class Fraction {
public:
    Fraction(std::int64_t,std::int64_t=1) { throw std::logic_error("TODO"); }
    std::int64_t numerator() const { throw std::logic_error("TODO"); }
    std::int64_t denominator() const { throw std::logic_error("TODO"); }
    Fraction operator+(const Fraction&) const { throw std::logic_error("TODO"); }
    bool operator==(const Fraction&) const { throw std::logic_error("TODO"); }
};
