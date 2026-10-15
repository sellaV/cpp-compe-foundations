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

inline std::size_t longest_unique(const std::string& text) {
    std::array<std::size_t,256> after{};
    std::size_t start=0,best=0;
    for (std::size_t i=0;i<text.size();++i) {
        auto c=static_cast<unsigned char>(text[i]);
        start=std::max(start,after[c]);
        best=std::max(best,i-start+1);
        after[c]=i+1;
    }
    return best;
}
