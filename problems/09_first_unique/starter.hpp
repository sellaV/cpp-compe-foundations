#pragma once
#include <string>
#include <cstddef>

// stdexcept only supports the unfinished TODO placeholder; remove it when solved.
#include <stdexcept>
struct IndexResult { bool found; std::size_t index; };
inline IndexResult first_unique(const std::string& text) {
    // TODO: implement the contract using core language features.
    throw std::logic_error("TODO");
}

