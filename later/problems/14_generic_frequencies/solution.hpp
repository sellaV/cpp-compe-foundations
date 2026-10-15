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

template<class It> inline auto frequencies(It first,It last) {
    using T=typename std::iterator_traits<It>::value_type;
    std::map<T,std::size_t> out;
    for (;first!=last;++first) ++out[*first];
    return out;
}
