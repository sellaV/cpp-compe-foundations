#pragma once
#include <vector>
#include <string>

// stdexcept only supports the unfinished TODO placeholder; remove it when solved.
#include <stdexcept>
class Inventory {
public:
    bool add(const std::string&,int) {throw std::logic_error("TODO");}
    bool remove(const std::string&,int) {throw std::logic_error("TODO");}
    int count(const std::string&) const {throw std::logic_error("TODO");}
};
