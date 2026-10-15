#pragma once
#include <string>
#include <cstddef>

struct IndexResult { bool found; std::size_t index; };
inline IndexResult first_unique(const std::string& text) {
unsigned counts[256]{};
for (char c:text) ++counts[static_cast<unsigned char>(c)];
for (std::size_t i=0;i<text.size();++i) if (counts[static_cast<unsigned char>(text[i])]==1) return {true,i};
return {false,0};
}
