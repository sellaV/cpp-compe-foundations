#pragma once
#include <vector>
#include <cstddef>

inline void remove_duplicates(std::vector<int>& values) {
std::size_t written=0;
for (std::size_t read=0;read<values.size();++read) {
    bool seen=false;
    for (std::size_t i=0;i<written;++i) if (values[i]==values[read]) {seen=true;break;}
    if (!seen) values[written++]=values[read];
}
values.resize(written);
}
