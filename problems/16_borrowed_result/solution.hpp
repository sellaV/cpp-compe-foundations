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

inline int* max_element_ptr(int* data,std::size_t n) {
    if (n>0 && !data) throw std::invalid_argument("null range");
    if (n==0) return nullptr;
    int* best=data;
    for (std::size_t i=1;i<n;++i) if (data[i]>*best) best=data+i;
    return best;
    }
    inline const int* max_element_ptr(const int* data,std::size_t n) {
    if (n>0 && !data) throw std::invalid_argument("null range");
    if (n==0) return nullptr;
    const int* best=data;
    for (std::size_t i=1;i<n;++i) if (data[i]>*best) best=data+i;
    return best;
}
