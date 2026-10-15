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

inline void reverse_range(int* data,std::size_t n) {
    if (n>0 && data==nullptr) throw std::invalid_argument("null range");
    for (std::size_t i=0;i<n/2;++i) {
        int temporary=data[i];
        data[i]=data[n-1-i];
        data[n-1-i]=temporary;
    }
}
