#pragma once


inline void rotate_values(int& a, int& b, int& c) {
    int old_c = c;
    c = b;
    b = a;
    a = old_c;
}
