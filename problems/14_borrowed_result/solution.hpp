#pragma once
#include <cstddef>

inline int* max_element_ptr(int* data,std::size_t n) {
if (!data||n==0) return nullptr;
int* best=data;
for (std::size_t i=1;i<n;++i) if (data[i]>*best) best=data+i;
return best;
}
inline const int* max_element_ptr(const int* data,std::size_t n) {
if (!data||n==0) return nullptr;
const int* best=data;
for (std::size_t i=1;i<n;++i) if (data[i]>*best) best=data+i;
return best;
}
