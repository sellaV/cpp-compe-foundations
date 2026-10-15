#pragma once
#include <vector>
#include <cstddef>

inline void reverse_segment(std::vector<int>& values,std::size_t begin,std::size_t end) {
while (end>begin && end-begin>1) {
    --end;int temporary=values[begin];values[begin]=values[end];values[end]=temporary;++begin;
}
}
inline void rotate_right(std::vector<int>& values,std::size_t k) {
if (values.empty()) return;
k%=values.size();
reverse_segment(values,0,values.size());
reverse_segment(values,0,k);
reverse_segment(values,k,values.size());
}
