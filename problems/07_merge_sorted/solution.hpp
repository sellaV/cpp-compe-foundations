#pragma once
#include <vector>
#include <cstddef>


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
