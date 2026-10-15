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

inline std::vector<int> read_integers(std::istream& input) {
    std::vector<int> out;
    std::string token;
    while (input>>token) {
        int value=0;
        auto result=std::from_chars(token.data(),token.data()+token.size(),value);
        if (result.ec!=std::errc{} || result.ptr!=token.data()+token.size()) throw std::invalid_argument("integer token");
        out.push_back(value);
    }
    if (input.bad() || (!input.eof() && input.fail())) throw std::runtime_error("stream failure");
    return out;
}
