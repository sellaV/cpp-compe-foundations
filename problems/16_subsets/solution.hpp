#pragma once
#include <vector>
#include <cstddef>

inline void collect_subsets(const std::vector<int>& values,std::size_t i,std::vector<int>& current,std::vector<std::vector<int>>& out) {
if (i==values.size()) {out.push_back(current);return;}
collect_subsets(values,i+1,current,out);
current.push_back(values[i]);
collect_subsets(values,i+1,current,out);
current.pop_back();
}
inline std::vector<std::vector<int>> subsets(const std::vector<int>& values) {
std::vector<std::vector<int>> out;std::vector<int> current;
collect_subsets(values,0,current,out);
return out;
}
