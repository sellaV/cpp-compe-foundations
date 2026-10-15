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

using Value=std::variant<int,bool,std::string>;
inline std::optional<Value> parse_value(std::string_view text) {
    if (text.substr(0,5)=="text:") return Value{std::string(text.substr(5))};
    if (text=="bool:true") return Value{true};
    if (text=="bool:false") return Value{false};
    if (text.substr(0,4)!="int:") return std::nullopt;
    auto suffix=text.substr(4);
    if (suffix.empty()) return std::nullopt;
    int n=0;
    auto r=std::from_chars(suffix.data(),suffix.data()+suffix.size(),n);
    if (r.ec!=std::errc{} || r.ptr!=suffix.data()+suffix.size()) return std::nullopt;
    return Value{n};
}
