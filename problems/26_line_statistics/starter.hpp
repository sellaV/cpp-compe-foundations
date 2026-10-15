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

struct LineStats { std::size_t lines=0,nonempty=0,max_length=0; };
inline LineStats summarize_lines(std::istream&) { throw std::logic_error("TODO"); }
inline void write_stats(std::ostream&,const LineStats&) { throw std::logic_error("TODO"); }
