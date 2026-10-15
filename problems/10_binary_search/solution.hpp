#pragma once
#include <vector>
#include <cstddef>


inline std::size_t first_at_least(const std::vector<int> & sorted, int target) {
    std::size_t lo = 0, hi = sorted.size();
    while (lo < hi) {
        auto mid = lo + (hi - lo) / 2;
        if (sorted[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}
