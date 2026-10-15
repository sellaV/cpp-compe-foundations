#pragma once
#include <cstddef>

inline bool reverse_range(int* data,std::size_t n) {
if (n>0 && data==nullptr) return false;
for (std::size_t i=0;i<n/2;++i) {int temporary=data[i];data[i]=data[n-1-i];data[n-1-i]=temporary;}
return true;
}
