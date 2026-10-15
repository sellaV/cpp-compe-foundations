#pragma once
#include <vector>
#include <cstddef>

inline bool search_range(const std::vector<int>& values,int target,std::size_t begin,std::size_t end) {
if (begin>=end) return false;
std::size_t middle=begin+(end-begin)/2;
if (values[middle]==target) return true;
if (values[middle]<target) return search_range(values,target,middle+1,end);
return search_range(values,target,begin,middle);
}
inline bool contains_recursive(const std::vector<int>& values,int target) {
return search_range(values,target,0,values.size());
}
