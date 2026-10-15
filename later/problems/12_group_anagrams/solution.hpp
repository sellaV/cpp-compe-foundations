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

inline std::vector<std::vector<std::string>> group_anagrams(const std::vector<std::string>& words) {
    std::unordered_map<std::string,std::size_t> positions;
    std::vector<std::vector<std::string>> out;
    for (const auto& word : words) {
        auto key=word;std::sort(key.begin(),key.end());
        auto result=positions.emplace(key,out.size());
        if (result.second) out.emplace_back();
        out[result.first->second].push_back(word);
    }
    return out;
}
