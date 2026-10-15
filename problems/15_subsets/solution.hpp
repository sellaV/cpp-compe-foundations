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

inline std::vector<std::vector<int>> subsets(const std::vector<int>& values) {
    std::vector<std::vector<int>> out;
    std::vector<int> current;
    std::function<void(std::size_t)> visit=[&](std::size_t i) {
        if (i==values.size()) { out.push_back(current); return; }
        visit(i+1);
        current.push_back(values[i]);
        visit(i+1);
        current.pop_back();
    };
    visit(0);
    return out;
}
