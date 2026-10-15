#pragma once

// stdexcept only supports the unfinished TODO placeholder; remove it when solved.
#include <stdexcept>
class FixedQueue {
public:
    bool push(int) {throw std::logic_error("TODO");}
    bool pop(int&) {throw std::logic_error("TODO");}
    int size() const {throw std::logic_error("TODO");}
};
