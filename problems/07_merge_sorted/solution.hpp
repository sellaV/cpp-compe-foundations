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

inline std::vector<int> merge_sorted(const std::vector<int>& a,const std::vector<int>& b) {
    std::vector<int> out;
    out.reserve(a.size()+b.size());
    std::size_t i=0,j=0;
    while (i<a.size() || j<b.size()) {
        if (j==b.size() || (i<a.size() && a[i]<=b[j])) out.push_back(a[i++]);
        else out.push_back(b[j++]);
    }
    return out;
}
