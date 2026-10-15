#pragma once
#include <algorithm>
#include <charconv>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <limits>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

struct Interval {
    int start;
    int end;
};
inline std::vector<Interval> merge_intervals(std::vector<Interval> intervals) {
    for (auto r : intervals) if (r.start> r.end) throw std::invalid_argument("interval");
    std::sort(intervals.begin(), intervals.end(), [] (auto a, auto b) {
        return a.start < b.start;
    });
    std::vector<Interval> out;
    for (auto r : intervals) {
        if (out.empty() || r.start> out.back().end) out.push_back(r);
        else out.back().end = std::max(out.back().end, r.end);
    }
    return out;
}
