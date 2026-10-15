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
    std::int64_t n_,d_;
    public:
        Fraction(std::int64_t n,std::int64_t d=1) : n_(n),d_(d) {
            if (d_==0) throw std::invalid_argument("denominator");
            if (d_<0) { n_=-n_;d_=-d_; }
            auto g=std::gcd(n_,d_);n_/=g;d_/=g;
        }
        std::int64_t numerator() const { return n_; }
        std::int64_t denominator() const { return d_; }
        Fraction operator+(const Fraction& other) const {
            return Fraction(n_*other.d_+other.n_*d_,d_*other.d_);
        }
        bool operator==(const Fraction& other) const { return n_==other.n_ && d_==other.d_; }
};
