#pragma once
#include <vector>
#include <cstddef>

struct PairResult { bool found; std::size_t first,second; };
inline PairResult find_pair(const std::vector<int>& values,long long target) {
for (std::size_t j=0;j<values.size();++j) {
    for (std::size_t i=0;i<j;++i) {
        if (static_cast<long long>(values[i])+values[j]==target) return {true,i,j};
    }
}
return {false,0,0};
}
