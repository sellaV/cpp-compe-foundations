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
    std::ostream& stream_;
    std::ios::fmtflags flags_;
    std::streamsize precision_;
    public:
        explicit FormatGuard(std::ostream& stream):stream_(stream),flags_(stream.flags()),precision_(stream.precision()) {}
        ~FormatGuard() { stream_.flags(flags_);stream_.precision(precision_); }
        FormatGuard(const FormatGuard&)=delete;
        FormatGuard& operator=(const FormatGuard&)=delete;
        FormatGuard(FormatGuard&&)=delete;
        FormatGuard& operator=(FormatGuard&&)=delete;
};
