#pragma once
#include <vector>

struct NumberResult { bool found; int value; };
inline NumberResult second_largest(const std::vector<int>& values) {
int first=0,second=0;
bool has_first=false,has_second=false;
for (int x : values) {
    if (!has_first || x>first) {
        if (has_first) { second=first;has_second=true; }
        first=x;has_first=true;
    } else if (x<first && (!has_second || x>second)) {
        second=x;has_second=true;
    }
}
return {has_second,has_second?second:0};
}
